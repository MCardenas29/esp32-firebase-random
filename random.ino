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
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(100);
  }
  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());  
  // Get time
  timeClient.begin();
  timeClient.setTimeOffset(GMT_OFFSET * -6);
  timeClient.setUpdateInterval(1);

  randomSeed(timeClient.getEpochTime());
}

void loop() {
  timeClient.update();
  long currentTime = timeClient.getEpochTime();
  double num = random(0, 1000) / 100.0;
  Serial.println(num);
  fb.setFloat("flujo/" + String(currentTime), num);
  delay(1000);
}
