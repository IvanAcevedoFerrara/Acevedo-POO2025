#ifndef PAJARO_H
#define PAJARO_H

#include <QWidget>

class Pajaro : public QWidget {
    Q_OBJECT

public:
    explicit Pajaro(QWidget *parent = nullptr);

    // Métodos getter para acceder a los atributos privados
    int getX() const { return x; }
    int getY() const { return y; }
    int width() const { return 20; }   // Ancho del pájaro
    int height() const { return 20; } // Alto del pájaro

    void mover(int velocidad); // Mover el pájaro
    void render(QPainter *painter); // Dibujar el pájaro

private:
    int x, y; // Posición del pájaro
};

#endif // PAJARO_H
