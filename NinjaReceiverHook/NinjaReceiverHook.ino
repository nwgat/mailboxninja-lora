// https://nwgat.ninja
// https://github.com/nwgat/mailboxninja-lora

#include <Arduino.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

// Fingerprint for demo URL, expires on June 2, 2021, needs to be updated well before this date
// const uint8_t fingerprint[20] = {0x40, 0xaf, 0x00, 0x6b, 0xec, 0x90, 0x22, 0x41, 0x8e, 0xa3, 0xad, 0xfa, 0x1a, 0xe8, 0x25, 0x41, 0x1d, 0x1a, 0x54, 0xb3};

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
  WiFiMulti.addAP("wifi", "wifipassword");

  // LoRa
  #define ss 15
  //#define rst 32
  #define rst 16
  
  LoRa.setPins(ss, rst);
  LoRa.setTxPower(20);
  LoRa.setSyncWord(0xF3);
  
  Serial.println("LoRa: OK");

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa: Fail!");
    while (1);
  }
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)); {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    // client->setFingerprint(fingerprint);
    client->setInsecure();

    // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    HTTPClient http;
    http.begin("http://nwgat.ninja/webhook");
    http.GET();
    Serial.print("webhook: OK | ");
    delay(4000);

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print(" | RSSI: ");
    Serial.println(LoRa.packetRssi());
  }

  }
}
