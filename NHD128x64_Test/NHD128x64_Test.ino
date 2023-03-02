/*

  HelloWorld.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#include <Arduino.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

U8G2_ST7565_64128N_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* cs=*/ 15, /* dc=*/ 32, /* reset=*/ 33);

char i = 0;

void centerText(char* text1, char* text2, char* text3, char* text4, char* text5, char* text6, uint8_t lines) {
 
  u8g2.firstPage();
  do {
    int16_t text1_width = u8g2.getStrWidth(text1);
    int16_t text2_width = u8g2.getStrWidth(text2);
    int16_t text3_width = u8g2.getStrWidth(text3);
    int16_t text4_width = u8g2.getStrWidth(text4);
    int16_t text5_width = u8g2.getStrWidth(text5);
    int16_t text6_width = u8g2.getStrWidth(text6);
    int16_t charHeight  = u8g2.getMaxCharHeight() - 3;

    u8g2.setCursor((SCREEN_WIDTH - text1_width) / 2, (((SCREEN_HEIGHT - (lines * charHeight))/2) + charHeight));
    u8g2.print(text1);
    
    u8g2.setCursor((SCREEN_WIDTH - text2_width) / 2, (((SCREEN_HEIGHT - (lines * charHeight))/2) + (2 * charHeight)));
    u8g2.print(text2);

    u8g2.setCursor((SCREEN_WIDTH - text3_width) / 2, (((SCREEN_HEIGHT - (lines * charHeight))/2) + (3 * charHeight)));
    u8g2.print(text3);

    u8g2.setCursor((SCREEN_WIDTH - text4_width) / 2, (((SCREEN_HEIGHT - (lines * charHeight))/2) + (4 * charHeight)));
    u8g2.print(text4);

    u8g2.setCursor((SCREEN_WIDTH - text5_width) / 2, (((SCREEN_HEIGHT - (lines * charHeight))/2) + (5 * charHeight)));
    u8g2.print(text5);

    u8g2.setCursor((SCREEN_WIDTH - text6_width) / 2, (((SCREEN_HEIGHT - (lines * charHeight))/2) + (6 * charHeight)));
    u8g2.print(text6);
    
  } while (u8g2.nextPage());
}

void setup() {
  Serial.begin(115200);
  u8g2.begin();
  u8g2.setFlipMode(1);
  u8g2.setContrast(150);
  u8g2.setFont(u8g2_font_ncenB24_tf);
   
  String starS = "*";
  char* starC = "";

  for(i=0;i<7;i++){ 
  
  starC = const_cast<char*>(starS.c_str());
   
  centerText(starC, "", "", "", "", "", 1);
  delay(1000);
  starS += '*';
  }
     
  u8g2.setFont(u8g2_font_ncenB08_tf);
}

void loop() {
  
  drawScreen(i);
  i++;
  if(i==21){i=0;}
  delay(2000);
  /*centerText("Els""\xf6""", "", "", "", "", "", 1);
  delay(2000);
  centerText("Els""\xf6""", "M""\xe1""sodik", "", "", "", "", 2);
  delay(2000);
  centerText("Els""\xf6""", "M""\xe1""sodik", "Harmadik", "", "", "", 3);
  delay(2000);
  centerText("Els""\xf6""", "M""\xe1""sodik", "Harmadik", "Negyedik", "", "", 4);
  delay(2000);
  centerText("Els""\xf6""", "M""\xe1""sodik", "Harmadik", "Negyedik", """\xd6""t""\xf6""dik", "", 5);
  delay(2000);
  centerText("Els""\xf6""", "M""\xe1""sodik", "Harmadik", "Negyedik", """\xd6""t""\xf6""dik", "Hatodik", 6);
  delay(2000);*/
}


