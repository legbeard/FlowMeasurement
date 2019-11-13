#include "Wifi.h"


void Wifi::connect(){
  WiFi.begin("Annes iPhone", "33333333");
  pinMode(LED_BUILTIN, OUTPUT);
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_BUILTIN, LOW);
    yield();
  }
  digitalWrite(LED_BUILTIN, HIGH);
}

void Wifi::init(){
  connect(); 
}

int Wifi::sendData(int maxFlow, int volumen, String rfid){
  HTTPClient http;
  http.begin("http://172.20.10.4:5000/shitposts");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  String postData = "rfid=" + rfid + "&flow=" + maxFlow + "&volumen=" + volumen;
  
  int httpCode = http.POST(postData);
  http.end();
  return httpCode;
}
