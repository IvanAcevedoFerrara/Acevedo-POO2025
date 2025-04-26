#include "login.h"
#include "mainwindow.h"
#include <QGridLayout >
#include <QLabel>
#include <QPushButton>
#include <QUrl>
#include <QNetworkRequest>
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

    QGridLayout * layout = new QGridLayout ;
    layout->addWidget(lblUsuario);
    layout->addWidget(usuario);
    layout->addWidget(lblContrasena);
    layout->addWidget(contrasena);
    layout->addWidget(btnIngresar);
    layout->addWidget(errorLabel);
    layout->addWidget(temperaturaLabel);

    setLayout(layout);

    connect(btnIngresar, &QPushButton::clicked, this, &Login::validarLogin);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Login::procesarRespuesta);

    obtenerTemperatura();
}

void Login::obtenerTemperatura() {
    QString apiKey = "68fd0a13060549cc1e8d2427dec6bbcb";  // Usar key https://home.openweathermap.org/api_keys
    QString url = "https://api.openweathermap.org/data/2.5/weather?q=Cordoba,AR&units=metric&appid=" + apiKey;
    QUrl qurl(url);
    QNetworkRequest request(qurl);
    manager->get(request);
}

void Login::procesarRespuesta(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        temperaturaLabel->setText("Error al obtener temperatura");
        qDebug() << "Error:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QByteArray respuesta = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(respuesta);
    QJsonObject obj = doc.object();
    QJsonObject mainObj = obj["main"].toObject();
    double temperatura = mainObj["temp"].toDouble();

    temperaturaLabel->setText("Temperatura en Córdoba: " + QString::number(temperatura) + "°C");

    reply->deleteLater();
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
