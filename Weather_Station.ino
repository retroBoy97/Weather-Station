#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2 //Data PIN connected to the arduino
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int humidity;
int temperature;
int dt = 2000;

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();

}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  if(isnan(humidity) || isnan(temperature)){ //isnan = is Not A Number
    Serial.print("Failed to reat from dht");
    lcd.print("Failed to reat from dht");
  }

  else{
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\tTemperature: ");
    Serial.print(temperature);
    Serial.println("C");

    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.print(temperature);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity:");
    lcd.print(humidity);
    lcd.print("%");
  }

  delay(dt);

}
