#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

AdminDB *AdminDB::instancia = nullptr;

AdminDB::AdminDB() {}

AdminDB *AdminDB::getInstancia() {
    if (!instancia) {
        instancia = new AdminDB();
    }
    return instancia;
}

void AdminDB::conectar() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:"); // Base de datos en memoria. Cambiar por "usuarios.db" si deseas persistencia.

    if (!db.open()) {
        qDebug() << "Error al conectar con la base de datos:" << db.lastError().text();
        return;
    }

    // Crear la tabla "usuarios" si no existe
    QSqlQuery query;
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS usuarios (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nombre TEXT NOT NULL,
            password TEXT NOT NULL,
            ultimo_ingreso TEXT
        )
    )")) {
        qDebug() << "Error al crear la tabla 'usuarios':" << query.lastError().text();
    }

    // Insertar usuarios de prueba si la tabla está vacía
    if (!query.exec("SELECT COUNT(*) FROM usuarios") || !query.next() || query.value(0).toInt() == 0) {
        query.exec("INSERT INTO usuarios (nombre, password) VALUES ('admin', '1234')");
        query.exec("INSERT INTO usuarios (nombre, password) VALUES ('Juan', '12345')");
        query.exec("INSERT INTO usuarios (nombre, password) VALUES ('Maria', '5678')");
        query.exec("INSERT INTO usuarios (nombre, password) VALUES ('Carlos', 'abcd')");
        qDebug() << "Usuarios de prueba agregados a la base de datos.";
    }
}

bool AdminDB::validarUsuario(const QString &nombre, const QString &password, QString &ultimoIngreso) {
    QSqlQuery query;
    query.prepare("SELECT ultimo_ingreso FROM usuarios WHERE nombre = :nombre AND password = :password");
    query.bindValue(":nombre", nombre);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        ultimoIngreso = query.value(0).toString();
        return true;
    }
    return false;
}

void AdminDB::actualizarUltimoIngreso(const QString &nombre) {
    QSqlQuery query;
    query.prepare("UPDATE usuarios SET ultimo_ingreso = :fecha WHERE nombre = :nombre");
    query.bindValue(":fecha", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":nombre", nombre);

    if (!query.exec()) {
        qDebug() << "Error al actualizar el último ingreso:" << query.lastError().text();
    }
}
