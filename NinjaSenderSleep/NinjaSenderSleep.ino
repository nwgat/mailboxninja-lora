// https://nwgat.ninja
// https://github.com/nwgat/mailboxninja-lora

#include <SPI.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  // while (!Serial);  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // LoRa
  #define ss 15
  #define rst 32
  // #define rst 16

  LoRa.setPins(ss, rst);
  LoRa.setSyncWord(0xF3);
  
  Serial.println("LoRa: OK");

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa: Fail!");
    while (1);
  }
  Serial.println("Sending packet: ");

  // send packet
  LoRa.beginPacket();
  LoRa.print("c");
  LoRa.endPacket();

  // deep sleep
  Serial.println("Going deep sleeping... in 15 sec");
  ESP.deepSleep(15e6); 
}

void loop() {

}
