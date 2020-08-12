# mailboxninja-lora
Arduino based LoRa Version

**TODO**

* [ ] Enable Deep Sleep on Sender
* [x] Enable WiFi on Receiver 
* [x] Enable HTTP GET request on Receiver 
* [ ] Enable HTTPS GET request on Receiver 

**Parts List**

* [x] Wemos D1 Mini 
* [x] LILYGO TTGO 16340
* [x] 2x Pre-Soldered Lora RA-02 Boards

**Pinout**

Receiver (Wemos D1 Mini)
* 3.3V > 3.3V
* GND > GND (closest to 3.3V)
* RST > RST
* NSS > D8
* MOSI > D7
* MOSO > D6
* SCK > D5

Sender (LILYGO T-OI 16340 Rechargeable)
* 3.3V > 3.3V 
* GND > GND (closest to 3.3V)
* RST > RST
* NSS > D8
* MOSI > D7
* MOSO > D6
* SCK > D5
