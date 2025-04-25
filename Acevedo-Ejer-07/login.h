#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "formulario.h"

class Login : public QWidget {
    Q_OBJECT

public:
    Login();

private slots:
    void validarClave();

private:
    QLineEdit* leUsuario;
    QLineEdit* leClave;
    QPushButton* btnAceptar;
};

#endif // LOGIN_H
