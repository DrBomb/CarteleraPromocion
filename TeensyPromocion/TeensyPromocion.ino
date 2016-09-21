#include <DFPlayer_Mini_Mp3.h>
#include <FastLED.h>
#include "font8x8_basic.h"
#include "Nombres.h"
#include "sprites.h"
#define NUM_LEDS 512
#define DATA_PIN 17
#define MATRIX_OFFSET 0
#define TRIG1 

DEFINE_GRADIENT_PALETTE( cloud_gp ) {
    0, 247,149, 91,
  127, 208, 32, 71,
  255,  42, 79,188};

//SUBRUTINA DE WATCHDOG
/*#ifdef __cplusplus
extern "C" {
#endif
void startup_early_hook() {
  // empty
}
#ifdef __cplusplus
}
#endif*/

// Funciones
void drawHalfCircle(int8_t x, CRGB color, bool openRight, bool draw = true);
void drawCharAt(int8_t x, int8_t y, char character, bool draw = true);
extern void  selectPalette(bool selectRandom, uint8_t number = 0);
const int reversed[8] = {7,6,5,4,3,2,1,0};
void bottomFiveScrollLeft(char Data[6], uint8_t pos, bool negative);
void fillMatrix(CRGB color, int8_t fromX = 0, int8_t fromY = 0,
int8_t toX=31,int8_t toY=15);
void leftFade(CRGB color = CRGB::White);
void drawThinCircle(uint8_t x, uint8_t y, CRGB color, uint8_t diameter, bool draw = true);
void transicion(uint8_t times = 2);
void drawPacman(int8_t x, int8_t y, CRGB color, bool closed, bool reversed, bool draw = true);

// Globales
String Nombre;
CHSV LetterColor(0,255,255);
CRGB leds[NUM_LEDS+1];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
  Serial2.begin(115200);
  Serial.begin(9600);
  Serial3.begin(9600);
  mp3_set_serial(Serial3);
  delay(10);
  mp3_set_volume(30);
  delay(10),
  delay(1);
  Nombre.reserve(12);
  random16_add_entropy(analogRead(0));
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(30);
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int index;
  if(Serial2.available()){
    index = Serial2.parseInt();
    while(Serial2.available()){
      Serial2.read();  
    }
    Serial.println(index);
    mp3_play(3);
    mostrarNombre(index,false);
    mostrarNombre(index,false);
  } else {
    index = random8(54);
    //Serial.println(index);
    mostrarNombre(index,false);
    mostrarNombre(index, false);
  }
  pacmanDelete();
  selectPalette(true);
  selectBlending();
  transicion();
}

void pacmanDelete(){
  mp3_play(2);
  pacmanUpper(false,false);
  pacmanLower(false,true);
  mp3_stop();
}

