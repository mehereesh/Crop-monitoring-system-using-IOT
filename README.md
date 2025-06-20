# Crop-monitoring-system-using-IOT
# 🌱 IoT-Based Soil and Climate Monitoring System using ESP32
Real time crop monitoring Using IOT
##🌡️ Temperature, Humidity, and Soil Moisture Monitoring System using ESP32 + Blynk

Monitor environmental data such as **temperature**, **humidity**, and **soil moisture** in real time using an **ESP32**, **DHT22**, and a **Soil Moisture Sensor**. The data is displayed live on the **Blynk IoT dashboard**.

---

## 🔧 Components Used

| Component             | Quantity |
|-----------------------|----------|
| ESP32 Dev Board       | 1        |
| DHT22 Sensor          | 1        |
| Soil Moisture Sensor  | 1        |
| Jumper Wires          | As needed |
| Breadboard            | 1        |
| Internet connection   | ✅       |

---

## 📲 Blynk Virtual Pins

| Data             | Virtual Pin |
|------------------|-------------|
| Temperature (°C) | V0          |
| Humidity (%)     | V1          |
| Soil Moisture (%)| V2          |

---

## 🔌 Wiring Diagram

### 🔹 DHT22 Sensor Connection

| DHT22 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO4     |

### 🔹 Soil Moisture Sensor Connection

| Soil Sensor Pin | ESP32 Pin |
|------------------|-----------|
| VCC              | 3.3V      |
| GND              | GND       |
| **AO** (Analog)  | **GPIO34** |
| DO (Optional)    | (GPIO35)  |

> ⚠️ Only AO is used for soil moisture percentage. DO can be used for threshold alerts if needed.

---

## 📷 Preview

### 📡 Blynk Dashboard:

| Widget | Description |
|--------|-------------|
| Gauge (V0) | Displays Temperature |
| Gauge (V1) | Displays Humidity |
| Gauge (V2) | Displays Soil Moisture |

_Add screenshots here:_
![Screenshot (74)](https://github.com/user-attachments/assets/8893b2ca-8fc6-4c4a-88dc-55704a097bc9)

![Screenshot (75)](https://github.com/user-attachments/assets/4b69a86c-b525-4a95-b598-56c584570bf0)


---

## 🔁 Code Overview

```cpp
#define DHTPIN 4
#define DHTTYPE DHT22
#define SOIL_PIN 34
