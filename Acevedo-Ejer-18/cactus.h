#ifndef CACTUS_H
#define CACTUS_H

#include <QWidget>

class Cactus : public QWidget {
    Q_OBJECT

public:
    explicit Cactus(QWidget *parent = nullptr);

    // Métodos getter para acceder a los atributos privados
    int getX() const { return x; }
    int getY() const { return y; }
    int width() const { return 20; }   // Ancho del cactus
    int height() const { return 40; } // Alto del cactus

    void mover(int velocidad); // Mover el cactus
    void render(QPainter *painter); // Dibujar el cactus

private:
    int x, y; // Posición del cactus
};

#endif // CACTUS_H
