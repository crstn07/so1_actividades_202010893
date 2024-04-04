## Completely Fair Scheduler (CFS) 

El Completely Fair Scheduler (CFS) es el planificador de procesos por defecto en el kernel de Linux desde la versión 2.6.23, lanzada en 2007. Fue diseñado para proporcionar un reparto de CPU justo y equitativo entre los procesos, evitando la inanición de procesos y mejorando la capacidad de respuesta del sistema. 

### Características principales:

1. **Modelo de programación basado en recursos virtuales**: CFS utiliza un modelo en el que cada tarea tiene asignados unos recursos virtuales (tiempo de CPU y ancho de banda de memoria) que se consumen a una tasa especificada. Esto permite un reparto justo de los recursos del sistema entre todas las tareas.

2. **Árbol jerárquico de scheduling**: Las tareas se organizan en un árbol jerárquico, donde cada nodo representa un grupo de tareas. Esto permite controlar la asignación de recursos de forma colectiva para grupos de procesos. Las tareas se organizan en un árbol rojo-negro balanceado, donde las tareas con menor `vruntime` están a la izquierda. Esto permite encontrar la tarea de mayor prioridad de forma eficiente.

3. **Prioridades y peso**: Cada tarea tiene asignada una prioridad y un peso relativo dentro de su grupo. Las tareas con mayor peso recibirán más tiempo de CPU.

4. **Tiempo Virtual Normalizado (vruntime)**: CFS utiliza un valor llamado `vruntime` para realizar el seguimiento del uso de CPU de cada tarea. Este valor se incrementa a medida que la tarea consume tiempo de CPU. La tarea con el menor valor de `vruntime` es la siguiente en ejecutarse.

5. **Planificación basada en tiempo**: CFS intenta planificar cada tarea durante un intervalo de tiempo llamado "período de planificación". Esto ayuda a reducir la latencia y mejorar la capacidad de respuesta del sistema.

6. **Balance de carga**: CFS intenta distribuir la carga de trabajo entre los diferentes núcleos de CPU disponibles, lo que mejora el rendimiento en sistemas multinúcleo.

7. **Jerarquía de dominios de planificación**: CFS agrupa los núcleos en una jerarquía de dominios de planificación según cómo comparten recursos (caché L1, L2, L3, nodos NUMA). El equilibrio de carga se realiza primero dentro de los dominios de menor nivel para minimizar las penalizaciones de NUMA.

### Funcionamiento:

1. Inicialmente, todas las tareas tienen un `vruntime` de cero.
2. CFS selecciona la tarea con el menor valor de `vruntime` para ejecutarse.
3. La tarea seleccionada se ejecuta durante un período de planificación o hasta que sea bloqueada o expulsada.
4. Mientras la tarea se ejecuta, su `vruntime` se incrementa para reflejar el tiempo de CPU consumido.
5. Cuando una tarea se bloquea o se expulsa, CFS selecciona la siguiente tarea con el menor valor de `vruntime` para ejecutarla.
6. Este proceso se repite continuamente, asegurando que todas las tareas reciban una porción justa de tiempo de CPU.

El objetivo principal de CFS es proporcionar un reparto justo de recursos del sistema, evitando la inanición de procesos y mejorando la capacidad de respuesta general del sistema operativo. Además, su diseño jerárquico y su capacidad para controlar grupos de tareas lo hacen adecuado para entornos con diversos requisitos de planificación.areas se organizan en un árbol jerárquico, donde cada nodo representa un grupo de tareas. Esto permite controlar la asignación de recursos de forma colectiva para grupos de procesos.
