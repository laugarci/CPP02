# CPP02

## Ex00
**constructor de copia:** se utiliza para crear un nuevo objeto como una copia exacta de un objeto existente. Ejemplo:

```
FixedPoint::FixedPoint(const FixedPoint& other) : value(other.value) {}
```

- **``const FixedPoint& other``:** Esto indica que estás recibiendo una referencia constante al objeto que se va a copiar. El uso de referencia constante evita copias innecesarias y es más eficiente.
- **``: value(other.value)``:** Esto inicializa el miembro value del objeto actual (this) con el valor del objeto pasado como argumento (other). Es decir, estás haciendo una copia del valor.

En resumen, el constructor de copia crea un nuevo objeto FixedPoint que es una copia exacta de otro objeto FixedPoint.

**Operador de Asignación de Copia:** se utiliza para asignar el valor de un objeto existente a otro objeto ya existente de la misma clase. Ejemplo:

```
FixedPoint& FixedPoint::operator=(const FixedPoint& other) {
  if (this != &other) {  
    value = other.value; 
  }
  return *this;
}
```

- **``FixedPoint& FixedPoint::operator=``:** Esto define el operador de asignación para la clase FixedPoint y devuelve una referencia a FixedPoint para permitir operaciones encadenadas.
- **``const FixedPoint& other``**: Al igual que en el constructor de copia, estás recibiendo una referencia constante al objeto desde el cual deseas copiar.
- **``if (this != &other)``**: Este condicional verifica que no estás intentando asignar un objeto a sí mismo, lo que podría causar problemas.
- **``value = other.value;``**: Aquí estás copiando el valor del objeto other al objeto actual (this).

En resumen, el operador de asignación de copia permite asignar el valor de un objeto existente a otro objeto ya existente de la misma clase, evitando problemas de autoasignación.
