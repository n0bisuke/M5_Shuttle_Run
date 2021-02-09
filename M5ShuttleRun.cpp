#include <M5Stack.h>
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include "M5ShuttleRun.h"
#include "_M5SR_Melody.h"
#include "_M5SR_Draw.h"

#define SHUTTLE_RUN_MAX_LEVEL 21

//int delayTime = 1000;
//int duration = 80;

float turnTimeLevel[] = {9, 8, 7.58, 7.2, 6.86, 6.55, 6.26, 6, 5.76, 5.54, 5.33, 5.14, 4.97, 4.8, 4.65, 4.5, 4.36, 4.24, 4.11, 4, 3.89};
int turnCountLevel[] = {7, 8, 8, 9, 9, 10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16};

int flag = 0; //0往路 1復路
int levelTurnCount = 0; //このレベルで何回目か
int totalTurnCount = 0; //トータルで何回目か
int level = 1; //レベル

void M5ShuttleRun(){
    SR_Draw_Header("M5Stack Shuttle Run", TFT_NAVY);
    M5.Lcd.setFreeFont(FF40);

    while(level < SHUTTLE_RUN_MAX_LEVEL){
      SR_Draw_Update(level, totalTurnCount); //描画更新
      
      float turnTime = turnTimeLevel[level] / 9 * 1000;
      if(flag == 0){
        SR_Melody_Going(800, (int)turnTime); //行きのメロディ
        totalTurnCount++;
        levelTurnCount++;
        flag = 1; //復路へ

      }else{
        SR_Melody_Returning(800, (int)turnTime); //帰りのメロディ
        totalTurnCount++;
        levelTurnCount++;
        flag = 0; //往路へ

      }

      if(turnCountLevel[level] < levelTurnCount){
        SR_SE_LevelUp(); //レベルアップ音
        level++;
        levelTurnCount = 0;
      }
    }
}

