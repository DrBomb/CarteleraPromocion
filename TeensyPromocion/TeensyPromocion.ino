#include <FastLED.h>
#include "font8x8_basic.h"
#include "Nombres.h"
#include "palettes.h"
#include "sprites.h"
#define NUM_LEDS 512
#define DATA_PIN 17
#define MATRIX_OFFSET 0

// Funciones
void drawHalfCircle(int8_t x, CRGB color, bool openRight, bool draw = true);
void drawCharAt(int8_t x, int8_t y, char character, bool draw = true);
void  selectPalette(bool selectRandom, uint8_t number = 0);
const int reversed[8] = {7,6,5,4,3,2,1,0};
void bottomFiveScrollLeft(char Data[6], uint8_t pos, bool negative);
void fillMatrix(CRGB color, uint8_t fromX = 0, uint8_t fromY = 0,
uint8_t toX=31,uint8_t toY=15);
void leftFade(CRGB color = CRGB::White);
void drawThinCircle(uint8_t x, uint8_t y, CRGB color, uint8_t diameter, bool draw = true);

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
  drawThinCircle(15,7,16,false);
  drawCharAt(9,4,'3',false);
  drawCharAt(17,4,'5',false);
  drawHalfCircle(8,CRGB::White,false);
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






