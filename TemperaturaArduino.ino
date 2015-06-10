#include <DHT.h>
#include <SPI.h>
#include <Ethernet.h>

#define DHTPIN 2     
#define DHTTYPE DHT11
#define MAX_CMD_LENGTH 25

DHT dht(DHTPIN, DHTTYPE);
      
//Rede
byte mac[] = { 0xDE, 0xDE, 0xBE, 0xEF, 0xFE, 0xED }; //Define o mac do arduino
IPAddress ip(192,168,0,251); //define o ip do arduino caso o dhcp no funcione
      
EthernetClient cliente;
EthernetServer servidor = EthernetServer(10050); //Zabbix Agent port
      
String cmd; //Recebe o comando do zabbix
boolean conectado=false;
int contador=0;
int portaPresenca=3;
      
void setup() {
  //iniciaSerial();
  iniciaRede();
       
  dht.begin();
        
  servidor.begin();
	
  pinMode(portaPresenca,INPUT);
 }
      
void loop() {    
  cliente = servidor.available();
  if(cliente == true){
    if(!conectado){
      cliente.flush();
      conectado=true;
    }
    if(cliente.available()>0){
      recebeComando(cliente.read());
    }
  }
  //imprimirTemperatura();
}
      
void iniciaSerial(){
  Serial.begin(9600);
  while(!Serial) { ; }
  Serial.println("Porta Serial Iniciada");  
}
      
void iniciaRede(){
  if (Ethernet.begin(mac) == 0) {
    //Serial.println("Falha ao pegar ip na rede");
    //Serial.println("Iniciando Configuracao manual da rede");
    Ethernet.begin(mac, ip);
  } 
  delay(1000);
  //Serial.println("Rede Iniciada");
}
      
void recebeComando(char c){
  if(cmd.length() == MAX_CMD_LENGTH) {
    cmd = "";
  }
  cmd += c;
  if(c == '\n') {
    if(cmd.length() > 2) {
      // remove \r and \n from the string
      cmd = cmd.substring(0,cmd.length() - 1);
      tratarComando();
    }
  }
}
      
void tratarComando(){
  if(cmd.equals("agent.ping")){
    servidor.println("1");
    //Serial.println("Ping: 1"); 
    cliente.stop();
  }       
  else if(cmd.equals("version")){
    servidor.println("1.1");
    cliente.stop();
  } 
  else if(cmd.equals("temp")){
    float t = dht.readTemperature();
    servidor.println(t);
    //Serial.print("Temperatura: ");  
    //Serial.println(t);
    cliente.stop();
    delay(2000);
  } 
  else if(cmd.equals("umid")){
    float h = dht.readHumidity();
    servidor.println(h);
    //Serial.print("Umidade: ");  
    //Serial.println(h);
    cliente.stop();
    delay(2000);
  }
  else if(cmd.equals("pres")){
    servidor.println(digitalRead(portaPresenca));
    cliente.stop();
  }
  else {
    servidor.println("ZBX_NOTSUPPORTED");
    cliente.stop();
   //Serial.println("ZBX_NOTSUPPORTED");
   //Serial.println(cmd);
  }
  cmd="";
}
