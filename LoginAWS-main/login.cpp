#include "login.h"
#include "ui_login.h"
#include "adminapi.h"
#include "interfaz.h"
#include "registrar.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");

    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_LoginButton_clicked, Qt::UniqueConnection);
    connect(ui->signupButton, &QPushButton::clicked, this, &Login::on_SignUpButton_clicked, Qt::UniqueConnection);
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    QString usuario = ui->usernameEdit->text();
    QString contrasena = ui->passwordEdit->text();

    if (usuario.isEmpty() || contrasena.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, ingresa usuario y contraseña.");
        return;
    }

    ui->loginButton->setEnabled(false);

    if (replyActual) {
        disconnect(replyActual, nullptr, this, nullptr);
        replyActual->deleteLater();
    }
    replyActual = AdminAPI::getInstancia()->iniciarSesion(usuario, contrasena);
    connect(replyActual, &QNetworkReply::finished, this, &Login::onLoginReply, Qt::UniqueConnection);
}

void Login::onLoginReply()
{
    ui->loginButton->setEnabled(true);

    if (!replyActual)
        return;

    QByteArray respuesta = replyActual->readAll();

    if (replyActual->error() == QNetworkReply::NoError) {
        // Parsear respuesta JSON y obtener token
        QJsonDocument jsonDoc = QJsonDocument::fromJson(respuesta);
        QJsonObject obj = jsonDoc.object();
        QString token = obj.value("access_token").toString();

        if (!token.isEmpty()) {
            // Puedes guardar el token en algún singleton o pasarlo a la Interfaz
            QMessageBox::information(this, "Login exitoso", "¡Bienvenido!");

            Interfaz *ventanaInterfaz = new Interfaz(nullptr, token);
            ventanaInterfaz->show();
            this->close();
        } else {
            QMessageBox::warning(this, "Error de login", "Respuesta inesperada del servidor.");
        }
    } else {
        QMessageBox::warning(this, "Error de login", "Usuario o contraseña incorrectos.");
    }
    replyActual->deleteLater();
    replyActual = nullptr;
}

void Login::on_SignUpButton_clicked()
{
    Registrar *ventanaRegistrar = new Registrar();
    ventanaRegistrar->show();
    this->close();
}
