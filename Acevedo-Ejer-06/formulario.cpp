#include "formulario.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Formulario::Formulario() {
    setWindowTitle("Formulario");

    QLabel* lblLegajo = new QLabel("Legajo:");
    QLabel* lblNombre = new QLabel("Nombre:");
    QLabel* lblApellido = new QLabel("Apellido:");

    QLineEdit* leLegajo = new QLineEdit;
    QLineEdit* leNombre = new QLineEdit;
    QLineEdit* leApellido = new QLineEdit;

    QPushButton* btnEnviar = new QPushButton("Enviar");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(lblLegajo, 0, 0);
    layout->addWidget(leLegajo, 0, 1);
    layout->addWidget(lblNombre, 1, 0);
    layout->addWidget(leNombre, 1, 1);
    layout->addWidget(lblApellido, 2, 0);
    layout->addWidget(leApellido, 2, 1);
    layout->addWidget(btnEnviar, 3, 1);

    setLayout(layout);
}
