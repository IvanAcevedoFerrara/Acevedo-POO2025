#include "ventana.h"
#include "ui_ventana.h"
#include "boton.h"
#include <QPainter>
#include <QDebug>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana) {
    ui->setupUi(this);

    // Personalizar los botones promocionados
    QList<Boton *> botones = findChildren<Boton *>();
    botones[0]->colorear(Boton::Rojo);
    botones[1]->colorear(Boton::Magenta);
    botones[2]->colorear(Boton::Violeta);
    botones[3]->colorear(Boton::Azul);
    botones[4]->colorear(Boton::Verde);

    for (int i = 0; i < botones.size(); ++i) {
        connect(botones[i], &Boton::signal_clic, this, [i]() {
            qDebug() << "Botón" << i + 1 << "clicado";
        });
    }
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QImage fondo("C:/Escritorio/UBP/POO2025/Ejercios/Acevedo-Ejer-17/fondo.png");
    if (!fondo.isNull()) {
        painter.drawImage(rect(), fondo);
    }
    QWidget::paintEvent(event);
}

