#include <iostream>
#include <vector>

class Producto {
public:
    Producto(int id, const std::string& nombre, double precio)
        : id(id), nombre(nombre), precio(precio) {
    }

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }

private:
    int id;
    std::string nombre;
    double precio;
};

int main() {
    std::vector<Producto> productos;
    const size_t memoryLimit = 200 * 1024 * 1024; // 200 MB
    size_t currentMemoryUsage = 0;
    size_t objectSize = sizeof(Producto);

    int id = 0;
    while (currentMemoryUsage + objectSize <= memoryLimit) {
        productos.emplace_back(id++, "Producto" + std::to_string(id), id * 10.0);
        currentMemoryUsage += objectSize;
    }

    std::cout << "Cantidad de objetos agregados: " << productos.size() << std::endl;
    return 0;
}
