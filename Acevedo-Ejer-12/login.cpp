#include "login.h"
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    QLabel* lblUsuario = new QLabel("Usuario:");
    QLabel* lblContrasena = new QLabel("Contrasena:");
    usuario = new QLineEdit;
    contrasena = new QLineEdit;
    contrasena->setEchoMode(QLineEdit::Password);

    QPushButton* btnIngresar = new QPushButton("Ingresar");
    errorLabel = new QLabel;
    errorLabel->setStyleSheet("color: red");

    temperaturaLabel = new QLabel("Cargando temperatura...");
    obtenerTemperatura();  // Simular API

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(lblUsuario);
    layout->addWidget(usuario);
    layout->addWidget(lblContrasena);
    layout->addWidget(contrasena);
    layout->addWidget(btnIngresar);
    layout->addWidget(errorLabel);
    layout->addWidget(temperaturaLabel);

    setLayout(layout);

    connect(btnIngresar, &QPushButton::clicked, this, &Login::validarLogin);
}

void Login::obtenerTemperatura() {
    // Simulamos obtener temperatura de una API
    QString ciudad = "Cordoba";
    int temperatura = 24 + (rand() % 5);  // Valor entre 24 y 28
    temperaturaLabel->setText("Temperatura en " + ciudad + ": " + QString::number(temperatura) + "°C");
}

void Login::validarLogin() {
    if (usuario->text() == "admin" && contrasena->text() == "1234") {
        this->close();
        MainWindow* ventana = new MainWindow;
        ventana->show();
    } else {
        errorLabel->setText("Usuario o contraseña incorrectos.");
    }
}
