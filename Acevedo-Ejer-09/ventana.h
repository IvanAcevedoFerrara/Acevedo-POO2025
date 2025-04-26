#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QImage>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana();

protected:

    void paintEvent(QPaintEvent* );

private :
    QNetworkAccessManager manager;
    QImage image;

private slots:
    void slot_descargaFinalizada(QNetworkReply *reply);
};

#endif // VENTANA_H
