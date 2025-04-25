#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void validarLogin();
    void obtenerTemperatura();
    void procesarRespuesta(QNetworkReply* reply);

private:
    QLineEdit* usuario;
    QLineEdit* contrasena;
    QLabel* temperaturaLabel;
    QLabel* errorLabel;

    QNetworkAccessManager* manager;
};

#endif // LOGIN_H
