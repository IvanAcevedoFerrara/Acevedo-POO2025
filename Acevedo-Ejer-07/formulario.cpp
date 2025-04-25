#include "formulario.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QRandomGenerator>

Formulario::Formulario() {
    setWindowTitle("Formulario");

    // Crear etiquetas para legajo, nombre y apellido
    QLabel* lblLegajo = new QLabel("Legajo:");
    QLabel* lblNombre = new QLabel("Nombre:");
    QLabel* lblApellido = new QLabel("Apellido:");

    // Crear campos de texto
    QLineEdit* leLegajo = new QLineEdit;
    QLineEdit* leNombre = new QLineEdit;
    QLineEdit* leApellido = new QLineEdit;

    // Grupo para captcha
    QGroupBox* grupoCaptcha = new QGroupBox("Verificacion Captcha");

    // Etiqueta y campo para captcha
    lblCaptcha = new QLabel;
    leCaptcha = new QLineEdit;

    // Layout para el captcha
    QGridLayout* layoutCaptcha = new QGridLayout;
    layoutCaptcha->addWidget(lblCaptcha, 0, 0);    // Mostrar captcha generado
    layoutCaptcha->addWidget(leCaptcha, 0, 1);      // Campo para ingresar captcha
    grupoCaptcha->setLayout(layoutCaptcha);

    // Boton para enviar formulario
    QPushButton* btnEnviar = new QPushButton("Enviar");

    // Layout general del formulario
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(lblLegajo, 0, 0);
    layout->addWidget(leLegajo, 0, 1);
    layout->addWidget(lblNombre, 1, 0);
    layout->addWidget(leNombre, 1, 1);
    layout->addWidget(lblApellido, 2, 0);
    layout->addWidget(leApellido, 2, 1);
    layout->addWidget(grupoCaptcha, 3, 0, 1, 2);  // Captcha ocupa dos columnas
    layout->addWidget(btnEnviar, 4, 1);           // Boton a la derecha

    setLayout(layout);

    // Generar el primer captcha aleatorio
    generarNuevoCaptcha();

    // Conectar el boton de enviar con la verificacion del captcha
    connect(btnEnviar, SIGNAL(clicked()), this, SLOT(verificarCaptcha()));
}

// Funcion que genera un nuevo captcha aleatorio
void Formulario::generarNuevoCaptcha() {
    QString caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    captchaGenerado = "";

    // Generar una cadena de 5 caracteres aleatorios
    for (int i = 0; i < 5; ++i) {
        int indice = QRandomGenerator::global()->bounded(caracteres.length());
        captchaGenerado += caracteres[indice];
    }

    // Actualizar la etiqueta con el nuevo captcha
    lblCaptcha->setText("Captcha: " + captchaGenerado);
}

// Verifica si el texto ingresado coincide con el captcha
void Formulario::verificarCaptcha() {
    QString ingreso = leCaptcha->text();

    if (ingreso == captchaGenerado) {
        this->close();  // Si es correcto, cerrar el formulario
    } else {
        leCaptcha->clear();       // Borrar campo si es incorrecto
        generarNuevoCaptcha();    // Generar uno nuevo
    }
}
