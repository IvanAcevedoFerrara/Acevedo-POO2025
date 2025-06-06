#include "registrar.h"
#include "ui_registrar.h"
#include "adminapi.h"
#include "login.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>

Registrar::Registrar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registrar)
{
    ui->setupUi(this);
    setWindowTitle("Registro de Usuario");

    connect(ui->signupButton, &QPushButton::clicked, this, &Registrar::on_signupButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &Registrar::on_cancelButton_clicked);
}

Registrar::~Registrar()
{
    delete ui;
}

void Registrar::on_signupButton_clicked()
{
    QString nombre = ui->nameEdit->text();
    QString apellido = ui->surnameEdit->text();
    QString usuario = ui->usernameEdit->text();
    QString contrasena = ui->passwordEdit->text();
    QString correo = ui->mailEdit->text();

    if (nombre.isEmpty() || apellido.isEmpty() || usuario.isEmpty() || contrasena.isEmpty() || correo.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, completa todos los campos.");
        return;
    }

    ui->signupButton->setEnabled(false);

    if (replyActual) {
        disconnect(replyActual, nullptr, this, nullptr);
        replyActual->deleteLater();
    }
    replyActual = AdminAPI::getInstancia()->registrarUsuario(nombre, apellido, usuario, contrasena, correo);
    connect(replyActual, &QNetworkReply::finished, this, &Registrar::onRegisterReply);
}

void Registrar::onRegisterReply()
{
    ui->signupButton->setEnabled(true);

    if (!replyActual)
        return;

    QByteArray respuesta = replyActual->readAll();

    if (replyActual->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Registro exitoso", "¡Usuario registrado correctamente!");
        Login *ventanaLogin = new Login();
        ventanaLogin->show();
        this->close();
    } else {
        // Intentar sacar el mensaje de error de la respuesta
        QJsonDocument jsonDoc = QJsonDocument::fromJson(respuesta);
        QString msg = "No se pudo registrar el usuario.";
        if (!jsonDoc.isNull() && jsonDoc.isObject() && jsonDoc.object().contains("detail")) {
            msg = jsonDoc.object().value("detail").toVariant().toString();
        }
        QMessageBox::warning(this, "Error de registro", msg);
    }
    replyActual->deleteLater();
    replyActual = nullptr;
}

void Registrar::on_cancelButton_clicked()
{
    Login *ventanaLogin = new Login();
    ventanaLogin->show();
    this->close();
}
