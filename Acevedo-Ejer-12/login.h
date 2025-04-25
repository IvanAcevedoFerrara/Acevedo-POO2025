#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void validarLogin();

private:
    QLineEdit* usuario;
    QLineEdit* contrasena;
    QLabel* temperaturaLabel;
    QLabel* errorLabel;

    void obtenerTemperatura();  // Simulada
};

#endif // LOGIN_H
