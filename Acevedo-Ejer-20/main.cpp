#include <iostream>
#include <vector>
#include <memory>

// Clase base Instrumento
class Instrumento {
protected:
    std::string marca;

public:
    Instrumento(std::string marca = "Yamaha") : marca(marca) {}
    virtual ~Instrumento() {}

    virtual void sonar() const = 0; // Función virtual pura
    virtual void verlo() const {
        std::cout << "Marca: " << marca << std::endl;
    }
};

// Clase derivada Guitarra
class Guitarra : public Instrumento {
private:
    int cuerdas;

public:
    Guitarra(int cuerdas = 6, std::string marca = "Yamaha") : Instrumento(marca), cuerdas(cuerdas) {}

    void sonar() const override {
        std::cout << "Guitarra suena..." << std::endl;
    }

    void verlo() const override {
        Instrumento::verlo();
        std::cout << "Cuerdas: " << cuerdas << std::endl;
    }
};

// Clase derivada Bateria
class Bateria : public Instrumento {
private:
    int tambores;

public:
    Bateria(int tambores = 5, std::string marca = "Yamaha") : Instrumento(marca), tambores(tambores) {}

    void sonar() const override {
        std::cout << "Batería suena..." << std::endl;
    }

    void verlo() const override {
        Instrumento::verlo();
        std::cout << "Tambores: " << tambores << std::endl;
    }
};

// Clase Electrico
class Electrico {
protected:
    int voltaje;

public:
    Electrico(int voltaje = 220) : voltaje(voltaje) {}
    virtual ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }

    void verVoltaje() const {
        std::cout << "Voltaje: " << voltaje << "V" << std::endl;
    }
};

// Clase derivada Teclado con herencia múltiple
class Teclado : public Instrumento, public Electrico {
private:
    int teclas;

public:
    Teclado(int teclas = 61, int voltaje = 220, std::string marca = "Yamaha")
        : Instrumento(marca), Electrico(voltaje), teclas(teclas) {}

    void sonar() const override {
        std::cout << "Teclado suena..." << std::endl;
    }

    void verlo() const override {
        Instrumento::verlo();
        std::cout << "Teclas: " << teclas << std::endl;
        verVoltaje();
    }
};

// Función principal
int main() {
    // Vector de punteros a Instrumento
    std::vector<std::unique_ptr<Instrumento>> instrumentos;

    // Crear objetos y agregarlos al vector
    instrumentos.push_back(std::make_unique<Guitarra>());
    instrumentos.push_back(std::make_unique<Bateria>());
    instrumentos.push_back(std::make_unique<Teclado>());
    instrumentos.push_back(std::make_unique<Guitarra>(12, "Fender"));
    instrumentos.push_back(std::make_unique<Bateria>(7, "Tama"));

    // Recorrer el vector y mostrar información de cada instrumento
    for (const auto &inst : instrumentos) {
        inst->verlo();
        inst->sonar();
        std::cout << "-------------------" << std::endl;
    }

    return 0;
}
