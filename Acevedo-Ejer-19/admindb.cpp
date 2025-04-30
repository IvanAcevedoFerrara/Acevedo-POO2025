#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

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
    db.setDatabaseName("medicamentos.db");

    if (!db.open()) {
        qDebug() << "Error al conectar con la base de datos:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS cajas_medicamentos ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "dosis_totales REAL NOT NULL)");
}

bool AdminDB::insertarCaja(float dosis) {
    float total = obtenerTotalDosis();
    if (total + dosis > 1000) {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO cajas_medicamentos (dosis_totales) VALUES (:dosis)");
    query.bindValue(":dosis", dosis);

    if (!query.exec()) {
        qDebug() << "Error al insertar caja:" << query.lastError().text();
        return false;
    }

    return true;
}

QList<CajaMedicamento> AdminDB::obtenerTodas() {
    QList<CajaMedicamento> lista;
    QSqlQuery query("SELECT id, dosis_totales FROM cajas_medicamentos");

    while (query.next()) {
        int id = query.value(0).toInt();
        float dosis = query.value(1).toFloat();
        lista.append(CajaMedicamento(id, dosis));
    }

    return lista;
}

float AdminDB::obtenerTotalDosis() {
    QSqlQuery query("SELECT SUM(dosis_totales) FROM cajas_medicamentos");
    if (query.next()) {
        return query.value(0).toFloat();
    }
    return 0;
}
