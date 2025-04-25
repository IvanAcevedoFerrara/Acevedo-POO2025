#include "ventana.h"
#include <QImageReader>
#include <QDebug>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    fondo = new QLabel(this);
    fondo->setScaledContents(true);
    fondo->setGeometry(this->rect());

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Ventana::imagenDescargada);

    // URL de imagen para la ventana principal
    QUrl url("https://picsum.photos/1200/800");
    manager->get(QNetworkRequest(url));
}

void Ventana::imagenDescargada(QNetworkReply *reply) {
    QImage imagen;
    imagen.loadFromData(reply->readAll());

    QSize tamVentana = this->size();
    QImage escalada = imagen.scaled(tamVentana, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    fondo->setPixmap(QPixmap::fromImage(escalada));
}