void drawScreen(char drawState){ 
  u8g2.setFont(u8g2_font_ncenB08_tf);
  u8g2.firstPage();
  do {
  switch(drawState){
    case 0:
    centerText("Inicializ""\xe1""l""\xe1""s...", "", "", "", "", "", 1);
    break;
    case 1:
    centerText("Inicializ""\xe1""l""\xe1""s k""\xe9""sz!", "", "", "", "", "", 1);
    break;
    case 2:
    centerText("Nem tal""\xe1""lhat""\xf3"" vagy", "hib""\xe1""s az SD k""\xe1""rtya!", "", "", "", "", 2);
    break;
    case 3:
    centerText("Hiba t""\xf6""rt""\xe9""nt a", "f""\xe1""jl ""\xed""r""\xe1""sakor!", "", "", "", "", 2);
    break;
    case 4:
    centerText("Hiba t""\xf6""rt""\xe9""nt a", "f""\xe1""jl megnyit""\xe1""sakor!", "", "", "", "", 2);
    break;
    case 5:
    centerText("* Magyar Nyelv *", "# English Language #", "", "", "", "", 2);
    break;
    case 6:
    centerText("\xcd""rd be a feloldani", "k""\xed""v""\xe1""nt"" dokk sz""\xe1""m""\xe1""t""!", "", "", "", "", 2);
    break;
    case 7:
    centerText("K""\xe9""rlek add meg a", "felold""\xe1""shoz a", "PIN k""\xf3""dodat!", "", "", "", 3);
    break;
    case 8:
    centerText("K""\xe9""rlek adj meg egy 4", "sz""\xe1""mjegy""\xfc"" PIN k""\xf3""dot!", "A parkol""\xe1""s v""\xe9""gezt""\xe9""vel", "ezzel fogod tudni", "kinyitni a dokkot.", "", 5);
    break;
    case 9:
    centerText("K""\xe9""rlek add meg ism""\xe9""t", "a PIN k""\xf3""dot!", "", "", "", "", 2);
    break;
    case 10:
    centerText("Hopp""\xe1"", ""\xfa""gy t""\xfc""nik", "rossz k""\xf3""dot adt""\xe1""l meg.", "K""\xe9""rlek, pr""\xf3""b""\xe1""ld meg", "ism""\xe9""t!", "", "", 4);
    break;
    case 11:
    centerText("Szuper, a bring""\xe1""d", "parkol""\xe1""si folyamata", "v""\xe9""get ""\xe9""rt!", "K""\xe9""rlek vedd ki a", "dokkb""\xf3""l ""\xe9""s hagyd", "nyitva a kaput!", 6);
    break;
    case 12:
    centerText("Meg is voln""\xe1""nk!", "K""\xe9""rlek helyezd a", "ker""\xe9""kp""\xe1""rt a(z)", "10.", "t""\xe1""roloba ""\xe9""s csukd", "r""\xe1"" a kaput!", 6);
    break;
    case 13:
    centerText("********Admin********", "", "\xcd""rja be a feloldani", "k""\xed""v""\xe1""nt"" dokk sz""\xe1""m""\xe1""t""!", "", "",6);
    break;
    case 14:
    centerText("********Admin********", "", "K""\xe9""rem adja meg a", "felold""\xe1""shoz az admin", "jelsz""\xf3""t!",  "", 6);
    break;
//Angol-------------------------------------------------------------------------
    case 15:
    centerText("Enter dock's number", "you want to unlock!", "", "", "", "", 2);
    break;
    case 16:
    centerText("Please enter your", "PIN code to unlock!", "", "", "", "", 2);
    break;
    case 17:
    centerText("Super, your bike", "parking process is", "over. Please take it", "out of the dock and", "leave the gate open!", "Have a nice trip!", 6);
    break;
    case 18:
    centerText("Oops, it looks like", "you entered the", "wrong code.", "Please try again!", "", "", 4);
    break;
    case 19:
    centerText("Please enter a", "4-digit PIN code!", "After parking, you", "will be able to open", "the dock with this", "", 5);
    break;
    case 20:
    centerText("Please enter the", "PIN again!", "", "", "", "", 2);
    break;
    case 21:
    centerText("Ready! Please place", "the bicycle in the", "10.", "storage and", "close the gate!", "", 5);
    break;
    default:
    break;
  }  
  }while ( u8g2.nextPage() );
}
