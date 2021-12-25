#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LCD 화면에 노출할 숫자 값 3개를 선언합니다.
int val1;
int val2;
int val3;

// 게임 진행에 필요한 코인(money)을 선언합니다.
int money = 100;

// 버튼을 사용하기 위해 변수 bt를 선언합니다.
int bt = 7;

void setup() {
  // random함수를 사용하기 위한 세팅, 게임 시작 전 환영인사.
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  lcd.print("WELLCOME CASINO!!");
  lcd.setCursor(0,1);
  lcd.print("GOOD LUCK!");
  delay(5000);

  pinMode(7, OUTPUT);
}

void loop() {
  // 미리 프로그래밍 한 randomnum()를 사용합니다.
  randomnum();
  lcd.setCursor(0, 0);
  lcd.print("CASINO MACHINE!!");

  // 숫자 3개(val1, val2, val3)를 랜덤하게 롤링시킵니다.
  lcd.setCursor(0, 1);
  lcd.print(val1);
  lcd.print("   ");
  lcd.print(val2);
  lcd.print("   ");
  lcd.print(val3);
  lcd.print("|");
  lcd.print("$:");
  lcd.print(money);
  lcd.print("   ");

  // 버튼에 전원이 들어온 경우 게임 머니를 차감시키고, 숫자를 정지(딜레이) 시킵니다.
  // 게임 결과에 따라 게임 머니를 변화시키고, 경기 결과를 출력합니다.
  if(digitalRead(bt) == HIGH) {
    money = money - 25;
    lcd.setCursor(0, 1);
    lcd.print(val1);
    lcd.print("   ");
    lcd.print(val2);
    lcd.print("   ");
    lcd.print(val3);
    lcd.print("|");
    lcd.print("$:");
    lcd.print(money);
    lcd.print("   ");
    delay(3000);
    if(val1 == val2 && val2 == val3) {
      lcd.setCursor(0, 0);
      lcd.print("! WIN + 225 $  !");
      money = money + 225;
      delay(3000);
    } 
    else if(val1 == val2 || val2 == val3) {
      lcd.setCursor(0, 0);
      lcd.print("-  DRAW + 25 $ -");
      money = money + 25;
      delay(3000);
    } else if(val1 == val3) {
      lcd.setCursor(0, 0);
      lcd.print("-  DRAW + 25 $ -");
      money = money + 25;
      delay(3000);
    } else {
    lcd.setCursor(0, 0);
    lcd.print("~~ LOSE - 25 $ ~~");
    money = money - 25;
    delay(3000);
    }
  }

  // 만약 주어진 게임머니 100$를 모두 소진한 경우 게임이 끝납니다.
  // 딜레이 후 게임 머니는 다시 100$로 회복되며 게임이 다시 시작합니다.
  if(money == 0) {
    lcd.setCursor(0, 0);
    lcd.print("!! GAME OVER !! ");
    lcd.setCursor(0, 1);
    lcd.print("----- $ 0 ------");
    delay(3000);
    money = money + 100;
  }

}

void randomnum() {
  // 숫자 값 3개를 랜덤으로 롤링합니다.
  
  val1 = random(1, 8);
  val2 = random(1, 8);
  val3 = random(1, 8); 
}
