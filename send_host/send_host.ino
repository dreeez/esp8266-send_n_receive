#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid     = "Send_Data_WLan";
const char* password = "SoMe78pAssW0r78D";
IPAddress ip(192,168,4,1);
IPAddress gateway(192,168,1,254);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

String header;
unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup() {
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  WiFi.config(ip, gateway, subnet);
  server.begin();
  Serial.println(); Serial.println();
  Serial.println(">> -------------------------");
  Serial.println(">> Sender | Host");
  Serial.print(">> SSID: "); Serial.println(ssid);
  Serial.print(">> Password: "); Serial.println(password);
  Serial.println(">> Setup started!");
  Serial.println(">> -------------------------");
  Serial.println();
  Serial.println(">> |||||||||||||||||||||||||");
  Serial.println(); Serial.println();
  delay(1500);
}

void loop(){
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {                             
    Serial.print(">> Client connected! ");          
    String currentLine = ""; // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            Serial.print("> Sending data to client!");
            client.print("value1");
            client.print("!"); // Space the values
            client.print("value2");
            client.print("!"); // Space the values
            client.print("value3");
            client.print("!"); // Space the values
            client.print("value4");
            client.print("!"); // Space the values
            client.print("value5");
            client.print("!"); // Space the values
            client.println("value6");
            break; // Break out while in the loop
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println(" > Stopped!");
    Serial.println();
    delay(1000);
  }
}
