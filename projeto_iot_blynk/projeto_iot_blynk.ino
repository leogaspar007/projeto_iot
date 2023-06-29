#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] ="Y7a46tH2TBobzBblFIACKs6KyD6nwtyJ";

char ssid[] = "heloisav";
char pass[] = "heloeleo1234";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop(){
  Blynk.run();
}