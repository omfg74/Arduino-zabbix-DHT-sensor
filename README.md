# Temperature and humidity sensor for zabbix using arduino #

# Wiring #

![Arduino Nano + ENC28j60](https://bitbucket.org/vitorveras/zabbix-dht-sensor-using-arduino/downloads/WiringDiagramNano.jpg)

- Arduino Nano + ENC28j60


![Arduino Uno + Ethernet shield](https://bitbucket.org/vitorveras/zabbix-dht-sensor-using-arduino/downloads/WiringDiagramUno.jpg)

- Arduino Uno + w5100 Ethernet shield


To use this code with Arduino uno and ethernet shild, change ethernet lib from:
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
[Download Zabbix 3.x Template](https://bitbucket.org/vitorveras/zabbix-dht-sensor-using-arduino/downloads/zbx_Template_Arduino_DHT_Sensor.xml)

# 3D Case #

![3D Case](https://bitbucket.org/vitorveras/zabbix-dht-sensor-using-arduino/downloads/3D_printed_case.jpg)

[Thingverse link](https://www.thingiverse.com/thing:2761584)
