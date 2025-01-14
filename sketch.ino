#include <WiFi.h>
#include <DHT.h>

// DHT22 Configuration
#define DHTPIN 4        // SDA pin connected to GPIO 4
#define DHTTYPE DHT22   // DHT22 sensor type
DHT dht(DHTPIN, DHTTYPE);

// LDR Configuration
#define LDR_PIN 34      // AO pin connected to GPIO 34

// LED Pins
#define LED1_PIN 12     // LED for power on (blinking)
#define LED2_PIN 13     // LED for Wi-Fi connection

// Wi-Fi AP Configuration
const char* ssid = "ESP32_Sensor_AP";
const char* password = "12345678";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // Initialize DHT sensor
  dht.begin();
  Serial.println("Sensor Node Prototype Initialized!");

  // Configure LED pins as output
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // Configure Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.println("Access Point Started!");
  Serial.print("AP Name: ");
  Serial.println(ssid);
  Serial.print("AP Password: ");
  Serial.println(password);
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // Start the web server
  server.begin();
  Serial.println("Web Server started.");
}

void loop() {
  // Blink the first LED (LED1) every 500ms
  digitalWrite(LED1_PIN, HIGH);
  delay(500);
  digitalWrite(LED1_PIN, LOW);
  delay(500);

  // Read data from DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read data from LDR
  int lightLevel = analogRead(LDR_PIN);

  // Print sensor data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Light Level (LDR): ");
  Serial.println(lightLevel);

  // Handle incoming client connections
  WiFiClient client = server.available();
  if (client) {
    // Turn on LED2 when Wi-Fi is connected
    digitalWrite(LED2_PIN, HIGH);
    Serial.println("New Client Connected");
    String request = client.readStringUntil('\r');
    Serial.println("Client Request: " + request);
    client.flush();

    // Create a simple web page
    String html = "<!DOCTYPE html><html>";
    html += "<head><title>ESP32 Sensor Node</title></head>";
    html += "<body style='font-family: Arial; text-align: center;'>";
    html += "<h1>ESP32 Sensor Node</h1>";
    html += "<p><strong>Temperature:</strong> " + String(temperature, 1) + " &deg;C</p>";
    html += "<p><strong>Humidity:</strong> " + String(humidity, 1) + " %</p>";
    html += "<p><strong>Light Level:</strong> " + String(lightLevel) + "</p>";
    html += "</body></html>";

    // Send the web page to the client
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println(html);
    client.stop();
    Serial.println("Client Disconnected");

    // Turn off LED2 when the client disconnects
    digitalWrite(LED2_PIN, LOW);
  }

  // Delay for 2 seconds before the next reading
  delay(2000);
}
