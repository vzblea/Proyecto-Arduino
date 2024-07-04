#include <EEPROM.h> // Biblioteca para utilizar la memoria EEPROM

int cntjuego = 0; // Contador de juegos
int color = 0; // Variable para almacenar el color generado

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
  pinMode(4, OUTPUT); // Configura el pin 4 como salida
  pinMode(5, OUTPUT); // Configura el pin 5 como salida
  pinMode(6, OUTPUT); // Configura el pin 6 como salida
  pinMode(7, OUTPUT); // Configura el pin 7 como salida
  pinMode(8, OUTPUT); // Configura el pin 8 como salida
  pinMode(9, OUTPUT); // Configura el pin 9 como salida
  pinMode(10, OUTPUT); // Configura el pin 10 como salida
  pinMode(11, OUTPUT); // Configura el pin 11 como salida
}

void loop() {
  crearColor(); // Llama a la función que crea un color aleatorio
  mostrarColor(); // Muestra la secuencia de colores almacenados
  comprobarRespuesta(); // Comprueba si la respuesta del usuario es correcta
}

void crearColor() {
  cntjuego++; // Incrementa el contador de juegos
  color = random(1, 5); // Genera un color aleatorio entre 1 y 4

  // Guarda el color en la EEPROM en función del valor generado
  switch (color) {
    case 1:
      EEPROM.write(cntjuego, 17);
      break;
    case 2:
      EEPROM.write(cntjuego, 18);
      break;
    case 3:
      EEPROM.write(cntjuego, 20);
      break;
    case 4:
      EEPROM.write(cntjuego, 24);
      break;
    default:
      break;
  }
  Serial.println(cntjuego); // Imprime el número de juego
  Serial.print("Color creado: "); // Imprime el color creado
  Serial.println(EEPROM.read(cntjuego));
  Serial.println("");
}

void mostrarColor() {
  // Muestra la secuencia de colores almacenados en la EEPROM
  for (int i = 1; i < cntjuego + 1; i++) {
    if (i == 1) {
      Serial.println("Nueva Secuencia"); // Imprime que es una nueva secuencia
    }
    delay(500); // Espera 500 milisegundos
    Serial.print("Se ejecuta "); // Imprime el número de ejecución
    Serial.println(i);

    // Enciende y apaga el LED correspondiente al color almacenado
    switch (EEPROM.read(i)) {
      case 17:
        Serial.println("Color guardado: 17, salida 4");
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4, LOW);
        break;
      case 18:
        Serial.println("Color guardado: 18, salida 5");
        digitalWrite(5, HIGH);
        delay(500);
        digitalWrite(5, LOW);
        break;
      case 20:
        Serial.println("Color guardado: 20, salida 6");
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        break;
      case 24:
        Serial.println("Color guardado: 24, salida 7");
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
        break;
      default:
        break;
    }
  }
}

void comprobarRespuesta() {
  // Comprueba la respuesta del usuario para cada color en la secuencia
  for (int i = 1; i < cntjuego + 1; i++) {
    float cntCompr = 0; // Contador para el tiempo de espera
    int respuesta = 0; // Variable para almacenar la respuesta del usuario
    Serial.print("Variable i= ");
    Serial.println(i);
    
    // Espera hasta que el usuario proporcione una respuesta
    while (1) {
      // Lee las entradas digitales y las combina en un valor
      respuesta = 0b00010000 | digitalRead(11) << 3 | digitalRead(10) << 2 | digitalRead(9) << 1 | digitalRead(8);
      if (respuesta != 16) {
        Serial.print("Respuesta = ");
        Serial.println(respuesta);
        // Si la respuesta es correcta, se rompe el bucle
        if (respuesta == EEPROM.read(i)) {
          Serial.println("Correcto");
          respuesta = 16;
          delay(500);
          break;
        } else {
          // Si la respuesta es incorrecta, se indica y se hace parpadear los LEDs
          while (1) {
            Serial.println("Incorrecto");
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            delay(500);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            delay(500);
          }
        }
      }
      cntCompr++;
      // Si el contador de tiempo supera un umbral, se indica que se pierde por tiempo
      if (cntCompr >= 50000) {
        while (1) {
          Serial.println("Pierdes por tiempo");
          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(7, HIGH);
          delay(500);
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          delay(600);
        }
      }
    }
  }
}
