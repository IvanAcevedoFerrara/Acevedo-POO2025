#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Login ventanaLogin;
    ventanaLogin.show();

    return app.exec();
}
