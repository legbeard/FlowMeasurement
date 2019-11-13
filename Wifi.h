#ifndef WIFI_
#define WIFI_

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


class Wifi{
  public:
  void init();
  int sendData(int maxFlow, int volumen, String rfid);

  private:
  void connect();
  
};


#endif
