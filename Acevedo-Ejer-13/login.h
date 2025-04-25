#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "ventana.h"

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

private slots:
    void validarUsuario();
    void imagenFondoDescargada(QNetworkReply *reply);

private:
    QLineEdit *usuarioInput;
    QLineEdit *claveInput;
    QLabel *fondo;
    QPushButton *btnIngresar;
    QNetworkAccessManager *manager;
};

#endif // LOGIN_H
