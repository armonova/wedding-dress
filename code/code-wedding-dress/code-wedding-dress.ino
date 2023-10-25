#include <LiquidCrystal.h>  // usando a biblioteca LiquidCrystal
#include "notes.h"
#include "notes2.h"

#define MESSAGE_1_L1 "xxxx xxxxx"
#define MESSAGE_1_L2 "xxxxxxxx"

// definition o the display pins
const int rs = 13, en = 12, d4 = 8, d5 = 7, d6 = 4, d7 = 2;
const char buzzer = 10;
const char yes = 11, no = 3;
// pin configuration
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// song
// char* mus[] = {"La","Re","Fa","Sol","La","Re", "Fa", "Sol", "Mi", "Pausa", "Sol", "Do", "Fa", "Mi", "Sol", "Do", "Fa", "Mi", "Re", "Fim"}; //Game of Thrones
// int tempo[] = {700, 500, 300, 250, 250, 300, 200, 200, 700, 200, 500, 500, 200, 200, 200, 500, 200, 200, 500};
// char* mus[] = {"La","Pausa","La","Pausa","La","Pausa","Fa","Do","La","Pausa","Fa","Do","La","Pausa","Mi","Pausa","Mi","Pausa","Mi","Pausa","Fa","Do","Sol","Pausa","Fa","Do","La","Pausa","La","Pausa","La","Pausa","La","Pausa","La","Pausa","Sol#","Pausa","Sol","Fa#","Fa","Fa#","Fim"}; //Marcha Imperial
// int tempo[] = {400, 100, 400, 100, 400, 100, 300, 200, 300, 100, 300, 200, 300, 200, 400, 100, 400, 100, 400, 100, 300, 300, 200, 100 , 300, 300, 200, 200, 400, 50, 400, 50, 400, 50, 400, 50, 300, 50, 300, 200, 200, 200};

char* mus[] = { "Do", "Re", "Mi", "Fa", "Sol", "La", "Si", "Fim" };
int tempo[] = { 500, 500, 500, 500, 500, 500, 500 };


// int noteDuration = 0;
// int noteDelay = 0;
// int tempo2 = 200;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(8, 2);  // defining the size of the LCD - 8 columns and 2 lines
  
  pinMode(buzzer, OUTPUT);  // buzzer
  pinMode(yes, INPUT);      // YES button
  pinMode(no, INPUT);       // NO button

  playSong4();
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
  // tone(buzzer,440,1000); //LA
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(10000);
}


void playSong() {
  int tom = 0;
  for (int i = 0; mus[i] != "Fim"; i++) {
    if (mus[i] == "Do") tom = 262;
    if (mus[i] == "Re") tom = 294;
    if (mus[i] == "Mi") tom = 330;
    if (mus[i] == "Fa") tom = 349;
    if (mus[i] == "Sol") tom = 392;
    if (mus[i] == "La") tom = 440;
    if (mus[i] == "Si") tom = 494;

    if (mus[i] == "Do#") tom = 528;

    if (mus[i] == "Re#") tom = 622;
    if (mus[i] == "Fa#") tom = 370;
    if (mus[i] == "Sol#") tom = 415;
    if (mus[i] == "La#") tom = 466;
    if (mus[i] == "Pausa") tom = 0;
    tone(buzzer, tom, tempo[i]);
    delay(tempo[i]);
  }
}

// void playSong2(){
//   for (int i = 0; i < sizeof(melody) / sizeof(melody[0]) / 2; i++) {
//     noteDuration = 1000 / melody[i * 2 + 1];
//     tone(buzzer, melody[i * 2], noteDuration);
//     noteDelay = noteDuration * 1.30;
//     delay(noteDelay);
//     noTone(buzzer);
//   }
//   delay(tempo2); // Adiciona uma pausa entre repetições
// }

void playSong3() {
  for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
      int noteDuration = 1000 / melody[i][1];  // Converte a duração da nota para milissegundos
      tone(buzzer, melody[i][0], noteDuration);  // Pino 8 é onde o buzzer está conectado
      int pauseBetweenNotes = noteDuration * 1.30;  // Pausa entre as notas
      delay(pauseBetweenNotes);
      noTone(8);  // Para a nota
    }
}

void playSong4() {
  for (int thisNote = 0; thisNote < melody_size + 1; thisNote++) {

    int noteDuration = durations[thisNote];
    tone(buzzer, notes[thisNote],noteDuration);

    delay(noteDuration);
    noTone(8);
  }

  delay (100);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Message();
  // buzzer_erro();
//  playSong3()
  //if
}
