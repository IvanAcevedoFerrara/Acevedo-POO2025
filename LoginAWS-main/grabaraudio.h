#ifndef GRABARAUDIO_H
#define GRABARAUDIO_H

#include <QWidget>
#include <QMediaRecorder>

namespace Ui {
class GrabarAudio;
}

class GrabarAudio : public QWidget
{
    Q_OBJECT

public:
    explicit GrabarAudio(QWidget *parent = nullptr);
    ~GrabarAudio();

signals:
    void audioGrabado(QString archivo);

private slots:
    void on_btnIniciar_clicked();
    void on_btnPausar_clicked();
    void on_btnDetener_clicked();
    void on_btnCancelar_clicked();
    void on_btnGuardar_clicked();

private:
    Ui::GrabarAudio *ui;
    QMediaRecorder *audioRecorder;
    QString rutaArchivoTemporal;
    bool grabando = false;
};

#endif // GRABARAUDIO_H
