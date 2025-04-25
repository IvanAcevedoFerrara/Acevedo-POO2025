#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear y mostrar ventana de login
    Login ventanaLogin;
    ventanaLogin.show();

    return app.exec();
}
