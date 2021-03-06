// (c) Michael Schoeffler 2014, http://www.mschoeffler.de

#include "SPI.h" // SPI library
#include "MFRC522.h" // RFID library (https://github.com/miguelbalboa/rfid)
#include "SD.h" // SD card library

#include <Wire.h>
#include "Adafruit_VCNL4010.h"

Adafruit_VCNL4010 vcnl;


const int pinRST = 9;
const int pinSDA = 10;


byte rBlue[] = {213, 7, 90, 211};
byte rOrange[] = {55, 207, 13, 99};
byte rBlack[] = {196, 140, 206, 156};

boolean isBlue = true;
boolean isOrange = true;
boolean isBlack = true;

int currTagColor = -1;

char *colorMessages[] = {
  "BLUE",
  "ORANGE",
  "BLACK"
};


// Photocell
int photoCellPin = A0;
int photoCellReading;
int photoCellThreshold = 35;
int photoCellLightThreshold = 45;

// Tilt switch
int isUpright = HIGH;
int tiltPin = 7;

int prevTime;
int currTime;

MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino

void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
}


void loop() {

  // Delays the photocell reading
  if(millis() % 50 == 0 ){
      photoCellReading = analogRead(photoCellPin);
      //Serial.println(photoCellReading);
  }

//  int tiltReading = digitalRead(tiltPin);
//  Serial.println(tiltReading);
//  

  // CHECK: 
  // if  RFID tag/card is present ) PICC = Proximity Integrated Circuit Card
  // if RFID tag/card was read
  // if shell is against ear = photoCell reading is darker than 30 && tiltSwitch
  
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() && photoCellReading < photoCellThreshold && isUpright == HIGH ) {
    
      int colorTag = determineColorTag();
      if(colorTag != currTagColor && colorTag >= 0 ){
        // Send the message to p5
        Serial.println(colorMessages[colorTag]);
        currTagColor = colorTag;
      }

  }
}



int determineColorTag(){
  isBlue = isOrange = isBlack = true;
  for (byte i = 0; i < mfrc522.uid.size; ++i) {
    isBlue &= rBlue[i] == mfrc522.uid.uidByte[i];
    isOrange &= rOrange[i] == mfrc522.uid.uidByte[i];
    isBlack  &= rBlack[i] == mfrc522.uid.uidByte[i];
 }
 
 if(isBlue){
    return 0;

 }
 else if(isOrange){
    return 1;
 }
 else if(isBlack){
  return  2;
 }
 
 else{
  return -1;
 }
     
}
