

#define BLYNK_TEMPLATE_ID "TMPLUsFmNnAS"
#define BLYNK_TEMPLATE_NAME "Delorean"
#define BLYNK_AUTH_TOKEN            "aXzUiNvHJJeNUEshnWE4LTaEWOt91ksn"
#define altas 16
#define bajas 5
#define atras 4
#define flujo1 0
#define flujo2 2
#define girod 14
#define giroi 12
#define reactor1 13
#define reactor2 15



// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LaManada";
char pass[] = "arquimedes";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
/*void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}*/

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


  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  ////////////////timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  /////////////timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

BLYNK_WRITE(V0)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(altas, value);
}

BLYNK_WRITE(V1)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(bajas, value);
}


BLYNK_WRITE(V2)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(atras, value);
}

BLYNK_WRITE(V3)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(flujo1, value);
}


BLYNK_WRITE(V4)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(flujo2, value);
}
    

BLYNK_WRITE(V5)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(girod, value);
}

BLYNK_WRITE(V6)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(giroi, value);
}

BLYNK_WRITE(V7)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(reactor1, value);
}

BLYNK_WRITE(V8)
{   
  int value = param.asInt(); // Get value as integer
digitalWrite(reactor2, value);
}




  
