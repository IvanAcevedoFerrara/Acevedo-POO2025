#include "ventana.h"
#include <QImageReader>
#include <QDebug>
#include <QResizeEvent>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    fondo = new QLabel(this);
    fondo->setScaledContents(true);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Ventana::imagenDescargada);

    // URL de imagen para la ventana principal
    QUrl url("https://picsum.photos/1920/1080");
    manager->get(QNetworkRequest(url));
}

void Ventana::imagenDescargada(QNetworkReply *reply) {
    imagenOriginal.loadFromData(reply->readAll());
    redibujarFondo();
    emit imagenLista(); // Notificamos que está lista la imagen
}


void Ventana::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    redibujarFondo(); // Redibuja fondo cuando cambia tamaño (p. ej., al hacer fullscreen)
}

void Ventana::redibujarFondo() {
    if (!imagenOriginal.isNull()) {
        QSize tamVentana = this->size();
        QImage escalada = imagenOriginal.scaled(tamVentana, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        fondo->setPixmap(QPixmap::fromImage(escalada));
        fondo->setGeometry(this->rect());
    }
}
