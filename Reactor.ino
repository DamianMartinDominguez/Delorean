/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#define A 50
#define B 36 // 22 24 30 34 36 32 28 26
int i;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(20, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);
  
  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(53, OUTPUT);


}

// the loop function runs over and over again forever
void loop() {

  /*
  // 22 24 30 34 36 32 28 26
  digitalWrite(22, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(22, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 
  
  digitalWrite(24, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(24, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 

  digitalWrite(30, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(30, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 

  digitalWrite(34, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(34, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 

  digitalWrite(36, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(36, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 

  digitalWrite(32, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(32, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 

  digitalWrite(28, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(28, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 
  
  digitalWrite(26, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(A);                      // wait for a second
  digitalWrite(26, LOW);   // turn the LED off by making the voltage LOW
  delay(A); 

  */
                       // wait for a second
  //digitalWrite(37, HIGH);          //luces bajas           
  //digitalWrite(39, HIGH);          //Marcha atras
  //digitalWrite(41, HIGH);          //condensador de flujo superior 
  //digitalWrite(43, HIGH);          //luz amarilla
  //digitalWrite(45, HIGH);          //luz verde
  //digitalWrite(47, HIGH);          //luz de giro acompañante
  //digitalWrite(49, HIGH);          //condensador de flujo inferior
  //digitalWrite(51, HIGH);          //luz de giro conductor
  //digitalWrite(53, HIGH);          //luces altas
  
  digitalWrite(49, HIGH);
  delay(A);
  digitalWrite(49, LOW);
  delay(A);
  digitalWrite(41, HIGH);
  delay(A);
  digitalWrite(41, LOW);
  delay(A);
  
}
