
#ifndef RFIDa_
#define RFIDa_

#include <SPI.h>
#include <MFRC522.h>

class RFID
{
public:
  void init();
  String getRfid();

private:
};
#endif
