#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'*', '0', '#', 'D'},
  {'7', '8', '9', 'C'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal_I2C lcd(0x27, 20, 4); 

String v_passcode="";
char data; // variable contenant le caractère lu
char ok='1';

void setup(){
  Serial.begin(9600);
     lcd.backlight();
     lcd.init(); 
}

void loop(){
  char key = customKeypad.getKey();
       data=Serial.read();  


/*****************************************************************************/
/*
do{
          lcd.setCursor(15, 0); 
          lcd.print(":");
          delay(1000);                // waits for a second
          lcd.setCursor(15, 0); 
          lcd.print(" ");
          delay(1000); 
}while(ok!='0');
*/
/*****************************************************************************/

  if (key != NO_KEY){
    
    v_passcode = v_passcode + key;
          lcd.setCursor(4, 1); 
          lcd.print(v_passcode);
        
    if(key=='A')
    {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Enter Product :");
        
        lcd.setCursor(4, 1); 
        v_passcode="#EV000";
        lcd.print(v_passcode);

    }
    
    if(key=='D')
    {
          lcd.clear();
          lcd.print(v_passcode);
          lcd.setCursor(0, 1);
          if(Serial.available()){
               Serial.print(v_passcode);
                if (data='1'){
                    lcd.clear();
                    lcd.print("PROD Dispo");
                }else if (data='0'){
                    lcd.clear();
                    lcd.print("PROD NON Dispo");
                }      
          }
    }        
  }
}


/*
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <String.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'*', '0', '#', 'D'},
  {'7', '8', '9', 'C'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal_I2C lcd(0x27, 20, 4);  

void setup(){
  Serial.begin(9600);
    lcd.backlight();
  lcd.init(); 

}
  
void loop(){
  char customKey = customKeypad.getKey();
  int a;
 String msg;
 int data=Serial.read();
  if(Serial.available()){
   
  if (data=='1'){
        lcd.clear();
      msg="   Disponible";
  }else if(data=='2'){
        lcd.clear();
      msg=" Non Disponible";
  }
    lcd.setCursor(0, 1); 
    lcd.print(msg);

    Serial.write(customKey);
  }
  }
  */
  
