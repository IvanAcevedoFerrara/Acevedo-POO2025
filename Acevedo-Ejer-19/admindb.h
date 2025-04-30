#ifndef ADMINDB_H
#define ADMINDB_H

#include "caja_medicamento.h"
#include <QList>
#include <QSqlDatabase>

class AdminDB {
private:
    static AdminDB *instancia;
    QSqlDatabase db;

    AdminDB();

public:
    static AdminDB *getInstancia();

    void conectar();
    bool insertarCaja(float dosis);
    QList<CajaMedicamento> obtenerTodas();
    float obtenerTotalDosis();
};

#endif // ADMINDB_H
