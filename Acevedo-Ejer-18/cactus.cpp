#include "cactus.h"
#include <QPainter>

Cactus::Cactus(QWidget *parent) : QWidget(parent), x(800), y(300) {
    // Inicializamos el cactus en el borde derecho de la pantalla
}

void Cactus::mover(int velocidad) {
    x -= velocidad; // Mover el cactus hacia la izquierda
}

void Cactus::render(QPainter *painter) {
    painter->setBrush(Qt::red);
    painter->drawRect(x, y, width(), height()); // Dibujar el cactus como un rectángulo
}
