

#include <DHT.h>
#include <Arduino.h>
#define Thrs_temp 34.0

DHT dht(26,DHT11);
int buzz=15;

void setup()
{
 Serial.begin(115200);
 dht.begin();
 delay(3000);
  pinMode(buzz,OUTPUT);
  pinMode(4,OUTPUT);
  ledcSetup(0, 500, 8); // LEDC channel 0, 1000 Hz frequency, 8-bit resolution
  ledcAttachPin(buzz, 0);
}

void loop()
{
 float temp=dht.readTemperature();
 if(isnan(temp))
{
 Serial.println("Error in sensor,check wiring!!!");
}
else{
if(temp>Thrs_temp)
{
  ledcWrite(0,255);
  Serial.print("High Temperature detected with a value of: ");
  Serial.print(temp);
  Serial.println(" degree Celsius");
  delay(2000);
  digitalWrite(4,LOW);
}
else
{
   ledcWrite(0,0);
 Serial.print("Temperature in normal state with a value of: ");
 Serial.print(temp);
 Serial.println(" degree Celsius");
 delay(2000);
 digitalWrite(4,HIGH);
}
}
}