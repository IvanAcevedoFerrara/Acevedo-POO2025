#include "admindb.h"
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QSqlError>
#include <QDebug>
#include <QFile>

AdminDB::AdminDB(QObject *parent) : QObject(parent) {
    usuarios = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite) {
    if (!QFile::exists(archivoSqlite)) {
        qDebug() << "Error: el archivo de la base de datos no existe en:" << archivoSqlite;
        return false;
    }

    usuarios.setDatabaseName(archivoSqlite);

    if (!usuarios.open()) {
        qDebug() << "Error al abrir la base de datos:" << usuarios.lastError().text();
        return false;
    }

    qDebug() << "Conexión a la base de datos exitosa.";
    return true;
}

QSqlDatabase AdminDB::getUsuarios() {
    return usuarios;
}

QStringList AdminDB::validarUsuario(QString tabla, QString usuario, QString clave) {
    QStringList datosPersonales;

    if (!usuarios.isOpen()) {
        qDebug() << "Error: la base de datos no está abierta.";
        return datosPersonales;
    }

    QSqlQuery query(usuarios);
    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();

    query.prepare("SELECT nombre, apellido FROM " + tabla + " WHERE usuario = :usuario AND clave = :claveMd5");
    query.bindValue(":usuario", usuario);
    query.bindValue(":claveMd5", claveMd5);

    if (!query.exec()) {
        qDebug() << "Error en la consulta:" << query.lastError().text();
        return datosPersonales;
    }

    while (query.next()) {
        datosPersonales << query.value("nombre").toString();
        datosPersonales << query.value("apellido").toString();
    }

    return datosPersonales;
}
