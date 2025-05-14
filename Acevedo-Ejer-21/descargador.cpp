#include "descargador.h"
#include <QNetworkReply>
#include <QFile>
#include <QDir>
#include <QRegularExpression>
#include <QFileInfo>
#include <QSslConfiguration>
#include <QDebug>

Descargador::Descargador(const QString &urlStr, const QString &directorio, QObject *parent)
    : QObject(parent), recursosPendientes(0) {
    QString fixedUrl = urlStr.trimmed();
    if (!fixedUrl.startsWith("http://") && !fixedUrl.startsWith("https://")) {
        fixedUrl = "https://" + fixedUrl;
    }
    urlBase = QUrl(fixedUrl);
    carpetaDestino = directorio;
    manager = new QNetworkAccessManager(this);
}

void Descargador::iniciar() {
    emit mensaje("Descargando HTML para analizar recursos...");
    QNetworkRequest request(urlBase);
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfig.setProtocol(QSsl::AnyProtocol);
    request.setSslConfiguration(sslConfig);

    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() { htmlDescargado(reply); });
}

void Descargador::htmlDescargado(QNetworkReply *reply) {
    QByteArray datos = reply->readAll();
    reply->deleteLater();

    if (datos.isEmpty()) {
        emit mensaje("No se pudo obtener el HTML.");
        emit descargaCompleta();
        return;
    }

    QString html = QString::fromUtf8(datos);
    emit mensaje("Analizando HTML...");
    extraerRecursosYDescargar(html);

    if (recursosPendientes == 0) {
        emit mensaje("No se encontraron recursos para descargar.");
        emit descargaCompleta();
    }
}

void Descargador::extraerRecursosYDescargar(const QString &html) {
    // Buscar src/href de imágenes, CSS, JS, fuentes, SVG, etc.
    QRegularExpression regex(R"((?:src|href)\s*=\s*["']([^"']+\.(?:css|js|png|jpg|jpeg|gif|webp|svg|ico|woff2?|ttf|eot|otf))["'])", QRegularExpression::CaseInsensitiveOption);
    auto it = regex.globalMatch(html);
    while (it.hasNext()) {
        auto match = it.next();
        QString recursoStr = match.captured(1).trimmed();

        if (recursoStr.startsWith("#") ||
            recursoStr.startsWith("mailto:") ||
            recursoStr.startsWith("javascript:") ||
            recursoStr.startsWith("data:")) continue;

        QUrl recursoUrl = urlBase.resolved(QUrl(recursoStr));
        QString recursoKey = recursoUrl.toString(QUrl::RemoveFragment);

        if (!recursoUrl.isValid() || descargados.contains(recursoKey))
            continue;

        descargados.insert(recursoKey);
        descargarRecurso(recursoUrl);
    }
}

void Descargador::descargarRecurso(const QUrl &urlRecurso) {
    emit mensaje("Descargando recurso: " + urlRecurso.toString());
    QNetworkRequest request(urlRecurso);
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfig.setProtocol(QSsl::AnyProtocol);
    request.setSslConfiguration(sslConfig);

    QNetworkReply* reply = manager->get(request);
    recursosPendientes++;
    connect(reply, &QNetworkReply::finished, this, [this, reply]() { this->recursoDescargado(reply); });
}

void Descargador::recursoDescargado(QNetworkReply *reply) {
    QUrl url = reply->url();
    QByteArray datos = reply->readAll();
    reply->deleteLater();

    QString pathRel = url.path();
    if (pathRel.isEmpty() || pathRel.endsWith('/')) {
        pathRel += "index.bin";
    }
    QString rutaLocal = carpetaDestino + QDir::separator() + pathRel;
    QDir().mkpath(QFileInfo(rutaLocal).absolutePath());

    QFile archivo(rutaLocal);
    if (archivo.open(QIODevice::WriteOnly)) {
        archivo.write(datos);
        archivo.close();
        emit mensaje("Guardado: " + rutaLocal);
    } else {
        emit mensaje("Error al guardar: " + rutaLocal);
    }

    recursosPendientes--;
    if (recursosPendientes <= 0) {
        emit descargaCompleta();
    }
}
