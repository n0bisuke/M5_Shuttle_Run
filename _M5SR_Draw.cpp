#include <M5Stack.h>
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include "_M5SR_Draw.h"

// ヘッダー描画
void SR_Draw_Header(const char *string, uint16_t color){
  M5.Lcd.fillScreen(color);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_MAGENTA, TFT_BLUE);
  M5.Lcd.fillRect(0, 0, 320, 30, TFT_BLUE);
  M5.Lcd.setTextDatum(TC_DATUM);
  M5.Lcd.drawString(string, 160, 2, 4); // Font 4 for fast drawing with background
}

// 描画更新
void SR_Draw_Update(int level, int totalTurnCount){
  M5.Lcd.drawString("Level: "+ (String)level +" ", 0, 40, GFXFF);
  M5.Lcd.drawString("Turn: " + (String)totalTurnCount +" ", 0, 90, GFXFF);
  M5.Lcd.drawString("Mile(m): " + (String)(totalTurnCount * 20) +" ", 0, 140, GFXFF);
  M5.Lcd.drawString("Kcal: " + (String)(60 * (totalTurnCount * 20 * 0.001)) +" ", 0, 190, GFXFF);
}