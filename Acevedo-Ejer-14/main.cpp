#include "pintura.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Pintura ventana;
    ventana.setWindowTitle("Dibujo a Mano Alzada");
    ventana.resize(800, 600);
    ventana.show();

    return app.exec();
}
