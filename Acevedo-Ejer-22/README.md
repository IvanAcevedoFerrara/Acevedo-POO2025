# 🧪 Ejercicio 22

## 📋 Enunciado

Inline en acción — Simulador de Sensor Inteligente

### Parte 1: Diseño de la clase Sensor

- Implementar una clase Sensor con:
  - Atributo: `int valorActual` (inicializable entre 0 y 1023)
  - Métodos:
    - `int getValorBruto()` (inline implícito)
    - `int getValorBrutoOffline()` (definido fuera de la clase)
    - `double getValorNormalizado()` (inline explícito)
    - `double getValorNormalizadoOffline()` (sin inline)

### Parte 2: Benchmark de rendimiento

- Usar QElapsedTimer para medir el tiempo de ejecución de:
  - 10 millones de llamadas a cada método anterior.
- Mostrar los tiempos en consola con qDebug().
