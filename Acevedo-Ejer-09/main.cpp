#include "ventana.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Ventana ventana;
    ventana.setWindowTitle("Mi Primer QT Network");
    ventana.resize(800, 600);
    ventana.show();

    return app.exec();
}
