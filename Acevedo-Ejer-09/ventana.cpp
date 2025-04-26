#include "ventana.h"
#include <QPainter>
#include <QUrl>
#include <QNetworkRequest>

Ventana::Ventana() {

connect(&manager, SIGNAL( finished( QNetworkReply * ) ), this, SLOT( slot_descargaFinalizada( QNetworkReply * ) ) );

    QNetworkRequest req(QUrl("https://www.ubp.edu.ar/wp-content/uploads/2021/08/UBP.png"));
    manager.get(req);
}

void Ventana::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawImage(0,0, this->image.scaled(this->width(),this->height()));
}

void Ventana::slot_descargaFinalizada(QNetworkReply *reply)
{
    this->image = QImage::fromData(reply->readAll());
    this->repaint();
}
