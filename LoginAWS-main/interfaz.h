#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = nullptr, const QString& usuarioActual = "");
    ~Interfaz();

    void setUsuario(const QString& usuarioNuevo);

private slots:
    void on_loadButton_clicked();
    void on_recordButton_clicked();
    void on_exportTxtButton_clicked();
    void on_exportWordButton_clicked();
    void on_exportPdfButton_clicked();
    void on_toolButton_clicked();
    void on_logoutButton_clicked();
    void on_usuarioAtras_clicked();
    void audioGrabado(QString archivo);
    void on_historialTranscripcion_clicked(const QModelIndex &index);
    void on_saveTranscriptionButton_clicked();

private:
    void agregarAlHistorial(const QString& texto);

    Ui::Interfaz *ui;
    QString usuario;
    QString rutaAudioCargado;
    QWidget* panelUsuario;
    QStandardItemModel* transcripcionesModel;
    QList<QString> historialTranscripciones;
};

#endif // INTERFAZ_H
