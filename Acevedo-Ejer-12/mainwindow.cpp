#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Ventana Principal");

    QLabel* mensaje = new QLabel("Bienvenido, admin.");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(mensaje);
    setLayout(layout);
}
