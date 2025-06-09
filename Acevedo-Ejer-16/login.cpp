#include "login.h"
#include "ui_login.h"
#include <QSettings>
#include <QMessageBox>
#include <QDebug>

#define ORGANIZATION "MiAplicacion"
#define APPLICATION "LoginApp"

Login::Login(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Login),
    admindb(new AdminDB(this))
{
    ui->setupUi(this);

    // Ruta real de la base de datos
    QString rutaBD = "C:/Escritorio/UBP/POO2025/Ejercios/Acevedo-Ejer-16/usuarios.sqlite";

    if (!admindb->conectar(rutaBD)) {
        QMessageBox::critical(this, "Error", "No se pudo conectar a la base de datos.");
        return;
    }

    // Leer último usuario logueado
    QSettings settings(ORGANIZATION, APPLICATION);
    ui->leUsuario->setText(settings.value("ultimoUsuario", "").toString());

    // Conectar botón
    connect(ui->pushButton, &QPushButton::clicked, this, &Login::slot_validarUsuario);
}

Login::~Login() {
    delete ui;
}

void Login::slot_validarUsuario() {
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();

    if (usuario.isEmpty() || clave.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, ingresa usuario y contraseña.");
        return;
    }

    QStringList nombre_apellido = admindb->validarUsuario("usuarios", usuario, clave);

    if (!nombre_apellido.isEmpty()) {
        QMessageBox::information(this, "Login Exitoso", "Bienvenido " + nombre_apellido.join(" "));

        // Guardar usuario en QSettings
        QSettings settings(ORGANIZATION, APPLICATION);
        settings.setValue("ultimoUsuario", usuario);
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrecta.");
    }
}
