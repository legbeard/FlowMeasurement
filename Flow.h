
#ifndef FLOW_
#define FLOW_
#define pulse_ip D7

#include "Wifi.h"

class Flow{
  public:
    void init();
    void measureFlow(String rfid);
  private:
    Wifi wifi;
    int ontime,offtime,duty;
    float freq,period, flow, volume, maxFlow;
    long startTime;
    bool activeMeasurement;
  
};


#endif
