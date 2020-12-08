#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=2;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}

tmrpcm.setVolume(6);

//tmrpcm.play("test.wav");
tmrpcm.play("pop-c.wav");
//tmrpcm.play("r-l.wav");
//tmrpcm.play("m-l.wav");
// tmrpcm.play("b-l.wav");


}

void loop() {
  // put your main code here, to run repeatedly:
}
