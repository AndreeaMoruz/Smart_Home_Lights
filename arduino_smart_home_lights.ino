
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>


#include <TFT.h>

#include <SPI.h>

#define RED 0xF800

#define cs 4
#define dc 3
#define rst 2

TFT TFTscreen = TFT(cs,dc,rst);

SoftwareSerial Bluetooth(0,1);
char Data;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  Bluetooth.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  TFTscreen.begin();

  TFTscreen.setTextSize(2);
  TFTscreen.background(0,0,0);
  TFTscreen.stroke(255,255,255);
  TFTscreen.text("SMART HOME",10,40);
  TFTscreen.text("LIGHTS",40,65);

    
  TFTscreen.setTextSize(0.5);

  while(1) {
      if(Bluetooth.available()) {
          Data=Bluetooth.read();
          // LED 1 ON
          if (Data==('0')) {
              digitalWrite(5,1);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumina sufragerie ON",10,20);

          }
          // LED 1 OFF
          if (Data==('1')) {
              digitalWrite(5,0);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumina sufragerie OFF",10,20);

          }
          // LED 2 ON
          if (Data==('2')) {
              digitalWrite(6,1);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumina baie ON",10,20);

          }
          // LED 2 OFF
          if (Data==('3')) {
              digitalWrite(6,0);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumina baie OFF",10,20);


          }
          // LED 3 ON
          if (Data==('4')) {
              digitalWrite(7,1);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumina pod ON",10,20);

          }
          // LED 3 OFF
          if (Data==('5')) {
              digitalWrite(7,0);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumina pod OFF",10,20);


          }
          // ALL LEDs ON
          if (Data==('a')) {
              digitalWrite(5,1);
              digitalWrite(6,1);
              digitalWrite(7,1);
              digitalWrite(8,1);
              digitalWrite(9,1);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("All lights ON",10,20);

          }
          // ALL LEDs OFF
          if (Data==('b')) {
              digitalWrite(5,0);
              digitalWrite(6,0);
              digitalWrite(7,0);
              digitalWrite(8,0);
              digitalWrite(9,0);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("All lights OFF",10,20);

          }
          // LED 4 On
          if (Data==('6')) {
              digitalWrite(8,1);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumini bucatarie ON",10,20);

          }
          // LED 4 OFF
          if (Data==('7')) {
              digitalWrite(8,0);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumini bucatarie OFF",10,20);

          }
          // LED 5 ON
          if (Data==('8')) {
              digitalWrite(9,1);
               TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumini garaj ON",10,20);

          }
          // LED 5 OFF
          if (Data==('9')) {
              digitalWrite(9,0);
              TFTscreen.background(0,0,0);
              TFTscreen.stroke(255,255,255);
              TFTscreen.text("Lumini garaj OFF",10,20);


          }

      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}
