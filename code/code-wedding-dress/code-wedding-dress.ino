#include <LiquidCrystal.h>  // usando a biblioteca LiquidCrystal
#include "notes.h"
#include "notes2.h"

#define MESSAGE_1_L1 "xxxx xxxxx"
#define MESSAGE_1_L2 "xxxxxxxx"

// definition o the display pins
const int rs = 6, en = 12, d4 = 8, d5 = 7, d6 = 4, d7 = 2;
const char buzzer = 10;
const char yes = 11, no = 3;
const char ledYes = 13, ledNo = 5;
// pin configuration
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(8, 2);  // defining the size of the LCD - 8 columns and 2 lines
  
  pinMode(buzzer, OUTPUT);  // buzzer
  pinMode(ledYes, OUTPUT);  // led Yes
  pinMode(ledNo, OUTPUT);   // led No
  pinMode(yes, INPUT);      // YES button
  pinMode(no, INPUT);       // NO button

  lcd.createChar(0, Heart1);
  lcd.createChar(1, Heart2);
  //playSong4();
}

void Message() {
  lcd.clear();              // Limpa o display
  lcd.setCursor(9, 0);      // 2 = 2 colunas para a direita. 0 = Primeira linha
  lcd.print(MESSAGE_1_L1);  // Imprime um texto
  lcd.setCursor(10, 1);     // 2 = 2 colunas para a direita. 1 = Segunda linha
  lcd.print(MESSAGE_1_L2);

  for (int pos = 0; pos < 19; pos++) {  //create the ilusion of animation
    //lcd.scrollDisplayRight();
    lcd.scrollDisplayLeft();
    delay(350);
  }
}

void buzzer_erro() {
  digitalWrite(ledNo, HIGH);
  lcd.clear();              // Limpa o display
  lcd.setCursor(0, 0);      // 2 = 2 colunas para a direita. 0 = Primeira linha
  lcd.print("RESPOSTA");  // Imprime um texto
  lcd.setCursor(1, 1);     // 2 = 2 colunas para a direita. 1 = Segunda linha
  lcd.print("ERRADA");
  
  tone(buzzer, NOTE_D5, 2500);
  noTone(8);
  delay(2500);
  digitalWrite(ledNo, LOW);
}

void playSong4() {
  lcd.clear();
  // HEAT LATHUR HEART
  lcd.setCursor(0, 0);
  lcd.write(byte(1));
  lcd.setCursor(1, 0);
  lcd.write("LATHUR");
  lcd.setCursor(7, 0);
  lcd.write(byte(1));
  // Many hearts
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(3, 1);
  lcd.write(byte(0));
  lcd.setCursor(4, 1);
  lcd.write(byte(0));
  lcd.setCursor(7, 1);
  lcd.write(byte(0));
  
  
  for (int thisNote = 0; thisNote < melody_size + 1; thisNote++) {
    digitalWrite(ledYes, !digitalRead(ledYes));
    int noteDuration = durations[thisNote];
    tone(buzzer, notes[thisNote],noteDuration);

    delay(noteDuration);
    noTone(8);
  }

  delay (100);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Message();

  lcd.clear();              // Limpa o display
  lcd.setCursor(9, 0);      // 2 = 2 colunas para a direita. 0 = Primeira linha
  lcd.print(MESSAGE_1_L1);  // Imprime um texto
  lcd.setCursor(10, 1);     // 2 = 2 colunas para a direita. 1 = Segunda linha
  lcd.print(MESSAGE_1_L2);

  for (int pos = 0; pos < 19; pos++) {  //create the ilusion of animation
    //lcd.scrollDisplayRight();
    lcd.scrollDisplayLeft();
    if (digitalRead(yes) == HIGH){
      playSong4();
    }
    if (digitalRead(no) == HIGH) {
      pos = 19;
      buzzer_erro();
    }
    delay(350);
  }
}
