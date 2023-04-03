#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = D3;
constexpr uint8_t SS_PIN = D4;

MFRC522 rfid(SS_PIN,RST_PIN);
MFRC522 :: MIFARE_Key key;

String tag;

void setup(){
   Serial.begin(9600);
   SPI.begin();
   rfid.PCD_Init(),
   pinMode(D8,OUTPUT);

   void loop(){
     if(I refid.PICC_IsNewCardPresent())
     return ;
     if(rfid.PICC_ReadCardSerial()){
     for(byte i = 0;i<4;i++){
     tag += rfid.uid.uidByte[i];
    }
  
  Serail.println(tag);
  (tag == "11521023130" || "35622263"),
   Serial.println("Access Granted !!");
   digitalWrite(D8,HIGH),
   delay(100);
   digitalWrite(D8,LOW),
   delay(100);
   digitalWrite(D8,HIGH),
   delay(100);
   digitalWrite(D8,LOW),
   delay(100);
   digitalWrite(D8,HIGH),
   delay(100);
   digitalWrite(D8,LOW),
   delay(100);
   } else{
       Serial.println("Access Denied !!");
       digitalWrite (D8,HIGH);
       delay(2000);
       digitalWrite (D8,LOW);   
       }
 
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCryptoI();
    } 
   }
