#define BLYNK_TEMPLATE_ID "TMPL3o7Uj9a9k"
#define BLYNK_TEMPLATE_NAME "Temperature and humidity monitor"
#define BLYNK_AUTH_TOKEN "LQ4L0GR9gZBQXd93GMerXZPP5BgARp6s"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Blynk Auth & WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "MEHER1951";
char pass[] = "12345678";

// DHT Sensor Config
#define DHTPIN 4           // ESP32 GPIO 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Soil Moisture Sensor Pin
#define SOIL_PIN 34        // Analog pin on ESP32

BlynkTimer timer;

// Function to send data to Blynk
void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Celsius
  int soilValue = analogRead(SOIL_PIN);  // Raw analog value (0 - 4095)

  // Optional: Convert soil value to percentage
  int soilPercent = map(soilValue, 4095, 0, 0, 100);  // Adjust if needed

  if (isnan(h) || isnan(t)) {
    Serial.println("❌ Failed to read from DHT22 sensor!");
    return;
  }

  // Send to Blynk
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, soilPercent);  // Soil moisture to V2

  // Serial Monitor Output
  Serial.print("🌡️ Temp: ");
  Serial.print(t);
  Serial.print(" °C  💧 Humidity: ");
  Serial.print(h);
  Serial.print(" %  🌱 Soil Moisture: ");
  Serial.print(soilPercent);
  Serial.println(" %");
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2000L, sendSensor); // Every 2 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
