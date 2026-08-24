// ======================================================
// PRUEBA DE LUCES - DELOREAN
// ESP8266 NodeMCU
// ======================================================


// ----------------------
// PINES
// ----------------------

#define flujoab   16
#define atras      5
#define bajas      4
#define altas      0
#define tableroa2  2
#define girod     14
#define flujoar   12
#define interior  13
#define giroi     15


// ======================================================
// CONFIGURACION
// ======================================================

unsigned long tiempoEncendido = 1000;  // 1 segundo
unsigned long tiempoApagado   = 500;   // 0,5 segundos


// ======================================================
// ESTRUCTURA DE LAS LUCES
// ======================================================

struct Luz {
  int pin;
  const char* nombre;
};


// Lista de luces

Luz luces[] = {

  {flujoab,   "Flujo abajo"},
  {atras,     "Luces traseras"},
  {bajas,     "Luces bajas"},
  {altas,     "Luces altas"},
  {tableroa2, "Tablero trasero"},
  {girod,     "Giro derecho"},
  {flujoar,   "Flujo arriba"},
  {interior,  "Luces interiores"},
  {giroi,     "Giro izquierdo"}

};


// Cantidad de luces

const int cantidadLuces = sizeof(luces) / sizeof(luces[0]);


// ======================================================
// VARIABLES
// ======================================================

int luzActual = 0;

bool luzEncendida = false;

unsigned long tiempoAnterior = 0;


// ======================================================
// SETUP
// ======================================================

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("================================");
  Serial.println(" PRUEBA DE LUCES - DELOREAN");
  Serial.println("================================");
  Serial.println();


  // Configuramos todos los pines

  for (int i = 0; i < cantidadLuces; i++) {

    pinMode(luces[i].pin, OUTPUT);

    digitalWrite(luces[i].pin, LOW);
  }


  Serial.println("Comenzando prueba...");
  Serial.println();

  tiempoAnterior = millis();
}


// ======================================================
// LOOP
// ======================================================

void loop() {

  unsigned long ahora = millis();


  // ------------------------------------------
  // ENCENDER LUZ
  // ------------------------------------------

  if (!luzEncendida) {

    if (ahora - tiempoAnterior >= tiempoApagado) {

      tiempoAnterior = ahora;

      digitalWrite(luces[luzActual].pin, HIGH);

      luzEncendida = true;


      Serial.print("ENCENDIENDO: ");
      Serial.print(luces[luzActual].nombre);
      Serial.print("  | GPIO ");
      Serial.println(luces[luzActual].pin);
    }
  }


  // ------------------------------------------
  // APAGAR LUZ
  // ------------------------------------------

  else {

    if (ahora - tiempoAnterior >= tiempoEncendido) {

      tiempoAnterior = ahora;

      digitalWrite(luces[luzActual].pin, LOW);

      luzEncendida = false;


      Serial.print("APAGANDO: ");
      Serial.println(luces[luzActual].nombre);


      // Pasamos a la siguiente luz

      luzActual++;


      // Si llegamos al final, volvemos a empezar

      if (luzActual >= cantidadLuces) {

        luzActual = 0;

        Serial.println();
        Serial.println("---------- FIN DE CICLO ----------");
        Serial.println();
      }
    }
  }
}
