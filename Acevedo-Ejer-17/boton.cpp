#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) : QWidget(parent), colorActual(Qt::gray) {
    setFixedSize(450,100); // Tamaño por defecto
}

void Boton::colorear(Boton::Color color) {
    // Cambiar el color basado en la enumeración
    switch (color) {
    case Azul:
        colorActual = QColor("#0000FF"); // Azul
        break;
    case Verde:
        colorActual = QColor("#00FF00"); // Verde
        break;
    case Magenta:
        colorActual = QColor("#FF00FF"); // Magenta
        break;
    case Rojo:
        colorActual = QColor("#FF0000"); // Rojo
        break;
    case Violeta:
        colorActual = QColor("#800080"); //Violeta
        break;
    }
    update(); // Forzar redibujado
}

void Boton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), colorActual);
    painter.setPen(Qt::black);
    painter.drawRect(rect().adjusted(0, 0, -1, -1)); // Borde
    painter.drawText(rect(), Qt::AlignCenter, "Clic");
}


void Boton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit signal_clic(); // Emitir la señal al hacer clic
    }
    QWidget::mousePressEvent(event);
}
