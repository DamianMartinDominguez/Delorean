#define altas 16
#define bajas 5
#define atras 4
#define flujo1 0
#define flujo2 2
#define girod 14
#define giroi 12
#define reactor1 13
#define reactor2 15

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(100);
  pinMode(atras,OUTPUT);
  pinMode(bajas,OUTPUT);
  pinMode(altas,OUTPUT);
  pinMode(flujo1,OUTPUT);
  pinMode(flujo2,OUTPUT);
  pinMode(girod,OUTPUT);
  pinMode(giroi,OUTPUT);
  pinMode(reactor1,OUTPUT);
  pinMode(reactor2,OUTPUT);

}

void loop() {
  digitalWrite(atras, HIGH);
  digitalWrite(bajas, HIGH);
  digitalWrite(altas, HIGH);
  digitalWrite(flujo1, HIGH);
  digitalWrite(flujo2, HIGH);
  digitalWrite(giroi, HIGH);
  digitalWrite(girod, HIGH);
  digitalWrite(reactor1, HIGH);
  digitalWrite(reactor2, HIGH);
   delay(500);
   digitalWrite(atras, HIGH);//luces marcha atras
  digitalWrite(bajas, HIGH);//luces marcha atras
  digitalWrite(altas, HIGH);//condensador de flujo bajas
  digitalWrite(flujo1, HIGH);//altas externas
  digitalWrite(flujo2, HIGH);//luces amarillas del tablero trasero 
  digitalWrite(giroi, HIGH);//condensador de flujo arriba
  digitalWrite(girod, HIGH);//giro derecho
  digitalWrite(reactor1, LOW);//tablero y posicion(bajas)
  digitalWrite(reactor2, HIGH);//giro izquierdo
   delay(500);
}
