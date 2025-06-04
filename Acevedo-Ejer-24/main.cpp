#include <QCoreApplication>
#include <QDebug>
#include <QString>

class Persona {
public:
    Persona(const QString& nombre) : nombre(nombre) {
        ++contador;
    }

    void mostrar() const {
        qDebug() << "Nombre:" << nombre;
    }

    static int totalPersonas() {
        return contador;
    }

private:
    QString nombre;
    static int contador;
};

// Definición e inicialización del miembro estático
int Persona::contador = 0;

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    Persona p1("Ana");
    Persona p2("Bruno");
    Persona p3("Carla");

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    qDebug() << "Total de personas creadas:" << Persona::totalPersonas();

    return 0;
}
