
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

void drawThinCircle(uint8_t x, uint8_t y, CRGB color, uint8_t diameter, bool draw){
  if(diameter==0){
    FastLED.show();
    return;
  }
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
  if(draw){FastLED.show();}
}

void drawHalfCircle(int8_t x, CRGB color, bool openRight, bool draw){
  uint8_t startX, finishX;
  if(openRight){
    startX=0;
    finishX=6;
    if(x<-6 || x>31){
      if(draw){FastLED.show();}
      return;
    }
    if(x<0){
      startX = x * -1;
    }
    if(x>31-6){
      finishX = 6-(31-x);
    }
    for(uint8_t yi = 0;yi<16;yi++){
      for(uint8_t xi = startX;xi<=finishX;xi++){
        if(circulo[15][yi][xi]){
          leds[ Matrix(x+xi,yi) ] = color;
        }
      }
    }
  } else {
    startX = 9;
    finishX = 15;
    if(x<0 || x>36){
      if(draw){FastLED.show();}
      return;
    }
    if(x>31){
      finishX = 15 - (x-31);
    }
    if(x<6){
      startX = 6 -x;
    }
    for(uint8_t yi = 0;yi<16;yi++){
      for(uint8_t xi = startX;xi<=finishX;xi++){
        if(circulo[15][yi][xi]){
          leds[ Matrix(x-15+xi,yi) ] = color;
        }
      }
    }
  }
  if(draw){FastLED.show();}
}

void drawCharAt(int8_t x, int8_t y, char character, bool draw){
  uint8_t charStartX = 0,charFinishX = 7,charStartY = 0,charFinishY = 7;
  if(x>31 || x<-7 || y>15 || y<-7){
    if(draw){ FastLED.show();}
    return;
  }
  if(x<0){
    charStartX = x * -1;
  }
  if(x>31-8){
    charFinishX = 8-(x-31);
  }
  if(y<0){
    charStartY = y * -1;
  }
  if(y>15-8){
    charFinishY = 8-(y-15);
  }
  for(uint8_t xi = charStartX;xi<=charFinishX;xi++){
    for(uint8_t yi = charStartY;yi<=charFinishY;yi++){
      if(bitRead(font8x8_basic[(int)character][yi],xi)==1){
        leds[Matrix(x+xi,y+yi)] = LetterColor;
      }
    }
  }
  if(draw){FastLED.show();}
}

void fillMatrix(CRGB color, uint8_t fromX, uint8_t fromY,
uint8_t toX, uint8_t toY){
  for(unsigned int x = fromX;x<=toX;x++){
    for(unsigned int y = fromY;y<=toY;y++){
      leds[ Matrix(x,y) ] = color;
    }
  }
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

