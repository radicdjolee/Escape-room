#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h" //if you want use other than pin 1 and 2 for serial

unsigned int ir_val = 0; //IR Sensor

unsigned int d_val = 1; //Outside drawer

unsigned int r_val = 1; //Rotor
unsigned int r_check = 0;

unsigned int sw_val = 1; //Switches
unsigned int sw_check = 0;

unsigned int o_val = 1; //Open inside drawer
unsigned int o_check = 0;

unsigned int c_val = 1; //Open inside drawer
unsigned int c_check = 0;

unsigned long start = 0; //Timer
unsigned long start1 = 0;
unsigned long m = 0;

SoftwareSerial mySoftwareSerial(0,1); // RX, TX any pins you need

DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);//set speed for SoftwareSerial

  Serial.begin(9600);   //set speed for Hardware  Serial pin 1 and 2 tx/rx

  myDFPlayer.begin(Serial);//select Serial to send comand to dfplayer

  myDFPlayer.volume(25);  //Set volume value. From 0 to 30

  //LED Panel
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(2, OUTPUT);
}

// loop will playback track 1 repeatedly at 2 seconds interval:

void loop() {
  
  delay(100);
  o_val = analogRead(A6);
      
  while( o_val < 10 ){
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(1000);
    o_val = analogRead(A6);
  }

  ir_val = analogRead(A2);

  if( ir_val > 100 ){

    start = millis();

    //LED Panel   
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
 
    myDFPlayer.play(1);
    delay(20000);
    
    while(1){
    
      start1 = millis()-start;
      m = ( ( start1 / 60000 ) - ( ( start1 / 3600000 ) * 60 ) );            
      
      switch( m ) {
        case 5:
          digitalWrite(2,LOW);
          break;
        case 10:
          digitalWrite(3,LOW);
          break;
        case 15:
          digitalWrite(4,LOW);
          break;
        case 20:
          digitalWrite(5,LOW);
          break;
        case 25:
          digitalWrite(6,LOW);
          break;
        case 30:
          digitalWrite(7,LOW);
          break;
        case 35:
          digitalWrite(8,LOW);
          break;
        case 40:
          digitalWrite(9,LOW);
          break;
        case 45:
          digitalWrite(10,LOW);
          break;
        case 50:
          digitalWrite(11,LOW);
          break;
        case 55:
          digitalWrite(12,LOW);
          break;
        case 60:
          digitalWrite(13,LOW);
          myDFPlayer.play(7);
          delay(12000);
          while(1);
          break;
      }

      delay(100);
     
      d_val = analogRead(A3);

      if( d_val < 5 ){
          myDFPlayer.play(2);
          delay(1000);              
      }

      r_val = analogRead(A4);
      
      if( r_val < 10 ){
        if( r_check == 0 ){
          r_check = 1;
          myDFPlayer.play(3);
          delay(18000); 
        }       
      }  
      
      o_val = analogRead(A6);
      
      if( o_val < 20 ){
        if( o_check == 0 ){
          o_check = 1;
          myDFPlayer.play(5);
          delay(24000);
          delay(120000); // ceka 2 min
          myDFPlayer.play(6);
          delay(70000);
          while(1);
        }       
      }  

      sw_val = analogRead(A1);
      
      if( sw_val > 70 ){
        if( sw_check == 0 ){
          sw_check = 1;
          myDFPlayer.play(4);
          delay(4000);    
        }
      }

    } // end WHILE
    
  } //end IF

} //END
