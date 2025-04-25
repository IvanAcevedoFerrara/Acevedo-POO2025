#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void imagenDescargada(QNetworkReply *reply);

private:
    QLabel *fondo;
    QImage imagenOriginal;
    QNetworkAccessManager *manager;

    void redibujarFondo();
};

#endif // VENTANA_H
