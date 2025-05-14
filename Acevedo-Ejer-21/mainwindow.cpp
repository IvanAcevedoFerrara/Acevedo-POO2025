#include "mainwindow.h"
#include "descargador.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>

Ventana::Ventana(QWidget *parent) : QWidget(parent), descargador(nullptr) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("URL del sitio web:", this));
    urlInput = new QLineEdit(this);
    urlInput->setPlaceholderText("https://ejemplo.com");
    layout->addWidget(urlInput);

    layout->addWidget(new QLabel("Carpeta de destino:", this));
    QHBoxLayout *dirLayout = new QHBoxLayout;
    directorioInput = new QLineEdit(this);
    directorioInput->setPlaceholderText("/ruta/a/carpeta");
    dirLayout->addWidget(directorioInput);
    QPushButton *selectDirBtn = new QPushButton("Seleccionar...", this);
    dirLayout->addWidget(selectDirBtn);
    layout->addLayout(dirLayout);

    QPushButton *descargarBtn = new QPushButton("Analizar y Descargar", this);
    layout->addWidget(descargarBtn);

    estadoLabel = new QLabel("Esperando acción...", this);
    layout->addWidget(estadoLabel);

    finalLabel = new QLabel("", this);
    layout->addWidget(finalLabel);

    connect(selectDirBtn, &QPushButton::clicked, this, &Ventana::seleccionarDirectorio);
    connect(descargarBtn, &QPushButton::clicked, this, &Ventana::analizarYDescargar);

    setLayout(layout);
    setWindowTitle("Descargador de recursos web");
    resize(600, 280);
}

void Ventana::seleccionarDirectorio() {
    QString directorio = QFileDialog::getExistingDirectory(this, "Seleccionar Directorio", ".");
    if (!directorio.isEmpty()) {
        directorioInput->setText(directorio);
    }
}

void Ventana::analizarYDescargar() {
    QString urlStr = urlInput->text().trimmed();
    QString directorio = directorioInput->text().trimmed();

    finalLabel->clear();

    if (urlStr.isEmpty()) {
        estadoLabel->setText("Error: Debe ingresar una URL.");
        return;
    }
    if (directorio.isEmpty()) {
        estadoLabel->setText("Error: Debe ingresar o seleccionar una carpeta de destino.");
        return;
    }

    if (descargador) {
        descargador->deleteLater();
        descargador = nullptr;
    }

    descargador = new Descargador(urlStr, directorio, this);
    connect(descargador, &Descargador::mensaje, this, [this](const QString &msg) {
        estadoLabel->setText(msg);
    });
    connect(descargador, &Descargador::descargaCompleta, this, [this]() {
        finalLabel->setText("¡Descarga completa!");
        estadoLabel->setText("Listo.");
    });

    descargador->iniciar();
}
