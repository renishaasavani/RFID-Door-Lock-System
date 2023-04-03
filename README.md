# Door-Locker
Door Locker system

This code is an Arduino program for an RFID reader using the MFRC522 library. The program reads the ID of a card presented to the reader and compares it with two specific IDs. If the ID matches either of the two, access is granted by turning on an LED connected to the D8 pin, and a message is printed on the serial monitor saying "Access Granted!!". If the ID does not match either of the two, access is denied, the LED connected to the D8 pin is turned on for 2 seconds, and a message is printed on the serial monitor saying "Access Denied!!".

Here is a detailed explanation of the code:

#include <SPI.h>
#include <MFRC522.h>

The first two lines include the necessary libraries for the program. The SPI library is required for communication with the MFRC522 chip, and the MFRC522 library provides functions for working with RFID cards.


constexpr uint8_t RST_PIN = D3;
constexpr uint8_t SS_PIN = D4;

These two lines define the reset (RST) and slave select (SS) pins of the MFRC522 chip. These pins are connected to digital pins D3 and D4 of the Arduino, respectively.


MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

These two lines declare an instance of the MFRC522 class called 'rfid' and a variable of type MFRC522::MIFARE_Key called 'key'. The MIFARE_Key data type is used to store the authentication key for the RFID card.


String tag;

This line declares a String variable called 'tag' that will be used to store the UID of the RFID card.


void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(D8, OUTPUT);
}

The setup() function is called once when the Arduino is powered on or reset. This function initializes the serial communication at a baud rate of 9600, initializes the SPI communication, initializes the MFRC522 chip, and sets the D8 pin as an output for the LED.


void loop() {
  if (!rfid.PICC_IsNewCardPresent())
    return;

The loop() function is called repeatedly while the Arduino is powered on. This if statement checks if a new card has been presented to the reader by calling the PICC_IsNewCardPresent() function of the MFRC522 library. If no card is present, the function returns and the loop starts again.


if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    if (tag == "11521023130" || tag == "35622263") {
      Serial.println("Access Granted!!");
      digitalWrite(D8, HIGH);
      delay(100);
      digitalWrite(D8, LOW);
      delay(100);
      digitalWrite(D8, HIGH);
      delay(100);
      digitalWrite(D8, LOW);
      delay(100);
      digitalWrite(D8, HIGH);
      delay(100);
      digitalWrite(D8, LOW);
      delay(100);
    } else {
      Serial.println("Access Denied!!");
      digitalWrite(D8, HIGH);
      delay(2000);
      digitalWrite(D8, LOW);
    }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}

This block of code is executed when a card is present. It reads the UID of the card using the PICC.

# We used RFID in this project 

The reason why RFID is used in this project is that it provides a secure and convenient way of identifying and authenticating individuals, objects or devices. The RFID technology enables wireless communication between the RFID reader and the RFID tag, which contains an integrated circuit and an antenna. The RFID reader sends a signal to the RFID tag, which responds with its unique identifier (UID). The RFID reader can then use this UID to identify and authenticate the RFID tag or the object/device it is attached to.

In this project, the RFID reader is used to identify and authenticate a specific RFID tag. If the UID of the presented RFID tag matches one of the two predefined UIDs in the program, access is granted by turning on an LED connected to the Arduino board. If the UID does not match, access is denied, and an LED connected to the Arduino board is turned on for 2 seconds. This type of access control system can be used in various applications, such as door access control, inventory management, attendance tracking, and so on.

Overall, RFID technology is a secure and reliable way of identifying and authenticating objects, devices or individuals, making it a suitable choice for access control and other related applications.

# Output



https://user-images.githubusercontent.com/63333592/229577626-04b28aa1-c01b-436a-a659-219ae6fb3604.mp4



