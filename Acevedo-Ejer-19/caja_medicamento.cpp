#include "caja_medicamento.h"

CajaMedicamento::CajaMedicamento(float dosis) : id(0), dosisTotales(dosis) {}

CajaMedicamento::CajaMedicamento(int id, float dosis) : id(id), dosisTotales(dosis) {}

CajaMedicamento CajaMedicamento::operator+(const CajaMedicamento &otra) const {
    return CajaMedicamento(this->dosisTotales + otra.dosisTotales);
}

bool CajaMedicamento::operator==(const CajaMedicamento &otra) const {
    return this->dosisTotales == otra.dosisTotales;
}

QString CajaMedicamento::toString() const {
    return QString("CajaMedicamento [ID: %1, Dosis: %2]").arg(id).arg(dosisTotales);
}
