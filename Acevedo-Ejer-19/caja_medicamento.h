#ifndef CAJA_MEDICAMENTO_H
#define CAJA_MEDICAMENTO_H

#include <QString>

class CajaMedicamento {
private:
    int id;
    float dosisTotales;

public:
    // Constructor para crear una nueva caja (sin ID)
    CajaMedicamento(float dosis);

    // Constructor para cargar una caja desde la base (con ID y dosis)
    CajaMedicamento(int id, float dosis);

    // Sobrecarga del operador +
    CajaMedicamento operator+(const CajaMedicamento &otra) const;

    // Sobrecarga del operador ==
    bool operator==(const CajaMedicamento &otra) const;

    // Método para obtener una representación en cadena
    QString toString() const;

    // Métodos getter
    int getId() const { return id; }
    float getDosis() const { return dosisTotales; }
};

#endif // CAJA_MEDICAMENTO_H
