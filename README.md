
# ESP32 Sensor Node with DHT22, LDR, and LED Indicators

## Overview
This project demonstrates a cost-effective IoT sensor node built using the **ESP32** microcontroller. It collects data from a **DHT22** sensor (temperature and humidity), an **LDR** (light level), and provides visual feedback via **LED indicators**. The data is served through a simple web interface, allowing real-time monitoring over Wi-Fi.

## Components Used
- **ESP32 Development Board**: Main microcontroller, providing Wi-Fi functionality and controlling sensors and LEDs.
- **DHT22 Sensor**: Measures temperature and humidity.
- **LDR (Light Dependent Resistor)**: Measures ambient light level.
- **LEDs**: Two LEDs for status indication.
  - LED1: Blinks to show the system is powered.
  - LED2: Lights up when the ESP32 is connected to Wi-Fi.

## Libraries Used
- `WiFi.h`: For ESP32 Wi-Fi functionality and access point setup.
- `DHT.h`: For interfacing with the DHT22 sensor.
- `WiFiServer.h`: For setting up a simple web server to serve the data.

## Features
- **Real-time Data**: Displays live temperature, humidity, and light level on a webpage.
- **Wi-Fi Enabled**: The ESP32 acts as a Wi-Fi access point, making the data accessible to any connected device.
- **LED Indicators**: Provides visual status of the system (power and Wi-Fi connection).

## Setup Instructions
1. **Wiring**:
   - Connect the **DHT22** data pin to **GPIO 4**.
   - Connect the **LDR** to **GPIO 34**.
   - Connect the LEDs to **GPIO 12** (LED1) and **GPIO 13** (LED2), with 220Ω resistors in series.
   
2. **Libraries**:
   - Install the **DHT sensor library** via the Arduino IDE Library Manager.

3. **Upload Code**:
   - Upload the provided code to the ESP32 board using the Arduino IDE.

4. **Access the Webpage**:
   - Once the ESP32 is powered on, connect to its Wi-Fi network.
   - Open a browser and enter the IP address of the ESP32 to view the sensor data.

## Expected Results
- The webpage will display temperature, humidity, and light data in real-time.
- The LEDs will blink or light up based on the system’s status.

## Conclusion
This simple ESP32-based sensor node offers an affordable solution for environmental monitoring. It can be used in various applications like agriculture or home automation where monitoring temperature, humidity, and light levels is essential.

## License
This project is open-source and free to use. Feel free to modify and adapt it for your own needs.

---

