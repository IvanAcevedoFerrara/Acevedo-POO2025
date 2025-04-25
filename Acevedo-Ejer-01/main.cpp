#include <iostream>   // Libreria para entrada y salida
#include <vector>     // Libreria para usar vector
#include <algorithm>  // Libreria para ordenar el vector

// Definicion de la clase Poste
class Poste {
private:
    int altura;     // Altura del poste en metros
    float diametro; // Diametro del poste en cm

public:
    // Constructor para inicializar los atributos
    Poste(int alt, float diam) : altura(alt), diametro(diam) {}

    // Metodo para obtener la altura (usado en la ordenacion)
    int getAltura() const { return altura; }

    // Metodo para mostrar los datos del poste
    void mostrar() const {
        std::cout << "Altura: " << altura << " m, Diametro: " << diametro << " cm" << std::endl;
    }
};

// Funcion principal
int main() {
    // Vector para almacenar los postes
    std::vector<Poste> postes;

    // Cargar 5 postes con diferentes alturas y diametros
    postes.push_back(Poste(8, 12.5));
    postes.push_back(Poste(5, 10.0));
    postes.push_back(Poste(12, 15.3));
    postes.push_back(Poste(7, 11.2));
    postes.push_back(Poste(6, 9.8));

    // Mostrar postes antes de ordenar
    std::cout << "Lista de postes antes de ordenar:" << std::endl;
    for (const Poste& p : postes) {
        p.mostrar();
    }

    // Ordenar los postes por altura (de menor a mayor)
    std::sort(postes.begin(), postes.end(), [](const Poste& a, const Poste& b) {
        return a.getAltura() < b.getAltura();
    });

    // Mostrar postes despues de ordenar
    std::cout << "\nLista de postes despues de ordenar:" << std::endl;
    for (const Poste& p : postes) {
        p.mostrar();
    }

    return 0;
}
