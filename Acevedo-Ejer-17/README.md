# 🧪 Ejercicio 17

## 📋 Enunciado

- Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana.
- Crear una clase Boton que hereda de QWidget.
- Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color.
- Definir el siguiente método en Boton:
  ```cpp
  Boton *boton = new Boton;
  boton->colorear(Boton::Azul);
  ```
  - Este método recibe como parámetro una enumeración que puede ser: `Boton::Azul`, `Boton::Verde`, `Boton::Magenta`.
- Usar QtDesigner para Ventana y Boton (Designer Form Class).
- Definir la enumeración en Boton.
- Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos.
- Que esta Ventana con botones quede lo más parecido a la imagen de referencia.
- Usar grid layout, espaciadores y recursos del QtDesigner.
- Dibujar un fondo agradable con paintEvent y drawImage.
- Que Boton tenga la señal `signal_clic()`.
