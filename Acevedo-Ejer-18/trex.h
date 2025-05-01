#ifndef TREX_H
#define TREX_H

#include <QWidget>
#include <QTimer>

class TRex : public QWidget {
    Q_OBJECT

public:
    explicit TRex(QWidget *parent = nullptr);

    void saltar();         // Realizar el salto
    void agacharse();      // Agacharse
    void levantarse();     // Volver a la posición inicial tras agacharse
    void moverIzquierda(); // Mover hacia la izquierda
    void moverDerecha();   // Mover hacia la derecha
    void reset();          // Restablecer el estado inicial
    void render(QPainter *painter); // Dibujar el T-Rex
    bool colisionaCon(QWidget *obstaculo); // Detectar colisión con obstáculos

    // Métodos para obtener la posición
    int getX() const { return x; }
    int getY() const { return y; }
    int width() const { return 30; }
    int height() const { return 30; }

private slots:
    void actualizarSalto(); // Actualizar la posición durante el salto

private:
    int x, y;          // Posición del T-Rex
    int velocidadY;    // Velocidad vertical para el salto
    bool enElAire;     // Indica si el T-Rex está en el aire
    bool agachado;     // Indica si el T-Rex está agachado
    int posicionInicial; // Altura inicial del T-Rex
    QTimer *timerSalto; // Timer para manejar el salto
};

#endif // TREX_H
