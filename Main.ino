#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define lightPin D1
#define fanPin D2

void setup() {
  pinMode(lightPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {
  digitalWrite(lightPin, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(fanPin, param.asInt());
}

void loop() {
  Blynk.run();
}
