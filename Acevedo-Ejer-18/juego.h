#ifndef JUEGO_H
#define JUEGO_H

#include <QWidget>
#include <QTimer>
#include "trex.h"
#include "pajaro.h"
#include "cactus.h"

class Juego : public QWidget {
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void actualizarJuego();
    void generarPajaro();
    void generarCactus();

private:
    TRex *dinosaurio;
    QList<Pajaro *> pajaros;
    QList<Cactus *> cactusLista;
    QTimer *timerPrincipal;
    int velocidad; // Velocidad del juego
    bool juegoTerminado;

    void detectarColisiones();
    void reiniciarJuego();
};

#endif // JUEGO_H
