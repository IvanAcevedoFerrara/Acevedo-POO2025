#ifndef DESCARGADOR_H
#define DESCARGADOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QSet>

class Descargador : public QObject {
    Q_OBJECT

public:
    Descargador(const QString &urlStr, const QString &directorio, QObject *parent = nullptr);
    void iniciar();

signals:
    void mensaje(const QString &msg);
    void descargaCompleta();

private slots:
    void htmlDescargado(QNetworkReply *reply);
    void recursoDescargado(QNetworkReply *reply);

private:
    void extraerRecursosYDescargar(const QString &html);
    void descargarRecurso(const QUrl &urlRecurso);

    QUrl urlBase;
    QString carpetaDestino;
    QNetworkAccessManager *manager;
    QSet<QString> descargados;
    int recursosPendientes;
};

#endif // DESCARGADOR_H
