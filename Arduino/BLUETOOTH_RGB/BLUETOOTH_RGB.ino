#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "_kq_SbvsK6xFnYF67qEA7v2Sx7KfKkDi"

#define BLYNK_PRINT Serial

#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial SerialBLE(2, 3); // RX, TX
#include <BlynkSimpleSerialBLE.h>

char auth[] = BLYNK_AUTH_TOKEN;

int pinR = 11;
int pinG = 6;
int pinB = 5;

void setup()
{
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  Serial.println("Waiting for connections...");
}


void loop()
{
  Blynk.run();
}
