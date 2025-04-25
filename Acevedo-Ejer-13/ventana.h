#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

private slots:
    void imagenDescargada(QNetworkReply *reply);

private:
    QLabel *fondo;
    QNetworkAccessManager *manager;
};

#endif // VENTANA_H
