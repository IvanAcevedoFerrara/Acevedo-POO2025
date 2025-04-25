#include <iostream>
#include <vector>
#include <algorithm>

// Funcion para eliminar los espacios de un string
std::string eliminarEspacios(const std::string& str) {
    std::string resultado;
    for (char c : str) {
        if (c != ' ') {
            resultado += c;
        }
    }
    return resultado;
}

int main() {
    // Vector con 5 expresiones idiomaticas
    std::vector<std::string> expresiones = {
        "pan comido",
        "a buen entendedor pocas palabras",
        "llover sobre mojado",
        "mas vale tarde que nunca",
        "estar en las nubes"
    };

    // Mostrar antes de ordenar
    std::cout << "Expresiones antes de ordenar:" << std::endl;
    for (const std::string& exp : expresiones) {
        std::cout << exp << std::endl;
    }

    // Ordenar ignorando espacios
    std::sort(expresiones.begin(), expresiones.end(), [](const std::string& a, const std::string& b) {
        return eliminarEspacios(a) < eliminarEspacios(b);
    });

    // Mostrar despues de ordenar
    std::cout << "\nExpresiones despues de ordenar:" << std::endl;
    for (const std::string& exp : expresiones) {
        std::cout << exp << std::endl;
    }

    return 0;
}
