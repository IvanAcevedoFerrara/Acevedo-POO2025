#include "pintura.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), colorPincel(Qt::black), tamanoPincel(5), dibujando(false) {
    lienzo = QImage(size(), QImage::Format_ARGB32);
    lienzo.fill(Qt::white);
    setAttribute(Qt::WA_StaticContents);
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(event->rect(), lienzo, event->rect());
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dibujando = true;
        puntoAnterior = event->pos();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (dibujando && (event->buttons() & Qt::LeftButton)) {
        dibujarLinea(puntoAnterior, event->pos());
        puntoAnterior = event->pos();
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        tamanoPincel++;
    } else if (tamanoPincel > 1) {
        tamanoPincel--;
    }
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_R:
        colorPincel = Qt::red;
        break;
    case Qt::Key_G:
        colorPincel = Qt::green;
        break;
    case Qt::Key_B:
        colorPincel = Qt::blue;
        break;
    case Qt::Key_Escape:
        lienzo.fill(Qt::white);
        update();
        break;
    }
}

void Pintura::dibujarLinea(const QPoint &inicio, const QPoint &fin) {
    QPainter painter(&lienzo);
    painter.setPen(QPen(colorPincel, tamanoPincel, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(inicio, fin);
    update();
}
