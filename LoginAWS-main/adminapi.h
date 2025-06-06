#ifndef ADMINAPI_H
#define ADMINAPI_H

#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>

class AdminAPI {
private:
    static AdminAPI *instancia;
    QNetworkAccessManager networkManager;
    const QString urlBase = "http://ec2-56-124-55-126.sa-east-1.compute.amazonaws.com:8000";
    AdminAPI();

public:
    static AdminAPI *getInstancia();

    // Login y registro
    QNetworkReply* iniciarSesion(const QString &usuario, const QString &contrasena);
    QNetworkReply* registrarUsuario(const QString &nombre, const QString &apellido, const QString &usuario, const QString &contrasena, const QString &correo);
    QNetworkReply* cambiarContrasena(const QString &usuario, const QString &contrasenaActual, const QString &nuevaContrasena);

    // === NUEVO ===
    // Historial: GET (leer), POST (agregar), PUT (modificar), DELETE (borrar)
    QNetworkReply* leerHistorial(const QString &token);
    QNetworkReply* agregarHistorial(const QString &nombreArchivo, const QString &transcripcion, const QString &token);
    QNetworkReply* modificarHistorial(int historial_id, const QString &nombreArchivo, const QString &transcripcion, const QString &token);
    QNetworkReply* borrarHistorial(int historial_id, const QString &token);

    // OpenAI Key
    QNetworkReply* obtenerOpenAIKey(const QString &token);
};

#endif // ADMINAPI_H
