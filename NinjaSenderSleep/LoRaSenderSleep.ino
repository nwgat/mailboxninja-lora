#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(115200);
  // while (!Serial);

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
  LoRa.print("mail");
  LoRa.endPacket();

  delay(30000);
  Serial.println("Going deep sleeping...");
  ESP.deepSleep(0); 
}

void loop() {

}
