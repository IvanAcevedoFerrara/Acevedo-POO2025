#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QScreen>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Crear objeto QLabel
    QLabel* etiqueta = new QLabel;

    // Cargar imagen desde disco
    QPixmap imagen("C:/Escritorio/UBP/POO2025/Acevedo-Ejer-05/paisaje.jpeg"); // Ruta completa de la imagen

    // Verificar si la imagen se cargó correctamente
    if (imagen.isNull()) {
        qWarning("No se pudo cargar la imagen.");
        return -1;
    }

    // Obtener el tamaño de la pantalla
    QScreen* screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();

    // Ajustar la imagen al tamaño de la pantalla sin deformarla
    etiqueta->setPixmap(imagen.scaled(screenSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Mostrar la etiqueta en pantalla completa
    etiqueta->showMaximized();

    // Cerrar la aplicación luego de 3 segundos
    QTimer::singleShot(3000, &app, SLOT(quit()));

    return app.exec();
}
