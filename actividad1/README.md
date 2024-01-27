## **Tipos de Kernel y sus diferencias**
Un kernel es el núcleo del sistema operativo que se encarga de administrar los recursos del sistema y proporcionar servicios a las aplicaciones. Existen varios tipos de kernels o núcleos:
- **Kernel monolítico:** Es un kernel grande que contiene todos los servicios del sistema operativo en un solo bloque de código. Solo define una interfaz virtual de alto nivel sobre el hardware del ordenador. Gestiona la memoria y procesos, así como de la comunicación entre los procesos y el soporte de las diferentes funciones de los drivers y el hardware. 
- **Microkernel:** Es un kernel pequeño que solo contiene los servicios más esenciales del sistema operativo. Su función principal es evitar el colapso total del sistema cuando se produzca algún fallo. Cuenta con diferentes módulos para cumplir con todas las tareas que realizaría un kernel monolítico.
- **Kernel Híbrido:** Es una combinación entre el kernel monolítico y el microkernel. El kernel híbrido comúnmente se implementa como un kernel monolítico con una arquitectura similar a la del microkernel.

<br>

Otros tipos de kernels no muy comúnes son:
- **Exokernel:** Fue creado con fines de investigación en el MIT sobre OpenBSD y otros sistemas operativos similares. Los exonúcleos son pequeños y se estructuran de manera vertical. Su propósito es crear una especie de capa de software para otros sistemas virtuales. Su funcionalidad está limitada a asegurar la protección y el multiplexado de recursos, que son muchísimo más simples que las implementaciones del paso de mensajes y las abstracciones de hardware de los núcleos monolíticos.
- **Nanokernel:** Es kernel pequeño (más pequeño que el microkernel) que ofrece abstracción de hardware, pero sin servicios del sistema.
- **Unikernel:** Es una imagen de máquina que contiene todo lo necesario para ejecutar una aplicación dentro de un solo paquete independiente. Se ejecutan directamente en un hipervisor o en metal desnudo, utilizando sistemas operativos de biblioteca para optimizar la seguridad, el tamaño y el rendimiento. Los unikernels ofrecen muchas ventajas en comparación con un sistema operativo tradicional, como una mayor seguridad, huella más pequeña, más optimización y tiempos de arranque más rápidos.

<br>

## **User Mode vs Kernel Mode**
El modo usuario (User Mode) y el modo kernel (Kernel Mode) son dos modos diferentes en los que se ejecuta el código en un sistema operativo. 

| User Mode | Kernel Mode |
|:---:|:---:|
| Modo en el que se ejecutan las aplicaciones de usuario. | Modo en el que se ejecutan los componentes principales del sistema operativo. |
| Tiene acceso limitado a los recursos del sistema. | Tiene acceso completo a los recursos del sistema. |
| Es más seguro, ya que las aplicaciones de usuario no pueden dañar el sistema operativo. | Es menos seguro, ya que los componentes del sistema operativo pueden dañar al mismo. |
| Cuando se produce un error no pasa nada grave | Un kernel panic puede colapsar todo el sistema. |
| Si una instrucción privilegiada se ejecuta aquí es ilegal y se generará una trampa. | Hay algunas instrucciones privilegiadas que solo se pueden ejecutar aquí, estas son instrucciones de interrupción, control de entrada y salida, entre otras. |

El sistema se inicia en modo kernel en el momento del arranque y, después de cargar el sistema operativo, ejecuta aplicaciones en modo usuario.

## **Interruptions vs traps**
Las interrupciones (interrumptions) y las trampas (traps) son dos mecanismos diferentes que se utilizan en los sistemas operativos para manejar eventos.

| Interruptions | Traps |
|:---:|:---:|
| Son señales emitidas por el software o el hardware cuando un proceso o evento requiere atención inmediata.| Se producen por el programa de usuario para invocar la funcionalidad del sistema operativo. |
| Es una señal que se envía al procesador para indicar que se ha producido un evento externo, como la llegada de un mensaje o la finalización de una operación de entrada/salida.| Es una señal que se genera internamente en el procesador para indicar que se ha producido un error o una excepción. |
| Se pueden enmascarar (ignorar) o desenmascarar (atender). | No se pueden enmascarar. |
| Son generadas por eventos externos. | Son generadas por eventos internos. |
| Son asíncronas. | Son síncronas. |
| Son menos activas | Son más activas |

