
## Shuttle Run for Arduino

M5Stackでシャトルランができます。

M5StackでArduino開発している人向けのライブラリです。

## How to Use

通常通りArduino IDEにライブラリ追加してください。

使うプログラムで`#include <M5ShuttleRun.h>`でライブラリのインクルードをして、
`M5ShuttleRun()`でシャトルランスタートです。

## Example

```
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
```