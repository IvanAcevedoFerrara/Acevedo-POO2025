#include "juego.h"
#include <QPainter>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>

Juego::Juego(QWidget *parent) : QWidget(parent), velocidad(5), juegoTerminado(false) {
    srand(static_cast<unsigned int>(time(nullptr))); // Semilla para números aleatorios

    dinosaurio = new TRex(this);

    // Timer principal para actualizar el juego
    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &Juego::actualizarJuego);
    timerPrincipal->start(30); // Actualización cada 30 ms (33 FPS)

    // Generar pájaros cada 5 segundos
    QTimer *timerPajaros = new QTimer(this);
    connect(timerPajaros, &QTimer::timeout, this, &Juego::generarPajaro);
    timerPajaros->start(5000);

    // Generar cactus cada 3 segundos
    QTimer *timerCactus = new QTimer(this);
    connect(timerCactus, &QTimer::timeout, this, &Juego::generarCactus);
    timerCactus->start(3000);
}

void Juego::paintEvent(QPaintEvent *event) {
    (void)event; // Evitar el aviso de parámetro no utilizado
    QPainter painter(this);

    // Dibujar fondo
    painter.fillRect(rect(), Qt::white);

    // Dibujar dinosaurio
    dinosaurio->render(&painter);

    // Dibujar cactus
    for (Cactus *cactus : cactusLista) {
        cactus->render(&painter);
    }

    // Dibujar pájaros
    for (Pajaro *pajaro : pajaros) {
        pajaro->render(&painter);
    }

    // Mostrar "Game Over" si el juego terminó
    if (juegoTerminado) {
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 24));
        painter.drawText(rect(), Qt::AlignCenter, "Game Over! Presiona Espacio para reiniciar.");
    }
}

void Juego::keyPressEvent(QKeyEvent *event) {
    if (juegoTerminado) {
        if (event->key() == Qt::Key_Space) {
            reiniciarJuego();
        }
        return;
    }

    switch (event->key()) {
    case Qt::Key_Space:
        dinosaurio->saltar();
        break;
    case Qt::Key_Down:
        dinosaurio->agacharse();
        break;
    case Qt::Key_Right:
        dinosaurio->moverDerecha(); // Mover a la derecha
        break;
    case Qt::Key_Left:
        dinosaurio->moverIzquierda(); // Mover a la izquierda
        break;
    }
}

void Juego::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down) {
        dinosaurio->levantarse();
    }
}

void Juego::actualizarJuego() {
    if (juegoTerminado) return;

    // Mover cactus y pájaros
    for (Cactus *cactus : cactusLista) {
        cactus->mover(velocidad);
    }
    for (Pajaro *pajaro : pajaros) {
        pajaro->mover(velocidad);
    }

    detectarColisiones();
    update();
}

void Juego::generarPajaro() {
    Pajaro *pajaro = new Pajaro(this);
    pajaros.append(pajaro);
}

void Juego::generarCactus() {
    Cactus *cactus = new Cactus(this);
    cactusLista.append(cactus);
}

void Juego::detectarColisiones() {
    // Detectar colisiones entre el dinosaurio y los cactus
    for (Cactus *cactus : cactusLista) {
        QRect rectCactus(cactus->getX(), cactus->getY(), cactus->width(), cactus->height());
        QRect rectTRex(dinosaurio->getX(), dinosaurio->getY(), dinosaurio->width(), dinosaurio->height());
        if (rectCactus.intersects(rectTRex)) {
            juegoTerminado = true;
            timerPrincipal->stop(); // Detener el temporizador principal
            break; // No es necesario seguir verificando colisiones
        }
    }

    // Detectar colisiones entre el dinosaurio y los pájaros
    for (Pajaro *pajaro : pajaros) {
        QRect rectPajaro(pajaro->getX(), pajaro->getY(), pajaro->width(), pajaro->height());
        QRect rectTRex(dinosaurio->getX(), dinosaurio->getY(), dinosaurio->width(), dinosaurio->height());
        if (rectPajaro.intersects(rectTRex)) {
            juegoTerminado = true;
            timerPrincipal->stop(); // Detener el temporizador principal
            break; // No es necesario seguir verificando colisiones
        }
    }

    // Si el juego terminó, actualizar la interfaz para mostrar "Game Over".
    if (juegoTerminado) {
        update(); // Forzar que se vuelva a pintar la pantalla
    }
}

void Juego::reiniciarJuego() {
    // Reiniciar estado del juego
    juegoTerminado = false;
    velocidad = 5;
    timerPrincipal->start(30); // Reiniciar el temporizador principal

    // Eliminar todos los obstáculos existentes
    for (Cactus *cactus : cactusLista) delete cactus;
    cactusLista.clear();

    for (Pajaro *pajaro : pajaros) delete pajaro;
    pajaros.clear();

    // Reiniciar el estado del T-Rex
    dinosaurio->reset();

    update(); // Volver a dibujar la pantalla
}
