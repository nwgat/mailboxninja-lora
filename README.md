# MailboxNinja-LoRa
Arduino based LoRa Version

| Name | Description | Status |
|-|-|-|
| NinjaSenderSleep | sender, deep sleep | Done |
| NinjaSenderSleepATmega | sender, deep sleep | Done |
| NinjaReceiverHook | http webhook  | Done|
| NinjaReceiverHookSecure | https webhook  | Work in Progress|
| NinjaReceiverHookMQTT | mqtt  | Work in Progress|
|-|-|-|
| LoRaSender | test sender code looped | | 
| LoRaReceiver  | test code | |

**TODO**

* [x] Enable Deep Sleep on Sender
* [x] Enable WiFi on Receiver 
* [x] Enable HTTP GET request on Receiver 
* [ ] Enable HTTPS GET request on Receiver 
* [x] Fix Phantom Packets
* [x] Fix interference from other lora near by

**Parts List**

* [x] [Wemos D1 Mini (NinjaReceiverHook)](https://www.aliexpress.com/item/32529101036.html) 
* [x] [LILYGO TTGO 16340 (NinjaSenderSleep)](https://www.aliexpress.com/item/4000429110448.html) 
* [x] [2x Wemos D1 Lora Shields](https://www.openhardware.io/view/394/Minimalist-LoRa-Ra-01-Shield-for-WeMos-D1-Mini)
* [x] [2x RA-01 + ANT](https://www.aliexpress.com/item/4000086980747.html)
* [x] [Reed Door Sensor](https://www.aliexpress.com/item/10000007677307.html?_mMdt3V9)

**Reed Door Sensor**

* Solder the reed door sensor leads to RST and GND on the TTGO

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
