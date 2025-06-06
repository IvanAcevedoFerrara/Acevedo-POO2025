#include "grabaraudio.h"
#include "ui_grabaraudio.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QScreen>
#include <QApplication>

GrabarAudio::GrabarAudio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GrabarAudio),
    audioRecorder(new QMediaRecorder(this))
{
    ui->setupUi(this);

    // Fondo color gris oscuro
    this->setStyleSheet("background-color: #444444;");

    // Centrar ventana respecto a la principal si existe (método clásico)
    if (parent) {
        QRect parentRect = parent->geometry();
        move(parentRect.center() - rect().center());
    } else {
        QRect screen = QApplication::primaryScreen()->geometry();
        move(screen.center() - rect().center());
    }

    // Indicador inicial
    ui->lblEstado->setText("Listo para grabar");
    ui->lblEstado->setStyleSheet("color: lightgray; font-weight: bold;");

    // Prevención de doble señal
    disconnect(ui->btnIniciar, nullptr, nullptr, nullptr);
    disconnect(ui->btnPausar, nullptr, nullptr, nullptr);
    disconnect(ui->btnDetener, nullptr, nullptr, nullptr);
    disconnect(ui->btnCancelar, nullptr, nullptr, nullptr);
    disconnect(ui->btnGuardar, nullptr, nullptr, nullptr);

    connect(ui->btnIniciar, &QPushButton::clicked, this, &GrabarAudio::on_btnIniciar_clicked, Qt::UniqueConnection);
    connect(ui->btnPausar, &QPushButton::clicked, this, &GrabarAudio::on_btnPausar_clicked, Qt::UniqueConnection);
    connect(ui->btnDetener, &QPushButton::clicked, this, &GrabarAudio::on_btnDetener_clicked, Qt::UniqueConnection);
    connect(ui->btnCancelar, &QPushButton::clicked, this, &GrabarAudio::on_btnCancelar_clicked, Qt::UniqueConnection);
    connect(ui->btnGuardar, &QPushButton::clicked, this, &GrabarAudio::on_btnGuardar_clicked, Qt::UniqueConnection);

    grabando = false;
}

GrabarAudio::~GrabarAudio() { delete ui; }

void GrabarAudio::on_btnIniciar_clicked() {
    rutaArchivoTemporal = QDir::temp().filePath("grabacion_temp.wav");
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(rutaArchivoTemporal));
    audioRecorder->record();
    grabando = true;
    ui->lblEstado->setText("Grabando...");
    ui->lblEstado->setStyleSheet("color: red; font-weight: bold;");
}

void GrabarAudio::on_btnPausar_clicked()  {
    if (grabando) {
        audioRecorder->pause();
        ui->lblEstado->setText("Pausado");
        ui->lblEstado->setStyleSheet("color: orange; font-weight: bold;");
    }
}
void GrabarAudio::on_btnDetener_clicked() {
    if (grabando) {
        audioRecorder->stop();
        ui->lblEstado->setText("Detenido");
        ui->lblEstado->setStyleSheet("color: gray; font-weight: bold;");
    }
}

void GrabarAudio::on_btnCancelar_clicked() {
    if (grabando) audioRecorder->stop();
    QFile::remove(rutaArchivoTemporal);
    this->close();
}

void GrabarAudio::on_btnGuardar_clicked() {
    if (grabando) audioRecorder->stop();
    bool ok;
    QString nombre = QInputDialog::getText(this, "Guardar como", "Nombre del archivo:", QLineEdit::Normal, "grabacion", &ok);
    if (ok && !nombre.isEmpty()) {
        QString destino = QFileDialog::getSaveFileName(this, "Guardar archivo de audio", QDir::home().filePath(nombre + ".wav"), "WAV (*.wav)");
        if (!destino.isEmpty()) {
            QFile::remove(destino); // Por si ya existe
            QFile::rename(rutaArchivoTemporal, destino);
            QMessageBox::information(this, "Guardado", "Audio guardado con éxito");
            emit audioGrabado(destino);
            this->close();
        }
    }
}
