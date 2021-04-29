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
       //char data;  
       String msg;


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
    
    if(key=='D'){
      lcd.clear();
      /*******************************ECRIRE UNE CHAINE******************************************/
  for (int i = 0; i < v_passcode.length()-1; i++)
  {
                 Serial.write(v_passcode[i]);   // Push each char 1 by 1 on each loop pass
              // Serial.print(v_passcode[i]); 
  }
      /******************************************************************************************/
         //delay(3000);
         //char data;
         
         if(Serial.available()){
             data=Serial.read();

               //Serial.print(v_passcode);
               //Serial.print(data);        

                if (data=='1'){
                  lcd.clear();
                   msg="DISPO";
                   lcd.setCursor(4, 1);
                     lcd.print(msg);
                              Serial.flush();

                }else if (data=='0'){
                  lcd.clear();
                    msg="NON DISPO";
                    lcd.setCursor(4, 1);
                     lcd.print(msg);
                              Serial.flush();

                } 
     
          }
           
                          
          
    }
        
           //Serial.print("ok");        
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
  
