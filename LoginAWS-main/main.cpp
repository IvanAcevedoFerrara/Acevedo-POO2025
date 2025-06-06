#include <QApplication>
#include <QFile>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Aplica el estilo global desde style.qss
    QFile styleFile("C:/Escritorio/UBP/POO2025/AWS/login/LoginAWS-main/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    }

    // Muestra primero el login
    Login loginWindow;
    loginWindow.show();

    return a.exec();
}
