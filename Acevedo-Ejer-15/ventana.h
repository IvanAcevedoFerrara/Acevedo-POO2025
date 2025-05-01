#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(const QString &nombre, const QString &ultimoIngreso, QWidget *parent = nullptr);

private:
    void setupUI(const QString &nombre, const QString &ultimoIngreso);
};

#endif // VENTANA_H
