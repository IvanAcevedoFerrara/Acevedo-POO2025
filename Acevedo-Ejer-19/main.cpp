#include <QApplication>
#include "medicamentosapp.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MedicamentosApp ventana;
    ventana.setWindowTitle("Gestión de Medicamentos");
    ventana.show();

    return app.exec();
}
