#include "transcripcion.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

Transcripcion::Transcripcion(const QString &token, QWidget *parent)
    : QWidget(parent), m_token(token)
{}

void Transcripcion::enviarAudio(const QString &rutaAudio)
{
    QUrl url("http://TU_API_URL/transcribir"); // Cambia por tu endpoint real
    QNetworkRequest request(url);

    QString authHeader = "Bearer " + m_token;
    request.setRawHeader("Authorization", authHeader.toUtf8());

    QFile *file = new QFile(rutaAudio);
    if (!file->open(QIODevice::ReadOnly)) {
        emit textoTranscripto("Error: no se pudo abrir el archivo de audio.");
        delete file;
        return;
    }

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart audioPart;
    audioPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"audio\"; filename=\"audio.wav\""));
    audioPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("audio/wav"));
    audioPart.setBodyDevice(file);
    file->setParent(multiPart);

    multiPart->append(audioPart);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->post(request, multiPart);
    multiPart->setParent(reply);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray respuesta = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(respuesta);
            QString texto = doc.object().value("texto").toString();
            emit textoTranscripto(texto);
        } else {
            emit textoTranscripto("No se pudo transcribir el audio: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
