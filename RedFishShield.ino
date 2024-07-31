#include "DigiKeyboard.h"

int SELECTPIN = 0;
int pwd = 0; //0: "Welcome", 1: "To", 2: "Paradise"
String pwdok = "";

int TOUCHPIN = 1;
int LEDPIN = 1;

void setup() {
  pinMode(SELECTPIN, INPUT);
  pinMode(TOUCHPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
}


void loop()
{

  if(digitalRead(SELECTPIN)==HIGH)
  {
    pwd = pwd + 1;
    if (pwd > 3) pwd = 0;
    DigiKeyboard.delay(50);
  }

  if(digitalRead(TOUCHPIN)==HIGH)
  {
    // START
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(50);

    // WRITE PASSWORD
    switch (pwd) {
      case 0:
        pwdok = "Welcome";
        break;
      case 1:
        pwdok = "To";
        break;
      case 2:
        pwdok = "Paradise";
        break;        
      default:
        pwdok = "Administrator";
        break;
    }

    DigiKeyboard.print(pwdok);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
   
    digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    DigiKeyboard.delay(100);
    digitalWrite(LEDPIN, LOW);
    DigiKeyboard.delay(100);
     
    // THE END
    DigiKeyboard.delay(100);
   
  }

DigiKeyboard.delay(100);

}