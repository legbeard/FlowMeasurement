#include "RFID.h"

#define SS_PIN D4
#define RST_PIN D3
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void RFID::init()
{
    Serial.begin(9600); // Initiate a serial communication
    SPI.begin();        // Initiate  SPI bus
    mfrc522.PCD_Init(); // Initiate MFRC522
}

String RFID::getRfid()
{
    while (true)
    {
        if (!mfrc522.PICC_IsNewCardPresent())
        {
            return "";
        }
        // Select one of the cards
        if (!mfrc522.PICC_ReadCardSerial())
        {
            return "";
        }
        //Show UID on serial monitor
        String content = "";
        byte letter;
        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
            Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
            Serial.print(mfrc522.uid.uidByte[i], HEX);
            content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
            content.concat(String(mfrc522.uid.uidByte[i], HEX));
        }
        content.toUpperCase();
        Serial.println();
        if (content.substring(1) == "35 23 07 85") //change UID of the card that you want to give access
        {
            Serial.println();
            return "Søren";
        }
        else if (content.substring(1) == "66 E2 63 AC")
        {
            return "Anders";
        }
    }
    // Look for new cards
}
