*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/
#define flujo1 16 //D0 condensador de flujo abajo
#define neon 5  //D1 neon
#define atras 4  //D2 luces marcha atras
#define altas 0 //D3 altas externas
#define amarilla 2 //D4 luces amarillas del tablero trasero
#define girod 14 //D5 giro derecho
#define flujo2 12 //D6 condensador de flujo arriba
#define bajas 13 //D7 tablero y posicion(bajas)
#define giroi 15 //D8 giro izquierdo
/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL2GP5lSre1"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "VFf6EDWoj6vwfx793RmKOIKUDfpUwasU"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



unsigned long previousMillis = 0;
int paso = 0;
bool secuenciaActiva = false;

const long interval = 300; // Intervalo de 100 milisegundos
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LaManada";
char pass[] = "arquimedes";
bool izquierda=LOW;
bool derecha=LOW;
bool balizas=0;
bool izquierda1=LOW;
bool derecha1=LOW;
bool balizas1=0;
bool condensador=0;
BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)//condensador
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V0, value);
  condensador=value;
}

BLYNK_WRITE(V1)//neon
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
  digitalWrite(neon, value);
}

BLYNK_WRITE(V2)//D2 luces marcha atras
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V2, value);
  digitalWrite(atras, value);
}

BLYNK_WRITE(V3)//D3 altas externas
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V3, value);
  digitalWrite(altas, value);
}

BLYNK_WRITE(V4)//D4 luces amarillas del tablero trasero
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V4, value);
  digitalWrite(amarilla, value);
}

BLYNK_WRITE(V5)//D5 giro derecho
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
 derecha=value;
  // Update state
  Blynk.virtualWrite(V5, value);
  digitalWrite(girod, value);
}

BLYNK_WRITE(V6)//D6 Balizas
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V6, value);
  balizas=bool(value);
}

BLYNK_WRITE(V7)//D7 tablero y posicion(bajas)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V7, value);
  digitalWrite(bajas, value);
}

BLYNK_WRITE(V8)//D8 giro izquierdo
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
 izquierda=value;
  // Update state
  Blynk.virtualWrite(V8, value);
  digitalWrite(giroi, value);
}



// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
//void myTimerEvent()
//{
//  // You can send any value at any time.
//  // Please don't send more that 10 values per second.
//  Blynk.virtualWrite(V2, millis() / 1000);
//}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  //timer.setInterval(1000L, myTimerEvent);
  pinMode (flujo1,OUTPUT); 
  pinMode (neon,OUTPUT);
  pinMode (atras,OUTPUT);
  pinMode (altas,OUTPUT);
  pinMode (amarilla,OUTPUT);
  pinMode (girod,OUTPUT);
  pinMode (flujo2,OUTPUT);
  pinMode (bajas,OUTPUT);
  pinMode (giroi,OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  unsigned long currentMillis = millis();

  if(izquierda==HIGH)
{
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    izquierda1 = !izquierda1; // Cambia el estado
    digitalWrite(giroi, izquierda1);
  }
}
if(derecha==HIGH)
{
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    derecha1 = !derecha1; // Cambia el estado
    digitalWrite(girod, derecha1);
  }
}
if(balizas==HIGH)
{
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    balizas1 = !balizas; // Cambia el estado
    digitalWrite(girod, balizas1);
    digitalWrite(giroi, balizas1);


}
}
 if (condensador == HIGH) { // Si está encendido

  switch (paso) {
    case 0: // Encender flujo1
      digitalWrite(flujo1, HIGH);
      digitalWrite(flujo2, LOW);
      paso = 1;
      break;

    case 1: // Esperar 300 ms y luego cambiar
      if (currentMillis - previousMillis >= 300) {
        digitalWrite(flujo1, LOW);
        digitalWrite(flujo2, HIGH);
        paso = 2;
      }
      break;

    case 2: // Esperar otros 500 ms
      if (currentMillis - previousMillis >= 500) {
        digitalWrite(flujo1, LOW);
        digitalWrite(flujo2, LOW);
        paso = 0;
      }
      break;
  }

} else {
  digitalWrite(flujo1, LOW);
  digitalWrite(flujo2, LOW);
}
  
  }

