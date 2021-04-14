#include <SPI.h>
#include <LoRa.h>
#include <avr/sleep.h>      // powerdown library

void setup() {
  Serial.begin(115200);
  while (!Serial);  
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {

  LoRa.beginPacket();
  LoRa.print("\nabc");
  LoRa.endPacket();
  LoRa.end();
  LoRa.sleep();

  delay(50);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // setting up for sleep ...
  sleep_enable();                       // setting up for sleep ...
  ADCSRA &= ~(1 << ADEN);    // Disable ADC
  PRR = 0xFF;   // Power down functions
  sleep_mode();                         // now go to Sleep and waits
}
