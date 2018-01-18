#include <UIPEthernet.h>
#include <DHT.h>

#define MACADDRESS 0xDE, 0xDE, 0xBE, 0xEF, 0xFE, 0xEE 
#define IP 192,168,0,250
#define LISTENPORT 10050
String hostname = "nuinf-temp01";

#define DHTPIN 2
#define DHTYPE DHT11

String items[] = { "agent.ping", "agent.hostname", "agent.version", "dht.temperature", "dht.humidity", "dht.type", "product.version" };
int itemsSize = 7; 

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

        switch(findId(msg)){
          case 0:
            server.println("1");
            break;
          case 1:
            server.println(hostname);
            break;
          case 2:
            server.println("3.0");
            break;
          case 3:
            server.println(dht.readTemperature());
            break;
          case 4:
            server.println(dht.readHumidity());
            break;
          case 5:
            server.println(DHTYPE);
            break;
          case 6:
            server.println("2.0");
            break;
          default:
            server.println("ZBX_NOTSUPPORTED");
        }

        client.stop();
        msg="";
      }else {
        msg += thisChar;  
      }
    }
  }
}

int findId(String text) {
  int returnValue=-1;
  for (int i=0; i < itemsSize; i++){
    if(items[i].equals(text)){
      returnValue = i; 
    }
  }
  return returnValue;
}
