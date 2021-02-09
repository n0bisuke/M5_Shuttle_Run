#include <M5Stack.h>
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include "M5ShuttleRun.h"
#include "_M5SR_Melody.h"
#include "_M5SR_Draw.h"

#define SHUTTLE_RUN_MAX_LEVEL 21 //レベルは21までらしい

//レベル0が無いので、0番目に0(適当な値)を入れている。
int TURN_COUNT_LEVEL[] = {0, 7, 8, 8, 9, 9, 10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16};
float LIMIT_TIME_LEVEL[] = {0, 9.00, 8.00, 7.58, 7.20, 6.86, 6.55, 6.26, 6.00, 5.76, 5.54, 5.33, 5.14, 4.97, 4.80, 4.65, 4.50, 4.36, 4.24, 4.11, 4.00, 3.89};

int flag = 0; //0往路 1復路
int levelTurnCount = 0; //このレベルで何回目か
int totalTurnCount = 0; //トータルで何回目か
int level = 1; //レベル

void M5ShuttleRun(){
    SR_Draw_Header("M5Stack Shuttle Run", TFT_NAVY);
    M5.Lcd.setFreeFont(FF40);
    SR_SE_Start(); //スタート音
    
    while(level < SHUTTLE_RUN_MAX_LEVEL){
      SR_Draw_Update(level, totalTurnCount); //描画更新
      
      //1音の長さ ミリ秒
      float oneSoundTime = LIMIT_TIME_LEVEL[level] / 9 * 1000; 

      //音の長さ:間隔 = 0.005:0.995
      float soundLength = oneSoundTime * 0.005;
      float delayTime = oneSoundTime - soundLength;
      Serial.println(soundLength);

      if(flag == 0){
        SR_Melody_Going(soundLength, delayTime); //行きのメロディ
        flag = 1; //復路へ
      }else{
        SR_Melody_Returning(soundLength, delayTime); //帰りのメロディ
        flag = 0; //往路へ
      }

      totalTurnCount++;
      levelTurnCount++;

      if(TURN_COUNT_LEVEL[level] <= levelTurnCount){
        SR_SE_LevelUp(); //レベルアップ音
        level++;
        levelTurnCount = 0;
      }
    }
}

