## Introducción

En este proyecto, me adentraré en la creación de una versión moderna del juego de memoria Simón. Este juego electrónico, que tuvo su auge en los años 80, sigue siendo una herramienta divertida y desafiante para ejercitar la memoria y la concentración.

El juego Simón se basa en una estructura sencilla: cuatro botones de colores (rojo, azul, amarillo y verde). Al encender el juego, Simón comienza iluminando uno de los botones al azar.  A medida que avanza, el juego añade un nuevo color a la secuencia, aumentando la dificultad con cada ronda.

El objetivo principal del juego es recordar y reproducir secuencias cada vez más largas y complejas de colores. Esta mecánica simple ayuda a mejorar habilidades cognitivas esenciales.

En mi proyecto, busco mejoras que puedan adaptarlo a las preferencias y tecnologías actuales. Esto incluirá el diseño de los circuitos electrónicos, la programación del comportamiento del juego y la creación de una interfaz de usuario.

## Desarrollo

### Objetivo del Proyecto

El objetivo principal del proyecto es diseñar y simular un juego "Simón Dice" utilizando una placa Arduino Nano y el software Proteus 8 Professional. El sistema debe incluir:
- Cuatro LEDs para mostrar las secuencias de colores.
- Cuatro botones para ingresar la secuencia.
- Una terminal virtual que indique si la secuencia ingresada es correcta, incorrecta o si he perdido por tiempo.

### Metodología

Para llevar a cabo el proyecto, seguí los siguientes pasos:

1. **Selección de Componentes:**
   - Placa Arduino Nano
   - 4 LEDs
   - 4 Botones
   - Software Proteus 8 Professional para la simulación
   - Arduino IDE para la programación
     
     ![image](https://github.com/vzblea/Proyecto-Arduino/assets/170975757/65f61658-4c96-4351-af6c-1a27817cc36a)


2. **Desarrollo del Código:** El código en Arduino fue diseñado para generar una secuencia aleatoria de colores, mostrarla mediante LEDs y verificar la secuencia ingresada.

3. **Simulación en Proteus:** La simulación se llevó a cabo en Proteus 8 Professional, permitiendo validar el correcto funcionamiento del circuito y la lógica del juego.

### Informe del Funcionamiento del Código

#### Biblioteca y Variables

El código utiliza la biblioteca EEPROM.h para almacenar y recuperar la secuencia de colores generada. Las principales variables utilizadas son:
- <font size="4"><strong>`cntjuego`</strong></font>: un contador de juegos que lleva el número de secuencias generadas.
- <font size="4"><strong>`color`</strong></font>: una variable para almacenar el color generado aleatoriamente.

#### Configuración Inicial

En la función `setup()`, se configura la comunicación serial a 9600 baudios y se inicializan los pines 4 a 11 como salidas, esenciales para controlar los LEDs y leer las entradas del usuario.

#### Bucle Principal

El `loop()` contiene tres llamadas a funciones clave:
- <font size="4"><strong>`crearColor()`</strong></font>: Genera un nuevo color aleatorio y lo almacena en la EEPROM.
- <font size="4"><strong>`mostrarColor()`</strong></font>: Muestra la secuencia de colores generada hasta el momento.
- <font size="4"><strong>`comprobarRespuesta()`</strong></font>: Verifica si la respuesta ingresada es correcta.

#### Función `crearColor()`

Esta función incrementa el contador de juegos, genera un color aleatorio entre 1 y 4, y lo guarda en la EEPROM. Los valores de los colores se almacenan en la EEPROM con valores específicos (17, 18, 20 y 24) que corresponden a diferentes pines de salida.

#### Función `mostrarColor()`

Esta función recorre la secuencia de colores almacenados en la EEPROM y enciende el LED correspondiente a cada color durante 500 milisegundos.

#### Función `comprobarRespuesta()`

En esta función, se verifica la respuesta comparándola con la secuencia almacenada. Se espera una entrada hasta que se presione un botón. Si la respuesta es correcta, el juego continúa; de lo contrario, todos los LEDs parpadean para indicar un error. Si se tarda demasiado en responder, se indica una pérdida por tiempo.

## Conclusiones

El código presentado implementa un juego de memoria en un microcontrolador Arduino, donde debo reproducir una secuencia aleatoria de colores generada por el sistema. A lo largo del desarrollo del código, se utilizan diversas técnicas para interactuar con el hardware, como el uso de la biblioteca EEPROM para almacenar datos de manera persistente y la manipulación de pines digitales para controlar LEDs.

Este programa no solo proporciona una experiencia de juego interactiva, sino que también demuestra varios conceptos importantes, como la generación de números aleatorios, la lectura de entradas digitales y el control de salidas. Además, la implementación de mecanismos para verificar las respuestas y gestionar errores (como respuestas incorrectas o demoras excesivas) muestra cómo se pueden manejar diferentes escenarios en una aplicación de tiempo real.

He realizado pruebas de mi código y he llegado a la conclusión de algunas mejoras posibles que podría realizar en un futuro:
- **Mejoras en el random:** Para evitar los patrones predecibles.
- **Agregar sonido:** El sonido hace el juego más interactivo y atractivo. Se pueden utilizar diferentes tonos para indicar eventos como la creación de un color, la correcta reproducción de la secuencia y los errores.
- **Menor tiempo de espera en cada nueva secuencia:** Un menor tiempo de espera en cada secuencia para que sea más dinámico.

