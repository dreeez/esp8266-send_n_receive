#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Split_String.h>

ESP8266WiFiMulti WiFiMulti;
String status;
int checktime = (10 * 1000); // (Sec * 1000 = refresh time)
Split_String split;

const char* ssid     = "Send_Data_WLan";
const char* password = "SoMe78pAssW0r78D";

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
  Serial.println(); Serial.println();
  Serial.println(">> -------------------------");
  Serial.println(">> Receiver | Client");
  Serial.print(">> SSID: "); Serial.println(ssid);
  Serial.print(">> Password: "); Serial.println(password);
  Serial.println(">> Setup started!");
  Serial.println(">> -------------------------");
  Serial.println();
  Serial.println(">> |||||||||||||||||||||||||");
  Serial.println(); Serial.println();
  delay(1500);
}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    Serial.print(">> Call Server!");
    http.begin("http://192.168.4.1");
    Serial.println(" > Gather Data!");
    int httpCode = http.GET();
    String payload_esp = http.getString();
    Serial.print(">> Received data: ");
    Serial.println(payload_esp);
    // Split the received data in seperate Strings
    String payload1 = split.brakestring(payload_esp, '!', 0);
    String payload2 = split.brakestring(payload_esp, '!', 1);
    String payload3 = split.brakestring(payload_esp, '!', 2);
    String payload4 = split.brakestring(payload_esp, '!', 3);
    String payload5 = split.brakestring(payload_esp, '!', 4);
    String payload6 = split.brakestring(payload_esp, '!', 5);
    Serial.println(">> Splitted data:");
    Serial.print("  >> Value 1: "); Serial.println(payload1);
    Serial.print("  >> Value 2: "); Serial.println(payload2);
    Serial.print("  >> Value 3: "); Serial.println(payload3);
    Serial.print("  >> Value 4: "); Serial.println(payload4);
    Serial.print("  >> Value 5: "); Serial.println(payload5);
    Serial.print("  >> Value 6: "); Serial.println(payload6);
    http.end();
  }
  delay(checktime);
}
