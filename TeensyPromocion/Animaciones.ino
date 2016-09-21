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
  uint8_t selection;
  if(selectRandom){
    selection = random8(5);
  } else {
    selection = number;
  }
  switch(selection){
    case 0:
    currentPalette = LavaColors_p;
    break;
    case 1:
    currentPalette = RainbowColors_p;
    break;
    case 2:
    currentPalette = OceanColors_p;
    break;
    case 3:
    currentPalette = ForestColors_p;
    break;
    case 4:
    currentPalette = PartyColors_p;
    break;
  }
}

void selectBlending(){
  if(random8() > 190){
    currentBlending = NOBLEND;
  } else {
    currentBlending = LINEARBLEND;
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

void transicion(uint8_t times){
  unsigned long startTime , checkTime, diff;
  int8_t pos;
  uint8_t index = 0;
  startTime = millis();
  checkTime = startTime;
  fillMatrix(CRGB::Black);
  while(millis() - startTime < times*6000){
    diff = millis() - checkTime;
    if(diff <= 500){
      drawCharAt(0,3,'P',false);
      drawCharAt(4,6,'r',false);
      drawCharAt(11,3,'o',false);
      drawCharAt(18,6,'m',false);
      drawCharAt(25,3,'o',false);
    }  else if(diff <= 6000){
      fillMatrix(CRGB::Black);
      for(uint8_t x = 0;x<14;x++){
        pos = 8 -x;
        drawHalfCircle(pos,ColorFromPalette( currentPalette,index+(x*10)),true,false);
        pos = 23 + x;
        drawHalfCircle(pos,ColorFromPalette( currentPalette,index+(x*10)),false,false);
        drawThinCircle(15,7,CRGB::White,16,false);
        drawCharAt(9,5,'3',false);
        drawCharAt(17,5,'5',false);
      }
      delay(100);
      index += 50;
    } else {
      checkTime = millis();
      fillMatrix(CRGB::Black);
    }
    FastLED.show();
    LetterColor.hue += 5;
    //SIM_SRVCOP = 0x55;
    //SIM_SRVCOP = 0xAA;
  }
}

void pacmanUpper(bool ghost, bool backwards){
  bool closed = false;
  if(!ghost){
    if(!backwards){
      for(int8_t x = -6;x<39;x++){
        fillMatrix(CRGB::Black, x,0,x+7,7);
        if(x>-1){
          fillMatrix(CRGB::Black,0,0,x,7);
        }
        drawPacman(x,0, CRGB::Orange,closed,false);
        fadeToBlackMatrix(1);
        closed = !closed;
        delay(150);
      }
    } else {
      for(int8_t x = 32;x>=-6;x--){
        fillMatrix(CRGB::Black, x,0,x+7,7);
        if(x<32){
          fillMatrix(CRGB::Black,31,0,x,7);
        }
        drawPacman(x,0,CRGB::Orange,closed,true);
        closed = !closed;
        delay(150);
      }
    }
  }
}

void pacmanLower(bool ghost, bool backwards){
  bool closed = false;
  if(!ghost){
    if(!backwards){
      for(int8_t x = -6;x<35;x++){
        fillMatrix(CRGB::Black, x,8,x+7,15);
        if(x>-1){
          fillMatrix(CRGB::Black,0,8,x,15);
        }
        drawPacman(x,8, CRGB::Orange,closed,false);
        fadeToBlackMatrix(1);
        closed = !closed;
        delay(150);
      }
    } else {
      for(int8_t x = 32;x>=-8;x--){
        fillMatrix(CRGB::Black, x,8,x+7,15);
        if(x<32){
          fillMatrix(CRGB::Black,x,8,31,15);
        }
        drawPacman(x,8,CRGB::Orange,closed,true);
        closed = !closed;
        delay(150);
      }
    }
  }
}


