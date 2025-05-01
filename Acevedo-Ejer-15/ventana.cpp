#include "ventana.h"
#include <QVBoxLayout>
#include <QLabel>

Ventana::Ventana(const QString &nombre, const QString &ultimoIngreso, QWidget *parent)
    : QWidget(parent) {
    setupUI(nombre, ultimoIngreso);
}

void Ventana::setupUI(const QString &nombre, const QString &ultimoIngreso) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Nombre del usuario en grande
    QLabel *lblNombre = new QLabel(nombre, this);
    lblNombre->setAlignment(Qt::AlignCenter);
    lblNombre->setStyleSheet("font-size: 24px; font-weight: bold;");
    layout->addWidget(lblNombre);

    // Último ingreso en un texto más pequeño
    QLabel *lblUltimoIngreso = new QLabel("Último ingreso: " + ultimoIngreso, this);
    lblUltimoIngreso->setAlignment(Qt::AlignCenter);
    lblUltimoIngreso->setStyleSheet("font-size: 14px;");
    layout->addWidget(lblUltimoIngreso);

    setLayout(layout);
    setWindowTitle("Ventana Principal");
    resize(400, 200);
}
