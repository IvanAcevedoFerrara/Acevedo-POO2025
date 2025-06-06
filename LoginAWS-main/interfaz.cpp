#include "interfaz.h"
#include "ui_interfaz.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <QDir>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "grabaraudio.h"
#include "login.h"

Interfaz::Interfaz(QWidget *parent, const QString& usuarioActual)
    : QWidget(parent)
    , ui(new Ui::Interfaz)
    , usuario(usuarioActual)
    , panelUsuario(nullptr)
    , transcripcionesModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    setWindowTitle("Transcriptor de conversaciones");

    ui->listView->setModel(transcripcionesModel);
    connect(ui->listView, &QListView::clicked, this, &Interfaz::on_historialTranscripcion_clicked);

    // Panel de usuario: crear SOLO UNA VEZ
    panelUsuario = new QWidget(this, Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    panelUsuario->setWindowModality(Qt::WindowModal);
    panelUsuario->setWindowTitle("Usuario");
    panelUsuario->setFixedSize(250, 180);
    QVBoxLayout* layout = new QVBoxLayout(panelUsuario);

    QLabel* label = new QLabel("Sesión iniciada como:", panelUsuario);
    layout->addWidget(label);

    QLabel* userLabel = new QLabel(usuario, panelUsuario);
    userLabel->setStyleSheet("font-weight: bold; font-size: 18px;");
    layout->addWidget(userLabel);

    QPushButton* btnAtras = new QPushButton("Atrás", panelUsuario);
    layout->addWidget(btnAtras);

    QPushButton* logoutButton = new QPushButton("Cerrar sesión", panelUsuario);
    layout->addWidget(logoutButton);

    connect(btnAtras, &QPushButton::clicked, this, &Interfaz::on_usuarioAtras_clicked);
    connect(logoutButton, &QPushButton::clicked, this, &Interfaz::on_logoutButton_clicked);

    panelUsuario->setLayout(layout);
    panelUsuario->hide();


}

Interfaz::~Interfaz()
{
    if (panelUsuario) {
        panelUsuario->deleteLater();
    }
    delete ui;
}

void Interfaz::setUsuario(const QString& usuarioNuevo)
{
    usuario = usuarioNuevo;
}

void Interfaz::agregarAlHistorial(const QString& texto)
{
    if (texto.trimmed().isEmpty()) return;
    historialTranscripciones << texto;
    QStandardItem* item = new QStandardItem(texto.left(30) + (texto.length()>30 ? "..." : ""));
    transcripcionesModel->appendRow(item);
}

void Interfaz::on_historialTranscripcion_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;
    int row = index.row();
    if (row < 0 || row >= historialTranscripciones.size()) return;

    QString textoCompleto = historialTranscripciones[row];

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Acción sobre transcripción");
    msgBox.setText("¿Qué deseas hacer con esta transcripción?");
    msgBox.setInformativeText(textoCompleto.left(200) + (textoCompleto.size()>200 ? "..." : ""));

    QPushButton *btnEditar = msgBox.addButton("Editar", QMessageBox::AcceptRole);
    QPushButton *btnEliminar = msgBox.addButton("Eliminar", QMessageBox::DestructiveRole);
    QPushButton *btnAtras = msgBox.addButton("Atrás", QMessageBox::RejectRole);

    msgBox.setDefaultButton(btnAtras);
    msgBox.exec();

    if (msgBox.clickedButton() == btnEditar) {
        ui->transcriptionEdit->setPlainText(textoCompleto);
    } else if (msgBox.clickedButton() == btnEliminar) {
        historialTranscripciones.removeAt(row);
        transcripcionesModel->removeRow(row);
    }
    // Si es Atrás, no hace nada
}

