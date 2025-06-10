# 🧪 Ejercicio 19

## 📋 Enunciado

Simulacro de Parcial - Gestión de medicamentos por Obra Social

- Desarrollar una aplicación de escritorio con C++ y Qt que permita gestionar las cajas de medicamentos entregadas a una única obra social, respetando un límite máximo de 1000 dosis en total.
- La aplicación debe usar únicamente QWidget (no usar QMainWindow), y debe almacenar la información en una base de datos SQLite.
- La clase AdminDBMedicamentos debe implementarse como singleton.

### Requisitos

- Clase CajaMedicamento:
  - Atributos: `int id` (autogenerado), `float dosisTotales`
  - Métodos: constructor para nueva caja y para cargar desde la base, operadores `+` y `==`, método `toString()`
- Clase AdminDBMedicamentos (singleton):
  - Métodos: `conectar()`, `insertarCaja(float dosis)`, `obtenerTodas()`, `obtenerTotalDosis()`
- Base de datos SQLite: tabla `cajas_medicamentos` con estructura especificada.
- Interfaz gráfica:
  - Ingreso de dosis (QDoubleSpinBox)
  - Botón Agregar (verifica límite de 1000 dosis)
  - Lista de cajas (QListWidget)
  - Botón Sumar (combina dos cajas seleccionadas)
  - Botón Comparar (compara dos cajas seleccionadas)
- Restricciones:
  - NO usar QMainWindow, QPixmap, lambdas ni punteros a funciones para connect()
  - Usar SIGNAL() y SLOT(), QWidget como contenedor principal, AdminDB como singleton, SQLite con QSqlDatabase
