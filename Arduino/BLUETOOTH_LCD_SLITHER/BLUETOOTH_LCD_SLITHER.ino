#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_AUTH_TOKEN            "_kq_SbvsK6xFnYF67qEA7v2Sx7KfKkDi"

#define BLYNK_PRINT Serial

#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial SerialBLE(2, 3); // RX, TX
#include <BlynkSimpleSerialBLE.h>

char auth[] = BLYNK_AUTH_TOKEN;

Servo servo_;
WidgetLCD lcd(V1);
int rotacion_servo = 0;
int rotacion_servo_actual = 0;

BLYNK_WRITE(V3)
{
  rotacion_servo = param.asInt();
  if(rotacion_servo_actual != rotacion_servo)
  {
    servo_.write(rotacion_servo_actual);
  }
  rotacion_servo_actual = rotacion_servo;
}


void setup()
{
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  servo_.attach(9);

  Serial.println("Waiting for connections...");
}


void loop()
{
  if(rotacion_servo<100)
  {
      lcd.clear();
    }
  lcd.print(4, 0, String(rotacion_servo));
  Blynk.run();

}
