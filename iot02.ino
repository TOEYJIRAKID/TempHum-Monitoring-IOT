#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

float temperature;
float humidity;
DHT dht14(D4,DHT11);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  temperature = 0;
  humidity = 0;
  Serial.begin(9600);
  dht14.begin();
}

void loop()
{
  lcd.begin();

  lcd.setCursor(0, 0);
  lcd.print("Hum : ");
  lcd.print(humidity);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.print(temperature);
  lcd.print(" C");
  delay(500);

  humidity = (dht14.readHumidity());
  temperature = (dht14.readTemperature());
  Serial.print("Temp : ");
  Serial.print(temperature);
  Serial.print("Hum : ");
  Serial.println(humidity);
  delay(500);
}
