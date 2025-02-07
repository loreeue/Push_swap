## Push Swap

**Push Swap** es un proyecto desarrollado en **42 Madrid** que consiste en diseñar un algoritmo eficiente para ordenar una lista de números utilizando solo un conjunto limitado de operaciones sobre dos pilas. El objetivo principal es minimizar el número de movimientos requeridos.

![Logo 42 Madrid](42-Madrid.jpeg)

### Descripción del Proyecto

El programa toma como entrada una serie de números enteros y los ordena utilizando únicamente un conjunto de operaciones específicas sobre dos pilas (*stack A* y *stack B*). La optimización del número de movimientos es clave para superar las pruebas de rendimiento.

#### Características Principales

- **Ordenación eficiente** de listas de números con el mínimo número de operaciones.
- **Gestión de estructuras de datos dinámicas** (pilas enlazadas).
- **Validación de entrada y manejo de errores**.
- **Optimización de movimientos** mediante estrategias como encontrar el número más "barato" para mover y sincronización de rotaciones.
- **Implementación modular** con código organizado en funciones específicas.

### Archivos Incluidos

- `push_swap.c`: Función principal que inicializa las pilas y maneja la entrada de datos.
- `validate_input.c`: Comprueba que los argumentos sean correctos y sin duplicados.
- `sort.c`: Implementa el algoritmo de ordenación.
- `sort_utils.c`: Funciones auxiliares para manipular las pilas durante la ordenación.
- `stack_utils.c`: Funciones para la creación y manipulación de las pilas.
- `big_small.c`: Determina los valores mínimo y máximo en la pila.
- `cheapest.c`: Encuentra el número con el menor coste de movimiento.
- `push_cheapest.c`: Mueve el número más "barato" a su posición óptima.
- `target.c`: Encuentra la posición correcta de un número en la pila.
- `frees.c`: Funciones para liberar memoria correctamente.
- `handle_errors.c`: Manejo de errores en la entrada.
- `push_swap.h`: Cabecera con estructuras de datos y prototipos de funciones.
- `Makefile`: Compila el proyecto y gestiona reglas como `all`, `clean`, `fclean`, `re`.

### Cómo Usarlo

1. **Compilación:**
   ```bash
   make
   ```

2. **Ejecución:**
   ```bash
   ./push_swap <número1> <número2> <número3> ...
   ```
   Ejemplo:
   ```bash
   ./push_swap 4 67 3 87 23
   ```

3. **Salida esperada:**
   - El programa imprimirá en **stdout** la secuencia de movimientos necesaria para ordenar la pila de la manera más eficiente posible.
   - Si la entrada no es válida (valores no numéricos, duplicados, etc.), imprimirá `"Error"` en la salida de error estándar.

### Operaciones Permitidas

El programa solo puede utilizar las siguientes operaciones sobre las pilas:

- `sa` / `sb` / `ss` – Intercambia los dos primeros elementos de una pila.
- `pa` / `pb` – Mueve el primer elemento de una pila a la otra.
- `ra` / `rb` / `rr` – Rota la pila hacia arriba.
- `rra` / `rrb` / `rrr` – Rota la pila hacia abajo.

### Estrategias de Optimización

El algoritmo implementado sigue una estrategia **voraz** y busca minimizar la cantidad de movimientos. Entre las técnicas utilizadas se incluyen:

- **Selección del número más "barato"** para mover a la otra pila.
- **Sincronización de rotaciones** para reducir movimientos innecesarios.
- **Colocación eficiente de los números en la pila final** evitando reordenamientos adicionales.

### Pruebas de Rendimiento

El proyecto debe cumplir con ciertos límites de movimientos para validar su eficiencia:

- Para **100 números aleatorios**, el algoritmo debe ordenarlos en **menos de 700 operaciones**.
- Para **500 números aleatorios**, el algoritmo debe ordenarlos en **menos de 5500 operaciones**.

Si el número de operaciones es demasiado alto, la evaluación fallará.

### Aclaración

Este proyecto sigue los estándares de la **Norma de 42** y debe ejecutarse correctamente sin producir errores inesperados.
