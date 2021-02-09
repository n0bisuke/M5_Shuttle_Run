#include <M5Stack.h>
#include "_M5SR_Melody.h"

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
#define NOTE_RE_H 587.330 //レH
#define NOTE_MI_H 659.255 //ミH

//行き
void SR_Melody_Going(int duration, float delayTime){  
  M5.Speaker.tone(NOTE_DO, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_RE, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_MI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_FA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_SOL, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_LA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_TI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO_H, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO, duration); delay(delayTime);
}

//帰り
void SR_Melody_Returning(int duration, float delayTime){
  M5.Speaker.tone(NOTE_DO_H, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_TI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_LA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_SOL, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_FA, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_MI, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_RE, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO, duration); delay(delayTime);
  M5.Speaker.tone(NOTE_DO_L, duration); delay(delayTime);
}

//レベルアップ音(サウンドエフェクト)
void SR_SE_LevelUp(){
   M5.Speaker.tone(NOTE_DO_H, 10); delay(250);
   M5.Speaker.tone(NOTE_SOL, 10); delay(250);
   M5.Speaker.tone(NOTE_RE_H, 10); delay(250);
}