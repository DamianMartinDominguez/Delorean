
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

int contador = 0;
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 200;  // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledSuperior, OUTPUT);
  pinMode(ledInferior, OUTPUT);

  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    contador = contador+1;
    Serial.print("contador= ");
    Serial.println(contador);

    if(contador==1)
    {
    digitalWrite(ledVerde, HIGH);
    Serial.print("contador= ");
    Serial.println(contador);
    }
    else
    {

      if(contador==2)
      {
        digitalWrite(ledAmarillo, HIGH);
        Serial.print("contador= ");
        Serial.println(contador);
      }
      else
      {
      digitalWrite(ledAmarillo, LOW);  
      digitalWrite(ledVerde, LOW);
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
