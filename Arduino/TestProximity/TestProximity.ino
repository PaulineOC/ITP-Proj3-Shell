#include <Wire.h>
#include "Adafruit_VCNL4010.h"
#include "pitches.h"

Adafruit_VCNL4010 vcnl;

//Analog
int FSRPin = A0;

//Digital
int speakerPin = 8;

// extra safety net boolean to make sure the speaker doesn't play incorrectly and doesn't break with noTone()
boolean speakerIsPlaying; 

//Impending doom tune
int melody[] = {
NOTE_A3, NOTE_A3,NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_E4,NOTE_E4,NOTE_E4,NOTE_F4,NOTE_C4, NOTE_GS3,NOTE_F3,NOTE_C4,NOTE_A3,
};

int noteDurations[] = {4,4,4,8,8,4,8,8,2,4,4,4,8,8,4,8,8,2};

// Stages
int currState;
int prevState = LOW;
int prevWeight;
int currWeight;
int weightThreshold = 18;

void setup() {
  Serial.begin(9600);


  // Proximity sensor
  if (! vcnl.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.println("Found VCNL4010");
  // Speaker
  speakerIsPlaying = false;
  
}

void loop() {
   Serial.print("Proximity: "); Serial.println(vcnl.readProximity());
   delay(1000);
    // playTune();
}

void playTune(){
  for (int thisNote = 0; thisNote < 18; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    //pause for the note's duration plus 30 ms:
    delay(noteDuration +50);
  }
}
