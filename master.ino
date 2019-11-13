#include "Flow.h"
#include "RFID.h"


Flow flow;
RFID rfid;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   flow.init();
   rfid.init();
}

void loop() {
  String rfidString = rfid.getRfid();
  if (rfidString != ""){
    flow.measureFlow(rfidString);  
  }
  
}
