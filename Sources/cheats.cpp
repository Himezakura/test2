#include "cheats.hpp"

namespace CTRPluginFramework
{

//--------------------------------------#
//										|
// 　NAME　	　=　関数名(English only)		|
// 　XXXXXXXX　=　アドレス					|
// 　YYYYYYYY　=　値						|
// 　ZZZZZZZZ　=　ベースアドレス				|
// 　AAAAAAAA　=　加算値					|
// 　B　　　　	　=　格納名					|
// 　CCCCCCCC = 繰り返す回数				|
//										|
//--------------------------------------*


//通常の記述
void NAME(MenuEntry *entry) {
 Process::Write32(0xXXXXXXXX, 0xYYYYYYYY);
}

//ポインターコードの記述
void NAME(MenuEntry *entry) {
 u32 B;
 Process::Read32(0xZZZZZZZZ, B);
 Process::Write32(B + 0xAAAAAAAA, 0xYYYYYYYY);
}

//ループの記述
void NAME(MenuEntry *entry) {
 u32 B;
  Process::Read32(0xZZZZZZZZ, B);
  for (int i = 0; i < 0xCCCCCCCC; i++) {
   Process::Write32(B + 0xAAAAAAAA + i * 4, 0xYYYYYYYY);
  }
}

//選択肢を出す記述
void NAME(MenuEntry *entry) {
 Keyboard key("説明", {"選択肢1", "選択肢2"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0xXXXXXXXX, 0xYYYYYYYY);
  } else if (B == 1) {
   Process::Write32(0xXXXXXXXX, 0xYYYYYYYY);
  }
}

//入力の記述
void NAME(MenuEntry *entry) {
 static u32 B = 1;
 u32 B;
  Keyboard key("説明");
  key.Open(B, B);
  Process::Read32(0xZZZZZZZZ, B);
  Process::Write32(B + 0xAAAAAAAA, B);
　}

//終了の記述
void NAME(MenuEntry *entry) {
  abort();
}

}
