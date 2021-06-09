//===================
//ESP8266 Web Server
//===================
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
#include "functions.h"
//---------------------------------
const char* ssid     = "Fernandez";
const char* password = "sparkie5919";
//======================================================================
void setup()
{
  Serial.begin(115200);
  pinMode(D1, INPUT); pinMode(D2, OUTPUT); digitalWrite(D2, LOW);
  
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");
  while (WiFi.status() != WL_CONNECTED) {delay(500); Serial.print(".");}
  Serial.println("");
  Serial.println("ESP8266 Webpage");
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", handleRoot);
  server.on("/pot", pot);
  server.on("/button", button);
  server.on("/led", led);
  
  server.begin();
  Serial.println("HTTP server started");
}
//======================================================================
void loop()
{server.handleClient();}