void Interfaz::on_loadButton_clicked()
{
    QString archivo = QFileDialog::getOpenFileName(this, "Seleccionar archivo de audio", "", "Audio (*.wav *.mp3)");
    if (!archivo.isEmpty()) {
        QFileInfo info(archivo);
        QMessageBox::information(this, "Archivo subido", "Archivo (" + info.fileName() + ") subido con éxito");
        // Set color SOLO para botón de cargar audio, el de grabar vuelve a default
        ui->loadButton->setStyleSheet("background-color: #4CAF50; color: white;");
        ui->recordButton->setStyleSheet(""); // default

        this->rutaAudioCargado = archivo;

        // SIMULACIÓN DE TRANSCRIPCIÓN
        QString transcripcion = "Transcripción de " + info.fileName();
        ui->transcriptionEdit->setPlainText(transcripcion);
        // El usuario guarda manualmente si quiere, así que ya no se agrega automáticamente
    }
}

void Interfaz::on_recordButton_clicked()
{
    GrabarAudio *ventana = new GrabarAudio();
    connect(ventana, &GrabarAudio::audioGrabado, this, &Interfaz::audioGrabado);
    ventana->setAttribute(Qt::WA_DeleteOnClose);

    ventana->adjustSize();
    QRect geomPadre = this->geometry();
    QRect geomHijo = ventana->frameGeometry();
    int x = geomPadre.center().x() - geomHijo.width()/2;
    int y = geomPadre.center().y() - geomHijo.height()/2;
    ventana->move(x, y);

    ventana->show();
}

void Interfaz::audioGrabado(QString archivo)
{
    // Set color SOLO para botón de grabar, el de cargar vuelve a default
    ui->recordButton->setStyleSheet("background-color: #4CAF50; color: white;");
    ui->loadButton->setStyleSheet(""); // default

    this->rutaAudioCargado = archivo;

    // SIMULACIÓN DE TRANSCRIPCIÓN
    QString transcripcion = "Transcripción grabada de " + QFileInfo(archivo).fileName();
    ui->transcriptionEdit->setPlainText(transcripcion);
    // El usuario guarda manualmente si quiere, así que ya no se agrega automáticamente
}

void Interfaz::on_saveTranscriptionButton_clicked()
{
    QString texto = ui->transcriptionEdit->toPlainText().trimmed();
    if (!texto.isEmpty()) {
        agregarAlHistorial(texto);
        QMessageBox::information(this, "Transcripción", "Transcripción guardada en el historial.");
    } else {
        QMessageBox::warning(this, "Transcripción", "No hay transcripción para guardar.");
    }
}

void Interfaz::on_exportTxtButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar como TXT", "", "Archivo TXT (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->transcriptionEdit->toPlainText();
            file.close();
            QMessageBox::information(this, "Exportar", "Transcripción exportada a TXT.");
        }
    }
}

void Interfaz::on_exportWordButton_clicked()
{
    // Guardar como .doc (NO .docx) y escribir HTML
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar como Word", "", "Archivo Word (*.doc)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QString html = ui->transcriptionEdit->toPlainText().replace("\n", "<br>");
            QTextStream out(&file);
            out << "<html><body>" << html << "</body></html>";
            file.close();
            QMessageBox::information(this, "Exportar", "Transcripción exportada a Word (.doc). Si quieres .docx real, usa una suite ofimática para convertir.");
        }
    }
}

void Interfaz::on_exportPdfButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar como PDF", "", "Archivo PDF (*.pdf)");
    if (!fileName.isEmpty()) {
        QPdfWriter writer(fileName);
        writer.setPageMargins(QMarginsF(30, 30, 30, 30));
        QPainter painter(&writer);
        QRect rect(0, 0, writer.width(), writer.height());
        painter.drawText(rect, Qt::AlignLeft | Qt::TextWordWrap, ui->transcriptionEdit->toPlainText());
        painter.end();
        QMessageBox::information(this, "Exportar", "Transcripción exportada a PDF.");
    }
}

void Interfaz::on_toolButton_clicked()
{
    panelUsuario->show();
    panelUsuario->raise();
}

void Interfaz::on_usuarioAtras_clicked()
{
    if (panelUsuario) panelUsuario->hide();
}

void Interfaz::on_logoutButton_clicked()
{
    if (panelUsuario) panelUsuario->close();
    this->close();
    Login* ventanaLogin = new Login();
    ventanaLogin->show();
}
