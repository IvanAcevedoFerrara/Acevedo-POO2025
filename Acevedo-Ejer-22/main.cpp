#include <QCoreApplication>
#include <QElapsedTimer>
#include <QDebug>
#include <cstdlib> // Para rand()
#include <ctime>   // Para srand()

class Sensor {
private:
    int valorActual;

public:
    // Constructor que inicializa el valorActual con un valor aleatorio entre 0 y 1023.
    Sensor() : valorActual(rand() % 1024) {}

    // Método inline implícito para devolver el valor bruto.
    int getValorBruto() const {
        return valorActual;
    }

    // Método offline para devolver el valor bruto.
    int getValorBrutoOffline() const;

    // Método inline explícito para devolver el valor normalizado.
    inline double getValorNormalizado() const {
        return valorActual / 1023.0;
    }

    // Método offline para devolver el valor normalizado.
    double getValorNormalizadoOffline() const;
};

// Definición offline del método getValorBrutoOffline
int Sensor::getValorBrutoOffline() const {
    return valorActual;
}

// Definición offline del método getValorNormalizadoOffline
double Sensor::getValorNormalizadoOffline() const {
    return valorActual / 1023.0;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Inicializar la semilla para generar números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));

    Sensor sensor;

    // Benchmark para getValorBruto()
    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < 10000000; ++i) {
        sensor.getValorBruto();
    }
    qDebug() << "Tiempo para getValorBruto() (inline implícito):" << timer.elapsed() << "ms";

    // Benchmark para getValorBrutoOffline()
    timer.restart();
    for (int i = 0; i < 10000000; ++i) {
        sensor.getValorBrutoOffline();
    }
    qDebug() << "Tiempo para getValorBrutoOffline() (offline):" << timer.elapsed() << "ms";

    // Benchmark para getValorNormalizado()
    timer.restart();
    for (int i = 0; i < 10000000; ++i) {
        sensor.getValorNormalizado();
    }
    qDebug() << "Tiempo para getValorNormalizado() (inline explícito):" << timer.elapsed() << "ms";

    // Benchmark para getValorNormalizadoOffline()
    timer.restart();
    for (int i = 0; i < 10000000; ++i) {
        sensor.getValorNormalizadoOffline();
    }
    qDebug() << "Tiempo para getValorNormalizadoOffline() (offline):" << timer.elapsed() << "ms";

    return 0;
}
