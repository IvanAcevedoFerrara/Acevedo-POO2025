#include "login.h"
#include <QGridLayout>
#include <QDebug>
#include <QImageReader>

Login::Login(QWidget *parent) : QWidget(parent) {
    this->resize(400, 300);

    fondo = new QLabel(this);
    fondo->setScaledContents(true);
    fondo->setGeometry(this->rect());

    usuarioInput = new QLineEdit(this);
    claveInput = new QLineEdit(this);
    claveInput->setEchoMode(QLineEdit::Password);

    btnIngresar = new QPushButton("Ingresar", this);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(usuarioInput);
    layout->addWidget(claveInput);
    layout->addWidget(btnIngresar);

    layout->setAlignment(Qt::AlignCenter);

    QWidget *formWidget = new QWidget(this);
    formWidget->setLayout(layout);
    formWidget->setGeometry(100, 80, 200, 120);
    formWidget->raise();

    connect(btnIngresar, &QPushButton::clicked, this, &Login::validarUsuario);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Login::imagenFondoDescargada);

    // URL de imagen para fondo del login
    QUrl url("https://picsum.photos/600/400");
    manager->get(QNetworkRequest(url));
}

void Login::imagenFondoDescargada(QNetworkReply *reply) {
    QImage imagen;
    imagen.loadFromData(reply->readAll());

    // Mostrar imagen sin deformar
    QSize tamVentana = this->size();
    QImage escalada = imagen.scaled(tamVentana, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    fondo->setPixmap(QPixmap::fromImage(escalada));
}

void Login::validarUsuario() {
    QString usuario = usuarioInput->text();
    QString clave = claveInput->text();

    if (usuario == "admin" && clave == "1234") {
        this->hide();

        Ventana *ventana = new Ventana();
        ventana->showFullScreen();
    } else {
        qDebug() << "Usuario o clave incorrecta";
    }
}
