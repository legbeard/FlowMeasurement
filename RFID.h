
#ifndef RFID_
#define RFID_

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D4
#define RST_PIN D3
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

class RFID
{
public:
  void init();
  String getRfid();

private:
  
  
};

#endif
