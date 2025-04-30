#include "medicamentosapp.h"
#include "admindb.h"
#include "caja_medicamento.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery> // Asegúrate de incluir esta cabecera
#include <QSqlError> // Asegúrate de incluir esta cabecera para QSqlError

MedicamentosApp::MedicamentosApp(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    spinDosis = new QDoubleSpinBox();
    spinDosis->setRange(1, 1000);
    layout->addWidget(spinDosis);

    QPushButton *btnAgregar = new QPushButton("Agregar");
    layout->addWidget(btnAgregar);

    listaCajas = new QListWidget();
    listaCajas->setSelectionMode(QAbstractItemView::MultiSelection); // Permitir selección múltiple
    layout->addWidget(listaCajas);

    QPushButton *btnSumar = new QPushButton("Sumar");
    layout->addWidget(btnSumar);

    QPushButton *btnComparar = new QPushButton("Comparar");
    layout->addWidget(btnComparar);

    QPushButton *btnEliminar = new QPushButton("Eliminar"); // Botón para eliminar cajas
    layout->addWidget(btnEliminar);

    connect(btnAgregar, SIGNAL(clicked()), this, SLOT(agregarCaja()));
    connect(btnSumar, SIGNAL(clicked()), this, SLOT(sumarCajas()));
    connect(btnComparar, SIGNAL(clicked()), this, SLOT(compararCajas()));
    connect(btnEliminar, SIGNAL(clicked()), this, SLOT(eliminarCajas())); // Conectar el botón eliminar

    AdminDB::getInstancia()->conectar();
    cargarCajas();
}

void MedicamentosApp::agregarCaja() {
    float dosis = spinDosis->value();
    if (!AdminDB::getInstancia()->insertarCaja(dosis)) {
        QMessageBox::warning(this, "Error", "No se puede agregar, límite de 1000 dosis alcanzado.");
        return;
    }
    cargarCajas();
}

void MedicamentosApp::cargarCajas() {
    listaCajas->clear();
    auto cajas = AdminDB::getInstancia()->obtenerTodas();
    for (const auto &caja : cajas) {
        listaCajas->addItem(caja.toString());
    }
}

void MedicamentosApp::sumarCajas() {
    auto seleccionadas = listaCajas->selectedItems();
    if (seleccionadas.size() != 2) {
        QMessageBox::warning(this, "Error", "Debe seleccionar exactamente dos cajas.");
        return;
    }

    int index1 = listaCajas->row(seleccionadas[0]);
    int index2 = listaCajas->row(seleccionadas[1]);

    auto cajas = AdminDB::getInstancia()->obtenerTodas();
    CajaMedicamento nuevaCaja = cajas[index1] + cajas[index2];

    // Verificar si la suma de las dosis no excede el límite de 1000
    float totalDosis = AdminDB::getInstancia()->obtenerTotalDosis();
    float nuevaDosis = nuevaCaja.getDosis();
    if (totalDosis - cajas[index1].getDosis() - cajas[index2].getDosis() + nuevaDosis > 1000) {
        QMessageBox::warning(this, "Error", "La suma excede el límite máximo de 1000 dosis.");
        return;
    }


    // Eliminar las cajas originales de la base de datos
    QSqlQuery query;
    query.prepare("DELETE FROM cajas_medicamentos WHERE id = :id1 OR id = :id2");
    query.bindValue(":id1", cajas[index1].getId());
    query.bindValue(":id2", cajas[index2].getId());

    if (!query.exec()) {
        qDebug() << "Error al eliminar las cajas originales:" << query.lastError().text();
        return;
    }
    // Insertar la nueva caja en la base de datos
    if (!AdminDB::getInstancia()->insertarCaja(nuevaCaja.getDosis())) {
        QMessageBox::warning(this, "Error", "No se pudo insertar la nueva caja.");
        return;
    }

    // Recargar la lista de cajas después de eliminar y agregar
    cargarCajas();
}

void MedicamentosApp::compararCajas() {
    auto seleccionadas = listaCajas->selectedItems();
    if (seleccionadas.size() != 2) {
        QMessageBox::warning(this, "Error", "Debe seleccionar exactamente dos cajas para comparar.");
        return;
    }

    int index1 = listaCajas->row(seleccionadas[0]);
    int index2 = listaCajas->row(seleccionadas[1]);

    auto cajas = AdminDB::getInstancia()->obtenerTodas();
    if (cajas[index1] == cajas[index2]) {
        QMessageBox::information(this, "Comparación", "Las cajas seleccionadas tienen la misma cantidad de dosis.");
    } else {
        QMessageBox::information(this, "Comparación", "Las cajas seleccionadas tienen cantidades diferentes de dosis.");
    }
}

void MedicamentosApp::eliminarCajas() {
    auto seleccionadas = listaCajas->selectedItems();
    if (seleccionadas.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe seleccionar al menos una caja para eliminar.");
        return;
    }

    auto cajas = AdminDB::getInstancia()->obtenerTodas();
    for (auto *item : seleccionadas) {
        int index = listaCajas->row(item);
        int id = cajas[index].getId();

        QSqlQuery query; // Aquí usamos QSqlQuery
        query.prepare("DELETE FROM cajas_medicamentos WHERE id = :id");
        query.bindValue(":id", id);

        if (!query.exec()) {
            qDebug() << "Error al eliminar la caja:" << query.lastError().text();
        }
    }

    cargarCajas(); // Recargar la lista tras eliminar
}
