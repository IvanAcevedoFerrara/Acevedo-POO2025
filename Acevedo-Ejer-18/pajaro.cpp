#include "pajaro.h"
#include <QPainter>
#include <cstdlib>

Pajaro::Pajaro(QWidget *parent) : QWidget(parent), x(800), y(rand() % 150 + 100) {
    // Inicializamos el pájaro en el borde derecho de la pantalla con una altura aleatoria
}

void Pajaro::mover(int velocidad) {
    x -= velocidad; // Mover el pájaro hacia la izquierda
}

void Pajaro::render(QPainter *painter) {
    painter->setBrush(Qt::blue);
    painter->drawEllipse(x, y, width(), height()); // Dibujar el pájaro como un círculo
}
