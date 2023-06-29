#include <ESP8266WiFi.h>
//PAGINA HTML
#include "pagina.h"

const char* ssid = "casa.exe";
const char* password = "CASA896969nil";

//IP FIXO PARA O NODEMCU 
IPAddress ip(192,168,0,144);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

#define led_1 4
#define led_2 5

bool led1Status = true;
bool led2Status = true;
//String StatusLED1 = "";
//String StatusLED2 = "";

// DECLARAÇÃO DE FUNÇÕES
void conectaWifi();
void requisicao(String);


void conectaWifi(){
WiFi.begin(ssid, password);
WiFi.config(ip, gateway, subnet);

while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 Serial.println("");
 Serial.print("Conectado a rede sem fio ");
 Serial.println(ssid);
 server.begin();
 Serial.println("Servidor Iniciado");
 
 Serial.print("IP para se conectar: ");
 Serial.print("http://");
 Serial.println(WiFi.localIP());

 Serial.println("");
 Serial.println("");
 Serial.print("conectando a: ");
 Serial.print(ssid);
}

 void requisicao(String request){
 
 if(request.indexOf("/LED=ON") != -1)
 {
  led1Status = true;
  digitalWrite(led_1, led1Status);
  //StatusLED1 = "Lâmpada 1 - Ligada";
  //Serial.println(StatusLED1);
 }
 
  else if(request.indexOf("/LED=OFF") != -1)
 {
  led1Status = false;
  digitalWrite(led_1, led1Status);
  //StatusLED1 = "Lâmpada 1 - Desligada";
  //Serial.println(StatusLED1);
 }
  else if(request.indexOf("/LED2=ON") != -1)
 {
  led2Status = true;
  digitalWrite(led_2, led2Status);
  //StatusLED2 = "Lâmpada 2 - Ligada";
  //Serial.println(StatusLED2);
 }
 
  else if(request.indexOf("/LED2=OFF") != -1)
 {
  led2Status = false;
  digitalWrite(led_2, led2Status);
  //StatusLED2 = "Lâmpada 2 - Desligada";
  //Serial.println(StatusLED2);
 }
 }

// ***************** INÍCIO DO SETUP *************************

void setup(){

Serial.begin(115200);
delay(10);

pinMode(LED_BUILTIN, OUTPUT);
pinMode(led_1, OUTPUT);
pinMode(led_2, OUTPUT);

digitalWrite(led_1, !led1Status);
digitalWrite(led_2, !led2Status);

conectaWifi();
}

// ***************** FIM DO SETUP ***************************

// ***************** INÍCIO DO LOOP *************************

 void loop(){
 
 WiFiClient client = server.available();
 if (!client){
 return;
 }
 Serial.println("Novo cliente");
 while(!client.available()){
 delay(1);
}
 
String request = client.readStringUntil('\r');
requisicao(request);
Serial.println(request);
 
 client.flush();
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html"); 
 client.println("");
 client.println(pagina);
 
 
 client.println("<section>");
 client.println("<div class='item-head'>");
 client.println("<div class='titulo'>LED 1</div>");
 led1Status ? client.println("<div class='estado on'>on</div>") : client.println("<div class='estado off'>off</div>");
 client.println("</div>");
 client.println("<div class='acoes'>");
 client.println("<a href='/LED=ON' class='ligar'>ligar</a>");
 client.println("<a href='/LED=OFF' class='desligar'>desligar</a>");
 client.println("</div>");
 client.println("</section>");


 client.println("<section>");
 client.println("<div class='item-head'>");
 client.println("<div class='titulo'>LED 2</div>");
 led2Status ? client.println("<div class='estado on'>on</div>") : client.println("<div class='estado off'>off</div>");
 client.println("</div>");
 client.println("<div class='acoes'>");
 client.println("<a href='/LED2=ON' class='ligar'>ligar</a>");
 client.println("<a href='/LED2=OFF' class='desligar'>desligar</a>");
 client.println("</div>");
 client.println("</section>");
 
client.println("<section>");
client.println("<div class='item-head'>");
client.println("<div class='titulo'>Temperatura Ambiente</div>");
client.println("</div>");
client.println("<div class='acoes'>");
client.println("<div class='leitura'>23°C</div>");
client.println("</div>");
client.println("</section>");
 
 client.println(rodape);
 delay(1);
 
 Serial.println("Cliente desconectado");
 Serial.println("");
 
 request = "";
 }

// ***************** FIM DO LOOP ***************************
 
