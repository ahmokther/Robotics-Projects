#include <LiquidCrystal.h> // lcd library
LiquidCrystal lcd(3, 4, 5, 6, 7, 8); // pin 8 connect Rs, pin 7 connect E(Enable)
                                      // pin 6 connect D4, 5 connect D5, 4 connect D6, 3 connect D7.
#include<Servo.h>    // servo library.
Servo myservo;       // define servo name.
int ldr1 = A0;      // set ldr1 value pin no A0.
int ldr2 = A1;     // set ldr2 value pin no A1.
int ldrV1;       
int ldrV2;
int a1;
int a2;
void setup() {
  Serial.begin(9600);    // Serial communication.
  lcd.begin(16, 2);      // for lcd
  myservo.attach(9);     // Servo Pin connect arduino 9 no pin.
  pinMode(ldr1,INPUT);   // ldr1 as an input.
  pinMode(ldr2,INPUT);   // ldr2 as an input
  

}

void loop() {
   lcd.print("Sun light Value");  // lcd string show.
   lcd.setCursor(0, 1);           // setCursor column 0 and row 1.
   lcd.print("E:");               // print value column 0 to 2 and row 1.
   lcd.setCursor(8, 1);          // setCursor column 8 and row 1.
   lcd.print("W:");              // print value column 8 to 10 and row 1.
   ldrV1 = analogRead(ldr1);    // sensor value reading.
   ldrV2 = analogRead(ldr2);    // sensor value reading.
   lcd.setCursor(4,1);          //setCursor column 4 and row 1.
   lcd.print(ldrV1);            //print value column 4 and row 1
   lcd.setCursor(12,1);         //setCursor column 12 and row 1.
   lcd.print(ldrV2);            //print value column 12 and row 1
   delay(1000);                  // delay 1 sec.
   lcd.clear();                 // clear screen.
   
   if(ldrV2 >=150 ){
        
        a1 = map(ldrV2 ,150,500,90,170);
        myservo.write(a1);    // servo move 90 to 170 degree.
        
        }
   else if(ldrV1 >=150 ){
         
        
        a2 = map(ldrV1 ,150,500,90,10); 
        myservo.write(a2);    // servo move 170 degree.
            
    }

   else if(ldrV1 >=200 && ldrV2 >=200 || ldrV1 == ldrV2){
    
     myservo.write(90);   // servo move 90 degree.
     
    }
   else{
    
    myservo.write(90);   // servo move 90 degree.
    
    }
    
   
}
