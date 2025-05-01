#include "trex.h"
#include <QPainter>

TRex::TRex(QWidget *parent)
    : QWidget(parent), x(50), y(300), velocidadY(0), enElAire(false), agachado(false) {
    posicionInicial = y; // Guardamos la altura inicial

    // Configurar el timer para manejar el salto
    timerSalto = new QTimer(this);
    connect(timerSalto, &QTimer::timeout, this, &TRex::actualizarSalto);
}

void TRex::saltar() {
    if (!enElAire) {
        velocidadY = -15; // Velocidad inicial del salto
        enElAire = true;
        timerSalto->start(30); // Actualizar cada 30 ms
    }
}

void TRex::agacharse() {
    if (!enElAire && !agachado) {
        y += 20; // Mover hacia abajo
        agachado = true;
    }
}

void TRex::levantarse() {
    if (agachado) {
        y = posicionInicial; // Volver a la posición inicial
        agachado = false;
    }
}

void TRex::moverIzquierda() {
    x = std::max(0, x - 10); // Mover hacia la izquierda, asegurarse de no salir del límite izquierdo
}

void TRex::moverDerecha() {
    x = std::min(750, x + 10); // Mover hacia la derecha, asegurarse de no salir del límite derecho
}

void TRex::reset() {
    x = 50;              // Restablecer posición horizontal
    y = posicionInicial; // Restablecer posición vertical
    velocidadY = 0;      // Detener cualquier movimiento vertical
    enElAire = false;    // Asegurar que no esté en el aire
    agachado = false;    // Asegurar que no esté agachado
    timerSalto->stop();  // Detener el timer del salto
}

void TRex::actualizarSalto() {
    if (enElAire) {
        y += velocidadY;     // Actualizar la posición vertical
        velocidadY += 1;     // Simular gravedad

        if (y >= posicionInicial) { // Si toca el suelo
            y = posicionInicial;
            enElAire = false;
            timerSalto->stop(); // Detener el salto
        }
    }
}

void TRex::render(QPainter *painter) {
    painter->setBrush(Qt::green);
    painter->drawRect(x, y, width(), height()); // Dibujar el T-Rex como un cuadrado
}

bool TRex::colisionaCon(QWidget *obstaculo) {
    return QRect(x, y, width(), height()).intersects(obstaculo->geometry());
}
