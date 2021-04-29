 /* Measurning Whell
 *
 *  by Mirko Pavleski,
 *
 *   https://www.youtube.com/channel/UCHLzc76TZel_vCTy0Znvqyw  
 *   
 *  some changes and adjustmets by impexeris as of 2021-04-29
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

int pin1 = 2;
int pin2 = 3;
int pin3 = 4;

int Pos = 0; 
int State;
int LastState;
int IsReset;


const float pi = 3.14;

const float R = 0.0785;
const int N = 20;

float distance = 0;

void setup() { 
  pinMode (pin1 ,INPUT_PULLUP);
  pinMode (pin2 ,INPUT_PULLUP);
  pinMode (pin3, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("MEASURNING WHEEL");
  delay(1000); 
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(30);
  }
  lcd.clear();
  lcd.print("Start measuring ");
 for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
  }
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(30);
  }

lcd.setCursor(7,1);
lcd.blink();

  LastState = digitalRead(pin1);
  LastState = digitalRead(pin2);    
} 

void loop() { 
 
  State = digitalRead(pin1);
   if (State != LastState){    
     if (digitalRead(pin2) != State) { 
       Pos --;
     } 
     else {
       Pos ++;
     }
   distance = ((2*pi*R)/N) * Pos ;
  lcd.setCursor(0, 0);
  lcd.print("Measuring       ");
  lcd.setCursor(0, 1);
  lcd.noBlink();
  lcd.print( distance);
  //lcd.setCursor(5, 1);
  lcd.print("m  ");
   
   } 
   
  LastState = State;
  if (digitalRead(pin3) == 0) {
  distance = 0;
  lcd.setCursor(0, 0);
  lcd.print("     RESET      ");
  lcd.setCursor(0, 1);
  lcd.noBlink();
  lcd.print( distance);
  //lcd.setCursor(5, 1);
  lcd.print("m  ");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Start measuring ");
  }
 }
