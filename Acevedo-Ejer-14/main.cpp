#include "pintura.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Pintura ventana;
    ventana.setWindowTitle("Dibujo a Mano Alzada");
    ventana.show();

    return app.exec();
}
