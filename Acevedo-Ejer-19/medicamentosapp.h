#ifndef MEDICAMENTOSAPP_H
#define MEDICAMENTOSAPP_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QListWidget>

class MedicamentosApp : public QWidget {
    Q_OBJECT

private:
    QDoubleSpinBox *spinDosis;
    QListWidget *listaCajas;

public:
    explicit MedicamentosApp(QWidget *parent = nullptr);

private slots:
    void agregarCaja();
    void cargarCajas();
    void sumarCajas();
    void compararCajas();
    void eliminarCajas(); // Nuevo método para eliminar cajas
};

#endif // MEDICAMENTOSAPP_H
