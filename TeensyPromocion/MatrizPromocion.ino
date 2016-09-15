
#include <FastLED.h>
#include "font8x8_basic.h"
#include "Nombres.h"
#define NUM_LEDS 512
#define DATA_PIN 17
#define MATRIX_OFFSET 0
char Data[6];
const int reversed[8] = {7,6,5,4,3,2,1,0};
String Nombre;
void bottomFiveScrollLeft(char Data[6], int pos, bool negative);
void fillMatrix(CRGB color, unsigned int fromX = 0, unsigned int fromY = 0,
unsigned int toX=31,unsigned int toY=15);
CHSV LetterColor(0,255,255);
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  Nombre.reserve(12);
  random16_add_entropy(analogRead(0));
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(30);
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int index;
  if(Serial.available()){
    index = Serial.parseInt();
    while(Serial.available()){
      Serial.read();  
    }
    mostrarNombre(index,false);
    mostrarNombre(index,false);
  } else {
    index = random8(54);
    //Serial.println(index);
    mostrarNombre(index,true);
    mostrarNombre(index, true);
  }
  //FastLED.show();
  //leftFade();
  //delay(300);
}

void info(bool negative){
  const String cadena1 = "Promo";
  const String cadena2 = "57";
  char data[6]
  int i = 0;
  for(int x = 0;x<6;x++){
    data2[x] = cadena2.charAt(x);
  }
  while(i<3){
    
  } 
}

void leftFade(CRGB color = CRGB::White){
  for(int x=31;x>=0;x--){
    fadeToBlackMatrix(20);
    for(int y = 0;y<16;y++){
      leds[ Matrix(x,y) ] = color;
    }
    FastLED.show();
    delay(100);
  }
}

void fadeToBlackMatrix(int number){
  fadeToBlackBy(&leds[MATRIX_OFFSET],512,number);
}

void mostrarNombre(int index, bool negative){
  Nombre = String(Nombres[index]);
  Nombre.trim();
  for(unsigned int i = 0;i<Nombre.length()-4;i++){
    Data[0] = Nombre.charAt(i);
    Data[1] = Nombre.charAt(i+1);
    Data[2] = Nombre.charAt(i+2);
    Data[3] = Nombre.charAt(i+3);
    Data[4] = Nombre.charAt(i+4);
    for(unsigned int j = 0;j<9;j++){
      upperFiveScrollLeft(" Ing ",4,negative);
      bottomFiveScrollLeft(Data,j, negative);
      LetterColor.hue++;
      FastLED.show();
      delay(50);
    }
  }
  delay(200);
  for(unsigned int i = 0;i<Nombre.length()-4;i++){
    char Data[6];
    Data[4] = Nombre.charAt(Nombre.length()-1-i);
    Data[3] = Nombre.charAt(Nombre.length()-2-i);
    Data[2] = Nombre.charAt(Nombre.length()-3-i);
    Data[1] = Nombre.charAt(Nombre.length()-4-i);
    Data[0] = Nombre.charAt(Nombre.length()-5-i);
    for(int j = 8;j>=0;j--){
      upperFiveScrollLeft(" Ing ",4,negative);
      bottomFiveScrollLeft(Data,j,negative);
      LetterColor.hue++;
      FastLED.show();
      delay(50);
    }
  }
  delay(200);
}

void bottomFiveScrollLeft(char Data[6], int pos, bool negative){
  CRGB Fill;
  CHSV Letter;
  if(negative){
    Fill = CRGB(LetterColor);
    Letter = CHSV(0,0,0);
  } else {
    Fill = CRGB::Black;
    Letter = LetterColor;
  }
  fillMatrix(Fill,0,8);
  for(int x = 0;x<8-pos;x++){
    for(int y = 0;y<8;y++){
      if(bitRead(font8x8_basic[(int)Data[0]][y],x+pos)==1){
        leds[ Matrix(x,y+8) ]  = Letter;
      }
    }
  }
  for(int x = 0;x<pos;x++){
    for(int y = 0;y<8;y++){
      if(bitRead(font8x8_basic[(int)Data[4]][y],x)==1){
        leds[ Matrix((8*4)-pos+x,y+8) ] = Letter;
      }
    }
  }
  for(int i = 1;i<4;i++){
    for(int x = 0;x<8;x++){
      for(int y = 0;y<8;y++){
        if(bitRead(font8x8_basic[(int)Data[i]][y],x)==1){
          leds[Matrix((i*8)+x-pos,y+8)] = Letter;
        }
      }
    }
  }
}

void upperFiveScrollLeft(char Data[6], int pos, bool negative){
  CRGB Fill;
  CHSV Letter;
  if(negative){
    Fill = CRGB(LetterColor);
    Letter = CHSV(0,0,0);
  } else {
    Fill = CRGB::Black;
    Letter = LetterColor;
  }
  fillMatrix(Fill,0,0,31,7);
  for(int x = 0;x<8-pos;x++){
    for(int y = 0;y<8;y++){
      if(bitRead(font8x8_basic[(int)Data[0]][y],x+pos)==1){
        leds[ Matrix(x,y) ]  = Letter;
      }
    }
  }
  for(int x = 0;x<pos;x++){
    for(int y = 0;y<8;y++){
      if(bitRead(font8x8_basic[(int)Data[4]][y],x)==1){
        leds[ Matrix((8*4)-pos+x,y) ] = Letter;
      }
    }
  }
  for(int i = 1;i<4;i++){
    for(int x = 0;x<8;x++){
      for(int y = 0;y<8;y++){
        if(bitRead(font8x8_basic[(int)Data[i]][y],x)==1){
          leds[Matrix((i*8)+x-pos,y)] = Letter;
        }
      }
    }
  }
}

void fillMatrix(CRGB color, unsigned int fromX, unsigned int fromY,
unsigned int toX,unsigned int toY){
  for(unsigned int x = fromX;x<=toX;x++){
    for(unsigned int y = fromY;y<=toY;y++){
      leds[ Matrix(x,y) ] = color;
    }
  }
}

int Matrix(unsigned int x, unsigned int y){
  if(y>15){
    y=15;
  }
  if(x>32){
    x=32;
  }
  int Led;
  if(y<8){
    if(x%2 == 0){
      Led = MATRIX_OFFSET + (x*8) + y;
    } else {
      Led = MATRIX_OFFSET + (x*8) + reversed[y];
    }
  } else {
    if(x%2 == 0){
      Led = MATRIX_OFFSET + 511 - (x*8) - reversed[y-8];
    } else {
      Led = MATRIX_OFFSET + 511 - (x*8) - (y-8);
    }
  }
  return Led;
}


