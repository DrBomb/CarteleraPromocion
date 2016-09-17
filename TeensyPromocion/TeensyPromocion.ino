#include <FastLED.h>
#include "font8x8_basic.h"
#include "Nombres.h"
#include "palettes.h"
#include "animaciones.h"
#define NUM_LEDS 512
#define DATA_PIN 17
#define MATRIX_OFFSET 0

// Funciones
void  selectPalette(bool selectRandom, uint8_t number = 0);
const int reversed[8] = {7,6,5,4,3,2,1,0};
void bottomFiveScrollLeft(char Data[6], uint8_t pos, bool negative);
void fillMatrix(CRGB color, uint8_t fromX = 0, uint8_t fromY = 0,
uint8_t toX=31,uint8_t toY=15);
void leftFade(CRGB color = CRGB::White);

// Globales
String Nombre;
CHSV LetterColor(0,255,255);
CRGB leds[NUM_LEDS+1];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

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
  for(int x = 0;x<17;x++){
    fillMatrix(CRGB::Black);
    drawThinCircle(8,4,x);
    delay(10);
  }
  for(int x = 16;x>=0;x--){
    fillMatrix(CRGB::Black);
    drawThinCircle(8,4,x);
    delay(10);
  }
  /*selectPalette(true);
  currentBlending=LINEARBLEND;
  fallingColors();
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
    mostrarNombre(index,false);
    mostrarNombre(index, false);
  }*/
}

void info(bool negative){
  const String cadena1 = "Promo";
  const String cadena2 = "57";
  char data[6];
  int i = 0;
  for(int x = 0;x<6;x++){
    data[x] = cadena1.charAt(x);
  }
  while(i<3){
    
  } 
}

void leftFade(CRGB color){
  for(int x=31;x>=0;x--){
    fadeToBlackMatrix(30);
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

void mostrarNombre(uint8_t index, bool negative){
  char Data[6];
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

void bottomFiveScrollLeft(char Data[6], uint8_t pos, bool negative){
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

void upperFiveScrollLeft(char Data[6], uint8_t pos, bool negative){
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

void fillMatrix(CRGB color, uint8_t fromX, uint8_t fromY,
uint8_t toX, uint8_t toY){
  for(unsigned int x = fromX;x<=toX;x++){
    for(unsigned int y = fromY;y<=toY;y++){
      leds[ Matrix(x,y) ] = color;
    }
  }
}

int Matrix(int8_t x, int8_t y){
  if(y>15 || x>32 || y<0 || x<0){
    return NUM_LEDS;
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

void selectPalette(bool selectRandom, uint8_t number){
  int selection;
  if(selectRandom){
    selection = random8(3);
  } else {
    selection = number;
  }
  switch(selection){
    case 0:
    currentPalette = cloud_gp;
    break;
    case 1:
    currentPalette = RainbowColors_p;
    break;
    case 2:
    currentPalette = OceanColors_p;
    break;
  }
}

void fallingColors(){
  int black_entry = random(16);
  if(black_entry+7>16){
    int i = 0;
    while(black_entry+i<16){
      currentPalette[black_entry+i]=CRGB::Black;
      i++;
    }
    for(int x = 0;x<7-i;x++){
      currentPalette[x] = CRGB::Black;
    }
  } else {
    currentPalette[black_entry] = CRGB::Black;
    currentPalette[black_entry+1] = CRGB::Black;
    currentPalette[black_entry+2] = CRGB::Black;
    currentPalette[black_entry+3] = CRGB::Black;
    currentPalette[black_entry+4] = CRGB::Black;
    currentPalette[black_entry+5] = CRGB::Black;
    currentPalette[black_entry+6] = CRGB::Black;
  }
  uint8_t offsets[32];
  uint8_t index = 0;
  for(unsigned int i = 0;i<32;i++){
    offsets[i] = random8(128);
  }
  for(int veces = 255;veces>=0;veces--){
    for(int x=0;x<32;x++){
      for(int y=0;y<16;y++){
        index = (veces*20)+offsets[x]+(y*10);
        leds[ Matrix(x,y) ] = ColorFromPalette( currentPalette, index, 255, currentBlending);
      }
    }
    FastLED.show();
    delay(100);
  }
}

void drawThinCircle(uint8_t x, uint8_t y, uint8_t diameter){
  if(diameter==0){
    FastLED.show();
    return;
  }
  CRGB color = CRGB::White;
  int center;
  if(diameter&0x01){
    center = (float)(diameter/2);
  } else {
    center = (diameter/2)-1;
  }
  for(uint8_t yi = 0;yi<diameter;yi++){
    for(uint8_t xi = 0;xi<diameter;xi++){
      if(circulo[diameter-1][yi][xi]){
        if(yi!=center && xi!=center){
          leds[ Matrix(x-center+xi,y-center+yi) ] = color;
        } else if(yi==center && xi!= center){
          leds[ Matrix(x-center+xi,y) ] = color; 
        } else if(yi!=center && xi==center){
          leds[ Matrix(x,y-center+yi) ] = color;
        } else {
          leds[ Matrix(x,y) ] = color;
        }
      }
    }
  }
  FastLED.show();
}

