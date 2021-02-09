
## Shuttle Run for Arduino

M5Stackでシャトルランができます。

M5StackでArduino開発している人向けのライブラリです。

## How to Use

通常通りArduino IDEにライブラリ追加してください。

使うプログラムで`#include <M5ShuttleRun.h>`でライブラリのインクルードをして、
`M5ShuttleRun()`でシャトルランスタートです。

## 動作確認

* 2021/2/10 Arduino IDE v1.8.13で動作確認

## Example

コピペで動きます。

```shuttlerun.ino
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