// ======================================================
// PRUEBA DE LUCES - DELOREAN
// ESP8266 NodeMCU
// ======================================================


// ----------------------
// PINES
// ----------------------

#define flujoab   16
#define azules      5
#define atras      4
#define altas      0
#define tableroa2  2
#define girod     14
#define flujoar   12
#define interior  13
#define giroi     15


void setup()
{
  // Debug console
  //Serial.begin(115200);
  delay(100);
  pinMode(atras,OUTPUT);
  pinMode(azules,OUTPUT);
  pinMode(altas,OUTPUT);
  pinMode(tableroa2,OUTPUT);
  pinMode(girod,OUTPUT);
  pinMode(flujoar,OUTPUT);
  pinMode(interior,OUTPUT);
  pinMode(giroi,OUTPUT);
  //pinMode(reactor2,OUTPUT);

}

void loop() {
  digitalWrite(atras, LOW);//luces marcha atras
  digitalWrite(azules, LOW);//luces marcha atras
  digitalWrite(flujoab, LOW);//condensador de flujo bajas
  digitalWrite(altas, LOW);//altas externas
  digitalWrite(tableroa2, LOW);//luces amarillas del tablero trasero 
  digitalWrite(flujoar, LOW);//condensador de flujo arriba
  digitalWrite(girod, LOW);//giro derecho
  digitalWrite(interior, LOW);//tablero y posicion(bajas)
  digitalWrite(giroi, LOW);//giro izquierdo
   delay(1500);
   digitalWrite(atras, HIGH);//luces marcha atras
  digitalWrite(azules, HIGH);//luces marcha atras
  digitalWrite(flujoab, LOW);//condensador de flujo bajas
  digitalWrite(altas, LOW);//altas externas
  digitalWrite(tableroa2, LOW);//luces amarillas del tablero trasero 
  digitalWrite(flujoar, LOW);//condensador de flujo arriba
  digitalWrite(girod, LOW);//giro derecho
  digitalWrite(interior, LOW);//tablero y posicion(bajas)
  digitalWrite(giroi, LOW);//giro izquierdo
   delay(1500);
}
