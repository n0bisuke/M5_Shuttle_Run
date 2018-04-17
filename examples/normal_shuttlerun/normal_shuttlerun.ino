#include <M5Stack.h>
#include <shuttlerun.h>

void setup() {
  M5.begin();
  M5.Lcd.printf("Shuttle Run Standby... Please Press Btn A \r\n");
}

void loop() {
  if(M5.BtnA.wasPressed()) { 
    shuttlerun();
  }

  M5.update();
}
