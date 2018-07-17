#include "DHTesp.h"

DHTesp dht;

void setup()
{
  Serial.begin(74880);
  delay(100);
  Serial.println();
  Serial.println("Good morning");

  dht.setup(2); // Connect DHT sensor to GPIO 2 (Pin D4)
}

void loop()
{
  int feuchtVal = analogRead (A0);
  Serial.print("Feutigkeitsmesser: ");
  Serial.print(feuchtVal);
  Serial.print("\t");
  
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.println(temperature, 1);
  Serial.println("Sleeping");
  ESP.deepSleep(20e6);
}

