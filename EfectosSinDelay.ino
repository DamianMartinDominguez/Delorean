
// constants won't change. Used here to set a pin number:
const int ledSuperior = 41;  // the number of the LED pin
const int ledInferior = 49;

const int ledAmarillo = 43;  // the number of the LED pin
const int ledVerde = 45;

// Variables will change:
int ledStateSuperior = LOW;  // ledState used to set the LED
int ledStateInferior = LOW;

int ledStateAmarillo = LOW;  // ledState used to set the LED
int ledStateVerde = LOW;
int BalizasState = LOW;

int contador = 0;
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated
unsigned long previousMillis2 = 0;

// constants won't change:
const long interval = 100;  // interval at which to blink (milliseconds)
const long intervalBalizas = 500;

void setup() {
  // set the digital pin as output:
  pinMode(ledSuperior, OUTPUT);
  pinMode(ledInferior, OUTPUT);

  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

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
  pinMode(47, OUTPUT);
  pinMode(51, OUTPUT);


  Serial.begin(9600);
}

void loop() 
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  unsigned long currentMillis2 = millis();
  
  digitalWrite(37, HIGH);

  if (currentMillis2 - previousMillis2 >= intervalBalizas) {
      previousMillis2 = currentMillis2;
      if (BalizasState == LOW) {
      BalizasState = HIGH;
    } else {
      BalizasState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(47, BalizasState);
    digitalWrite(51, BalizasState);
  }


  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    contador = contador+1;
    Serial.print("contador= ");
    Serial.println(contador);

    if(contador==1)
    {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(26, LOW);
    digitalWrite(28, LOW);

    Serial.print("contador= ");
    Serial.println(contador);
    }
    else
    {

      if(contador==2)
      {

        digitalWrite(ledAmarillo, HIGH);
        digitalWrite(22, LOW);
        digitalWrite(24, LOW);
        digitalWrite(30, LOW);
        digitalWrite(32, HIGH);
        digitalWrite(34, HIGH);
        digitalWrite(36, HIGH);
        Serial.print("contador= ");
        Serial.println(contador);
      }
      else
      {
      digitalWrite(ledAmarillo, LOW);  
      digitalWrite(ledVerde, LOW);
      digitalWrite(32, LOW);
      digitalWrite(34, LOW);
      digitalWrite(36, LOW);
      digitalWrite(26, HIGH);
      digitalWrite(28, HIGH);
      
      contador = 0;
      Serial.print("contador= ");
      Serial.println(contador);
      }
    }
    
    
    

    // if the LED is off turn it on and vice-versa:
    if (ledStateSuperior == LOW) {
      ledStateSuperior = HIGH;
      ledStateInferior = LOW;

    } else {
      ledStateSuperior = LOW;
      ledStateInferior = HIGH;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledSuperior, ledStateSuperior);
    digitalWrite(ledInferior, ledStateInferior);

  }
  
}
