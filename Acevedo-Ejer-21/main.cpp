#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Ventana ventana;
    ventana.show();
    return app.exec();
}
