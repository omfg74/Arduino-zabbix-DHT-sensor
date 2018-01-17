#include <UIPEthernet.h>
#include <DHT.h>

#define MACADDRESS 0xDE, 0xDE, 0xBE, 0xEF, 0xFE, 0xEE 
#define IP 192,168,0,250
#define LISTENPORT 10050

#define DHTPIN 2
#define DHTYPE DHT11


EthernetServer server = EthernetServer(LISTENPORT);

DHT dht(DHTPIN,DHTYPE);

String msg ="";
void setup() {
  //NETWORK
  uint8_t mac[6] = {MACADDRESS};
  uint8_t ip[4] = {IP};

  Ethernet.begin(mac,ip);
  server.begin();

  //DHT Sensor
  dht.begin();
  
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    if (client.available() > 0) {
      char thisChar = client.read();
      if (thisChar == '\n') {

        if(msg.equals("agent.ping") > 0) {
          server.println("1");           
        }
         if(msg.equals("temp") > 0) {
          server.println(dht.readTemperature());           
        }
         if(msg.equals("umid") > 0) {
          server.println(dht.readHumidity());           
        }
         if(msg.equals("version") > 0) {
          server.println("2.0");           
        }
        
        client.stop();
        
        msg="";
      }else {
        msg += thisChar;  
      }
    }
  }
}