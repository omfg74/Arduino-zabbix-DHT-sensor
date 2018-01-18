# Temperature and humidity sensor for zabbix using arduino #

# Wiring #

- Arduino Nano + ENC28j60
![Wiring Diagram](https://bitbucket.org/vitorveras/arduino/downloads/WiringDiagram.jpg)

- Arduino Uno + w5100 Ethernet shield

Change ethernet lib from:
```
#!C

#include <UIPEthernet.h>
```
To:
```
#!C

#include <Ethernet.h>
```
 
# Zabbix Template #
[Download Zabbix 3.x Template](https://bitbucket.org/vitorveras/arduino/downloads/zbx_Template_Arduino_DHT_Sensor.xml)

# 3D Case #
