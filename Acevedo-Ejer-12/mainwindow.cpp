#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana Principal");

    QLabel* mensaje = new QLabel("Bienvenido, admin.");
    QGridLayout * layout = new QGridLayout ;
    layout->addWidget(mensaje);
    setLayout(layout);
}
