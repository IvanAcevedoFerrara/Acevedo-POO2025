#include "login.h"
#include <QGridLayout>

Login::Login() {
    setWindowTitle("Login");

    QLabel* lblUsuario = new QLabel("Usuario:");
    QLabel* lblClave = new QLabel("Clave:");

    leUsuario = new QLineEdit;
    leClave = new QLineEdit;

    // Configurar entrada de clave con asteriscos
    leClave->setEchoMode(QLineEdit::Password);

    btnAceptar = new QPushButton("Ingresar");

    // Layout de grilla
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(lblUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lblClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(btnAceptar, 2, 1);

    setLayout(layout);

    // Conectar boton a funcion de validacion
    connect(btnAceptar, SIGNAL(pressed()), this, SLOT(validarClave()));

    // Detectar enter desde campo de clave
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(validarClave()));
}

void Login::validarClave() {
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    // Validar usuario y clave
    if (usuario == "admin" && clave == "1111") {
        this->close(); // Cerrar login
        Formulario* f = new Formulario(); // Crear formulario
        f->show(); // Mostrar formulario
    } else {
        leClave->clear(); // Limpiar campo de clave
    }
}
