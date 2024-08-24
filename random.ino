#include <WiFi.h>
#include <Firebase.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
// Define SSID, PASSWORD and the firebase REFERENCE_URL in "secrets.h"
#include "secrets.h"

#define GMT_OFFSET 3600
Firebase fb(REFERENCE_URL);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup() {
  randomSeed(76442352);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());  
  // Get time
  timeClient.begin();
  timeClient.setTimeOffset(GMT_OFFSET * -6);
  timeClient.setUpdateInterval(1);
}

void loop() {
  timeClient.update();
  String currentTime = timeClient.getFormattedTime();
  double num = random(0, 1000) / 100.0;
  Serial.println(num);
  fb.setFloat("flujo/" + currentTime, num);
  delay(1000);
}
