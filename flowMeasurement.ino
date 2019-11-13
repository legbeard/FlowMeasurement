#include "Flow.h"


Flow flow;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   flow.init();
}

void loop() {
  //String rfid = getrfid();
  String rfid = "Hej med dig!";
  flow.measureFlow(rfid);

}
