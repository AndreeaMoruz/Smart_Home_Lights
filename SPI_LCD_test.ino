#include <TFT_eSPI.h>

#include <TFT.h>

#include <SPI.h>



#define cs 4
#define dc 3
#define rst 2

TFT TFTscreen = TFT(cs,dc,rst);

void setup() {
  // put your setup code here, to run once:
TFTscreen.begin();
TFTscreen.background(0,0,0);
TFTscreen.stroke(255,255,255);
TFTscreen.setTextSize(0.5);

TFTscreen.text("IL IUBESC PE STEFANEL",10,20);


}

void loop() {
  // put your main code here, to run repeatedly:

}
