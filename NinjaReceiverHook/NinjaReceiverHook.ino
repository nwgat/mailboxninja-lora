// https://nwgat.ninja
// https://github.com/nwgat/mailboxninja-lora

#include <Arduino.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
String inData;

ESP8266WiFiMulti WiFiMulti;
void setup() {

  // WiFi
  Serial.begin(115200);
  while (!Serial);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("wifi_network", "wifi_password");

  // LoRa
  #define ss 15
  //#define rst 32
  #define rst 16
  
  LoRa.setPins(ss, rst);
  
  Serial.println("LoRa: OK");

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa: fail!");
    while (1);
  }
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)); {

    // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {

     // read packet
  while(LoRa.available() > 0 ){
    String str = LoRa.readString();
    if(str.indexOf("abc") > -1){
     // hook
     HTTPClient http;
     http.begin("http://example.com/webhook");
     http.GET();
     inData = "abc"; // Clear recieved buffer
     Serial.print("webhook: OK | "); 
     Serial.println("identified");} 
    else{
      Serial.println("unknown");

        }

      }
    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print(" RSSI: ");
    Serial.println(LoRa.packetRssi());
  }
  }
 }
