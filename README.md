# Temperature and humidity sensor for zabbix using arduino #

# Wiring #

-Arduino Nano + ENC28j60
![Wiring Diagram](https://bitbucket.org/vitorveras/arduino/downloads/WiringDiagram.jpg)

-Arduino Uno + w5100 Ethernet shield

```
#!C

Change
#include <UIPEthernet.h>

to
#include <Ethernet.h>

```
 
# Zabbix Template #
[Download Zabbix 3.x Template](https://bitbucket.org/vitorveras/arduino/downloads/zbx_Template_Arduino_DHT_Sensor.xml)

# 3D Case #
