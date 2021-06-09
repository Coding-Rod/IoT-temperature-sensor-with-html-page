#include <ESP8266WiFi.h>
// "port": "esp8266-9afbe0 at 192.168.0.4",
//SSID of your network
char ssid[] = "Fernandez";
//password of your WPA Network
char pass[] = "sparkie5919";

const int MAX_VAL = -20; // define maximum signal strength (in dBm)
const int MIN_VAL = -80; // define minimum signal strength (in dBm)

void setup() {
  Serial.begin(115200);
  Serial.println("ESP8266 WiFi Signal Strength Checker");

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(10);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // if you are connected, print out info about the connection:
  Serial.print("\nConnected to: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");

  pixels.begin(); // Initialize NeoPixel LEDs
}

void loop () {
  long rssi = WiFi.RSSI();
  Serial.print("RSSI: ");   // print the received signal strength:
  //Serial.println(rssi);
  int strength = map(rssi, MIN_VAL, MAX_VAL, 0, 4);
  
  delay(1000);
}