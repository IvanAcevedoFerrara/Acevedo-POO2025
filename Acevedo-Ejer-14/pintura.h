#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QColor>
#include <QPoint>
#include <QImage>
#include <QPainter>

class Pintura : public QWidget {
    Q_OBJECT

public:
    explicit Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QImage lienzo;
    QColor colorPincel;
    int tamanoPincel;
    QPoint puntoAnterior;
    bool dibujando;

    void dibujarLinea(const QPoint &inicio, const QPoint &fin);
};

#endif // PINTURA_H
