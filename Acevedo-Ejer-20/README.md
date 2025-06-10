# 🧪 Ejercicio 20

## 📋 Enunciado

- Crear una clase base llamada `Instrumento` y las clases derivadas `Guitarra`, `Bateria` y `Teclado`.
- La clase base tiene una función virtual pura llamada `sonar()`.
- Definir una función virtual `verlo()` que publique la marca del instrumento (por defecto "Yamaha").
- En `main()`, usar un `std::vector` para almacenar punteros a `Instrumento`. Instanciar 5 objetos y agregarlos al vector.
- Publicar la marca de cada instrumento recorriendo el vector.
- En las clases derivadas, agregar los miembros: `int cuerdas` (Guitarra), `int teclas` (Teclado), `int tambores` (Batería) con valores por defecto.
- Hacer que `Teclado` tenga herencia múltiple de una clase `Electrico` (voltaje por defecto 220V, destructor publica "Desenchufado").
- Al llamar a `sonar()`, debe publicar "Guitarra suena...", "Teclado suena..." o "Batería suena..." según corresponda.
- Incluir los métodos `get` y `set` necesarios.
