#include <iostream>
using namespace std;

class CuentaBancaria; // Declaración adelantada

// Declaración de la función amiga
bool compararSaldo(CuentaBancaria, CuentaBancaria);

class CuentaBancaria {
public:
    // Constructor que recibe el saldo inicial
    CuentaBancaria(int saldoInicial) : saldo(saldoInicial) {}

    // Método para depositar dinero
    void depositar(int monto) {
        saldo += monto;
    }

    // Método para mostrar el saldo
    void mostrar() const {
        cout << "Saldo: " << saldo << endl;
    }

    // Declaración de función amiga
    friend bool compararSaldo(CuentaBancaria, CuentaBancaria);

private:
    int saldo;
};

// Definición de la función amiga
bool compararSaldo(CuentaBancaria c1, CuentaBancaria c2) {
    return c1.saldo > c2.saldo;
}

int main() {
    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2(500);

    cuenta1.depositar(500);
    cuenta2.depositar(200);

    cout << "Cuenta 1: "; cuenta1.mostrar();
    cout << "Cuenta 2: "; cuenta2.mostrar();

    if (compararSaldo(cuenta1, cuenta2))
        cout << "La cuenta 1 tiene mayor saldo que la cuenta 2." << endl;
    else
        cout << "La cuenta 2 tiene mayor saldo o igual que la cuenta 1." << endl;

    return 0;
}
