#include <LiquidCrystal.h>      // usando a biblioteca LiquidCrystal

#define MESSAGE_1_L1 "xxxx xxxxx"
#define MESSAGE_1_L2 "xxxxxxxx"

// definition o the display pins
const int rs = 13, en = 12, d4 = 8, d5 = 7, d6 = 4, d7 = 2;
// pin configuration
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  
  lcd.begin(8, 2); // defining the size of the LCD - 8 columns and 2 lines

  digitalWrite(13, HIGH);
}

void Message () {
  lcd.clear(); // Limpa o display
  lcd.setCursor(9, 0); // 2 = 2 colunas para a direita. 0 = Primeira linha
  lcd.print(MESSAGE_1_L1); // Imprime um texto
  lcd.setCursor(10, 1); // 2 = 2 colunas para a direita. 1 = Segunda linha
  lcd.print(MESSAGE_1_L2);

  for(int pos=0;pos<19;pos++){ //create the ilusion of animation
    //lcd.scrollDisplayRight();
    lcd.scrollDisplayLeft();
    delay(350);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Message();
}
