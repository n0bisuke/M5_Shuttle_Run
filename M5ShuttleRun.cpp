#include <M5Stack.h>
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include "M5ShuttleRun.h"

#define NOTE_DO_L 130.813 //ドL
#define NOTE_SOL_L 195.998 //ソL
#define NOTE_DO 261.626 //ド
#define NOTE_RE 293.665 //レ
#define NOTE_MI 329.628 //ミ
#define NOTE_FA 349.228 //ファ
#define NOTE_SOL 391.995 //ソ
#define NOTE_LA 440.000 //ラ
#define NOTE_TI 493.883 //シ
#define NOTE_DO_H 523.251 //ドH

#define SHUTTLE_RUN_MAX_LEVEL 21

//int delayTime = 1000;
//int duration = 80;

float turnTimeLevel[] = {9, 8, 7.58, 7.2, 6.86, 6.55, 6.26, 6, 5.76, 5.54, 5.33, 5.14, 4.97, 4.8, 4.65, 4.5, 4.36, 4.24, 4.11, 4, 3.89};
int turnCountLevel[] = {7, 8, 8, 9, 9, 10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16};

int flag = 0; //0往路 1復路
int levelTurnCount = 0; //このレベルで何回目か
int totalTurnCount = 0; //トータルで何回目か
int level = 0; //レベル

// ヘッダー描画
void drawHeader(const char *string, uint16_t color)
{
  M5.Lcd.fillScreen(color);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_MAGENTA, TFT_BLUE);
  M5.Lcd.fillRect(0, 0, 320, 30, TFT_BLUE);
  M5.Lcd.setTextDatum(TC_DATUM);
  M5.Lcd.drawString(string, 160, 2, 4); // Font 4 for fast drawing with background
}

//往路
void shuttleRunForward(int duration, float delayTime){  
  M5.Speaker.tone(NOTE_DO, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_RE, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_MI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_FA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_SOL, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_LA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_TI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO_H, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO, duration); delay(delayTime);
  totalTurnCount++;
  levelTurnCount++;
  flag = 1; //復路へ
}

//復路
void shuttleRunBackward(int duration, float delayTime){
  M5.Speaker.tone(NOTE_DO_H, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_TI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_LA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_SOL, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_FA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_MI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_RE, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO_L, duration); delay(delayTime);
  totalTurnCount++;
  levelTurnCount++;
  flag = 0; //往路へ
}

void levelUp(){
   M5.Speaker.tone(NOTE_DO, 10); delay(250);
   M5.Speaker.tone(NOTE_SOL_L, 10); delay(250);
   M5.Speaker.tone(NOTE_RE, 10); delay(250);
   level++;
   levelTurnCount = 0;
}

void M5ShuttleRun(){
    drawHeader("M5Stack Shuttle Run", TFT_NAVY);
    M5.Lcd.setFreeFont(FF40);

    while(level < SHUTTLE_RUN_MAX_LEVEL){
      M5.Lcd.drawString("Level: "+ (String)level, 0, 40, GFXFF);
      M5.Lcd.drawString("Turn: " + (String)totalTurnCount, 0, 90, GFXFF);
      M5.Lcd.drawString("Mile(m): " + (String)(totalTurnCount * 20), 0, 140, GFXFF);
      M5.Lcd.drawString("Kcal: " + (String)(60 * (totalTurnCount * 20 * 0.001)), 0, 190, GFXFF);
      
      float turnTime = turnTimeLevel[level] / 9 * 1000;
      if(flag == 0){
        shuttleRunForward(800, (int)turnTime);
      }else{
        shuttleRunBackward(800, (int)turnTime);
      }

      if(turnCountLevel[level] <= levelTurnCount){
        levelUp();
      }
    }
}

