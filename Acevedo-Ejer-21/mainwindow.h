#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLineEdit;
class QLabel;
class Descargador;

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

private slots:
    void analizarYDescargar();
    void seleccionarDirectorio();

private:
    QLineEdit *urlInput;
    QLineEdit *directorioInput;
    QLabel *estadoLabel;
    QLabel *finalLabel;
    Descargador *descargador;
};

#endif // MAINWINDOW_H
