#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);         


int lcd_key     = 0;
int adc_key_in  = 0;
int calc_total;
int display_options;
int Relay1Pin = 3;
int Relay2Pin = 11;
int Relay3Pin = 12;
int Relay4Pin = 13;
int MenuOption = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int read_LCD_buttons(){              
    adc_key_in = analogRead(0);     

  

    if (adc_key_in > 1000) return btnNONE; 


    if (adc_key_in < 50)   return btnRIGHT;  
    if (adc_key_in < 150)  return btnUP; 
    if (adc_key_in < 300)  return btnDOWN; 
    if (adc_key_in < 450)  return btnLEFT; 
    if (adc_key_in < 700)  return btnSELECT;  

  

    return btnNONE;      
    
}

void setup(){
   lcd.begin(16, 2);              
   lcd.setCursor(0,0);    
   lcd.print ("MixIT");
   pinMode(3, OUTPUT);  
   pinMode(11, OUTPUT); 
   pinMode(12, OUTPUT); 
   pinMode(13, OUTPUT); 
    Serial.begin(9600);
    Serial.print(MenuOption);

}
 
void loop(){
  
         
   lcd_key = read_LCD_buttons();  
   

   switch (lcd_key){              
    
       case btnRIGHT:{  
          lcd.clear();
            lcd.setCursor(0,1);
            calc_total = calc_total + 1;
            calc_total = constrain(calc_total,1, 14);
            lcd.print (calc_total);
            delay(700);
            break;
       }
       case btnLEFT:{
         lcd.clear();
            lcd.setCursor(0,1); 
            calc_total = calc_total - 1;
            calc_total = constrain(calc_total,1, 14);
            lcd.print(calc_total);
            delay(700); 
            break;
            
       }
       case btnSELECT:{
       MenuOption = 1;
       Serial.print(MenuOption);
        delay(700);
        break;
        }
     }
     
    if (calc_total == 1){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 1");   
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(3, HIGH);
      }
      
    }
    else if (calc_total == 2){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 2");
       if (MenuOption == 1){
      digitalWrite(11, LOW);
      delay(10000);
      MenuOption = 0;
      digitalWrite(11, HIGH);
      }
    }
    else if (calc_total == 3){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 3");
      if (MenuOption == 1){
      digitalWrite(12, LOW);
      delay(10000);
      MenuOption = 0;
      digitalWrite(12, HIGH);
      }
    }
    else if (calc_total == 4){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 4");
      if (MenuOption == 1){
      digitalWrite(13, LOW);
      delay(10000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
    else if (calc_total == 5){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 5");
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(8000);
      digitalWrite(3, HIGH);
       digitalWrite(11, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(11, HIGH);
      }
    }
     else if (calc_total == 6){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 6");
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(8000);
      digitalWrite(3, HIGH);
       digitalWrite(12, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(12, HIGH);
      }
    }
     else if (calc_total == 7){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 7");
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(8000);
      digitalWrite(3, HIGH);
       digitalWrite(13, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
     else if (calc_total == 8){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 8");
      if (MenuOption == 1){
      digitalWrite(11, LOW);
      delay(8000);
      digitalWrite(11, HIGH);
       digitalWrite(12, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(12, HIGH);
      }
    }
     else if (calc_total == 9){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 9");
      if (MenuOption == 1){
      digitalWrite(11, LOW);
      delay(8000);
      digitalWrite(11, HIGH);
       digitalWrite(13, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
    else if (calc_total == 10){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 10");
      if (MenuOption == 1){
      digitalWrite(12, LOW);
      delay(8000);
      digitalWrite(12, HIGH);
       digitalWrite(13, LOW);
      delay(8000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
    else if (calc_total == 11){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 11");
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(4000);
      digitalWrite(3, HIGH);
       digitalWrite(11, LOW);
      delay(4000);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      delay(4000);
      MenuOption = 0;
      digitalWrite(12, HIGH);
      }
    }
    else if (calc_total == 12){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 12");
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(4000);
      digitalWrite(3, HIGH);
       digitalWrite(11, LOW);
      delay(4000);
      digitalWrite(11, HIGH);
      digitalWrite(13, LOW);
      delay(4000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
    else if (calc_total == 13){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 13");
      if (MenuOption == 1){
      digitalWrite(3, LOW);
      delay(4000);
      digitalWrite(3, HIGH);
       digitalWrite(12, LOW);
      delay(4000);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      delay(4000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
     else if (calc_total == 14){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 14");
      if (MenuOption == 1){
      digitalWrite(11, LOW);
      delay(4000);
      digitalWrite(11, HIGH);
       digitalWrite(12, LOW);
      delay(4000);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      delay(4000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
    else if (calc_total == 15){
      lcd.setCursor(0,0); 
      lcd.print("Menu Option 15");
      if (MenuOption == 1){
        digitalWrite(3, LOW);
      delay(2000);
      digitalWrite(3, HIGH);
      digitalWrite(11, LOW);
      delay(2000);
      digitalWrite(11, HIGH);
       digitalWrite(12, LOW);
      delay(2000);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      delay(2000);
      MenuOption = 0;
      digitalWrite(13, HIGH);
      }
    }
    else{
      digitalWrite(3, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
    }
     
   
    
}
