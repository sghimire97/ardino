#include <M5StickCPlus.h>

const int soilSensorPin = 32; // Pin connected to the soil moisture sensor

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
}

void loop() {
  // Read the soil moisture value
  int soilMoisture = analogRead(soilSensorPin);

  // Map the sensor reading to a moisture percentage 
  int moisturePercentage = map(soilMoisture, 0, 4095, 0, 100);

  // Display the moisture percentage on the screen
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(10, 20);
  M5.Lcd.printf("Soil Moisture: %d%%", moisturePercentage);

  delay(1000); // Delay for 1 second before the next reading
}
