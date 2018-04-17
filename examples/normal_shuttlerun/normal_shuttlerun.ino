#include <M5Stack.h>
#include <M5ShuttleRun.h>

void setup() {
  M5.begin();
  M5.Lcd.printf("Shuttle Run Standby... Please Press Btn A \r\n");
}

void loop() {
  if(M5.BtnA.wasPressed()) { 
    M5ShuttleRun();
  }

  M5.update();
}
