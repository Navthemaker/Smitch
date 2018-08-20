#include <ESP8266WiFi.h>         
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "15f4e80dedea4ddbaba72697f161b7d6";

Servo servo;

BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}

void setup() {
    Serial.begin(9600);
    WiFiManager wifiManager;
    wifiManager.autoConnect();
    Serial.begin(9600);
    Blynk.config(auth);
    servo.attach(4);
}

void loop() {
  Blynk.run();
}
