#include <QApplication>
#include "juego.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear y mostrar la ventana principal del juego
    Juego juego;
    juego.setWindowTitle("T-Rex Extremo");
    juego.resize(800, 400); // Tamaño inicial de la ventana
    juego.show();

    return app.exec();
}
