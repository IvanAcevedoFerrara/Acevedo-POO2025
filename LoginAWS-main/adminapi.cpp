#include "adminapi.h"
#include <QNetworkRequest>

AdminAPI* AdminAPI::instancia = nullptr;

AdminAPI::AdminAPI() {}

AdminAPI* AdminAPI::getInstancia() {
    if (!instancia) {
        instancia = new AdminAPI();
    }
    return instancia;
}

// === AUTENTICACIÓN ===
QNetworkReply* AdminAPI::iniciarSesion(const QString &usuario, const QString &contrasena) {
    QUrl url(urlBase + "/auth/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QUrlQuery params;
    params.addQueryItem("username", usuario);
    params.addQueryItem("password", contrasena);
    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply* AdminAPI::registrarUsuario(const QString &nombre, const QString &apellido, const QString &usuario,
                                          const QString &contrasena, const QString &correo) {
    QUrl url(urlBase + "/auth/registro");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QUrlQuery params;
    params.addQueryItem("nombre", nombre);
    params.addQueryItem("apellido", apellido);
    params.addQueryItem("usuario", usuario);
    params.addQueryItem("clave", contrasena);
    params.addQueryItem("mail", correo);
    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply* AdminAPI::cambiarContrasena(const QString &usuario, const QString &contrasenaActual, const QString &nuevaContrasena) {
    QUrl url(urlBase + "/auth/cambiar-clave");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QUrlQuery params;
    params.addQueryItem("usuario", usuario);
    params.addQueryItem("clave_actual", contrasenaActual);
    params.addQueryItem("nueva_clave", nuevaContrasena);
    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

// === HISTORIAL ===
QNetworkReply* AdminAPI::leerHistorial(const QString &token) {
    QUrl url(urlBase + "/auth/historial");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", token.toUtf8());
    return networkManager.get(request);
}

QNetworkReply* AdminAPI::agregarHistorial(const QString &nombreArchivo, const QString &transcripcion, const QString &token) {
    QUrl url(urlBase + "/auth/historial");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", token.toUtf8());
    QUrlQuery params;
    params.addQueryItem("nombre_archivo", nombreArchivo);
    params.addQueryItem("transcripcion", transcripcion);
    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply* AdminAPI::modificarHistorial(int historial_id, const QString &nombreArchivo, const QString &transcripcion, const QString &token) {
    QUrl url(urlBase + "/auth/historial/" + QString::number(historial_id));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", token.toUtf8());
    QUrlQuery params;
    params.addQueryItem("nombre_archivo", nombreArchivo);
    params.addQueryItem("transcripcion", transcripcion);
    return networkManager.put(request, params.query(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply* AdminAPI::borrarHistorial(int historial_id, const QString &token) {
    QUrl url(urlBase + "/auth/historial/" + QString::number(historial_id));
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", token.toUtf8());
    return networkManager.deleteResource(request);
}

// === OPENAI KEY ===
QNetworkReply* AdminAPI::obtenerOpenAIKey(const QString &token) {
    QUrl url(urlBase + "/auth/openai-key");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", token.toUtf8());
    return networkManager.get(request);
}
