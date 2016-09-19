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
