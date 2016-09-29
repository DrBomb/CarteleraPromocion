#include <SimpleTimer.h>

const int p1=2;   const int p2=1;   const int p3=59;   const int p4=60;   const int p5=61;   const int p6=62;   const int p7=63;   const int p8=64;
const int p9=3;   const int p10=4; const int p11=5; const int p12=18; const int p13=19; const int p14=20; const int p15=21; const int p16=22;
const int p17=6; const int p18=17; const int p19=25; const int p20=24; const int p21=23; const int p22=44; const int p23=43; const int p24=58; 
const int p25=7; const int p26=16; const int p27=29; const int p28=28; const int p29=27; const int p30=26; const int p31=42; const int p32=57; 
const int p33=8; const int p34=15; const int p35=30; const int p36=37; const int p37=38; const int p38=39; const int p39=40; const int p40=41;
const int p41=9; const int p42=14; const int p43=31; const int p44=36; const int p45=48; const int p46=47; const int p47=46; const int p48=45;
const int p49=10; const int p50=13; const int p51=32; const int p52=35; const int p53=49; const int p54=52; const int p55=53; const int p56=54; 
const int p57=11; const int p58=12; const int p59=33; const int p60=34; const int p61=50; const int p62=51; const int p63=56; const int p64=55;


int Matriz [8][8]={ {p1,p2,p3,p4,p5,p6,p7,p8},
                    {p9,p10,p11,p12,p13,p14,p15,p16},
                    {p17,p18,p19,p20,p21,p22,p23,p24},
                    {p25,p26,p27,p28,p29,p30,p31,p32},
                    {p33,p34,p35,p36,p37,p38,p39,p40},
                    {p41,p42,p43,p44,p45,p46,p47,p48},
                    {p49,p50,p51,p52,p53,p54,p55,p56},
                    {p57,p58,p59,p60,p61,p62,p63,p64}};



char rx;
String Srx="";
int Vrx=0;
int X;
int Y;
int R=0;
int auxX=0;
int auxY=0;
int Segundos=0;
int conteo=0;

SimpleTimer TIMER;

void setup() {
for (int i=2;i<19;i++){
pinMode(i,OUTPUT);
}
Borrar_Matriz();
Serial.begin(115200);
TIMER.setInterval(1000,tiempo);
String data="Actualizo matriz Valor en X : "+String(auxX,DEC)+" Valor en Y : "+String(auxY,DEC);
Serial.println(data);
}



void loop() {
TIMER.run(); 

if(Serial.available()>0){
  delay(20);
  while(Serial.available()>0){
  Srx=Srx+(char)Serial.read();
  }
Vrx=Srx.toInt();
Srx="";  
}

switch (Vrx){
    case 0:
    Borrar_Matriz();
    break;

    case 70:
    for(int i=2;i<10;i++){
    digitalWrite(i,LOW);  
    }
    for(int i=11;i<19;i++){
    digitalWrite(i,HIGH);
    delay(50);  
    digitalWrite(i,LOW);
    }
    break;

    case 71:
    for(int i=59;i<65;i++){
    R=LocalizarPersona(i);  
    delay(50);
    }
    break;
    
    case 72:
    break;

    case 73:
    for(int i=1;i<65;i++){
    R=LocalizarPersona(i);  
    delay(20);  
    }
    break;
    
    default: 
    Borrar_Matriz();
    R=LocalizarPersona(Vrx);
    Vrx=70;
    break; 

}

}

void Borrar_Matriz(){  // las X se apagan en bajo y las Y se apagan en alto
for(int i=2;i<10;i++){
digitalWrite(i,HIGH);  
}
for(int i=11;i<19;i++){
digitalWrite(i,LOW);  
}
}

void EnsenderLed(int x,int y){
//Borrar_Matriz();
digitalWrite((y+2),LOW);
digitalWrite((x+11),HIGH);  
}

void ApagarLed(int x,int y){
//Borrar_Matriz();
digitalWrite((y+2),HIGH);
digitalWrite((x+11),LOW);  
}

int LocalizarPersona(int Numero){
  for(int x=0;x<8;x++){
    for(int y=0;y<8;y++){
      if(Matriz[y][x]==Numero){
      Borrar_Matriz();
      EnsenderLed(x,y);
        String Data="Posiciones de la matriz X : "+String(x,DEC)+" Y : "+String(y,DEC);
        Serial.println(Data);
        return 1; 
      }
    }
  }
  return 0;
}

int LocalizarPersonaN(int Numero){
  for(int x=0;x<8;x++){
    for(int y=0;y<8;y++){
      if(Matriz[y][x]==Numero){
      ApagarLed(x,y);
        return 1; 
      }
    }
  }
  return 0;
}

void tiempo(){
Segundos=Segundos+1;
}

