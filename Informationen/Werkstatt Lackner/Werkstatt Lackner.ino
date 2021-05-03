#include <SoftwareSerial.h>
SoftwareSerial Serial2(A4,A5); //(Rx,Tx)

/*7seg
 * 0  = oben
 * 1 = rechts oben
 * 2 = rechts unten
 * 3 = unten
 * 4 = links unten
 * 5 = links oben
 * 6 = Mitte
 */

char zahl='3';

void turnOff() {

  pinMode(10, OUTPUT);  
  pinMode(12, INPUT);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);

}

void turnOffRGB() {

  pinMode(12, OUTPUT);  
  pinMode(10, INPUT); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);

}


void setup() { // Pins initalisieren

   Serial2.begin(19200);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);



  pinMode(13, OUTPUT);    //LED
 digitalWrite(13, LOW);



}

void loop() {           // Die LEDS für die Zahlen bei den Cases werden auf HIGH bzw LOW geschaltet

   if(Serial2.available() > 0){
    zahl = Serial2.read();
    Serial2.write(zahl);
    
  }
  switch (zahl){
    case '0': 
    turnOff();
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    
    break;
    case '1':
    turnOff();
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    
    break;
    case '2':
    turnOff();
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
   
    break;
    case '3':
    turnOff();
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    
    break;
    case '4':
    turnOff();
     digitalWrite(1,LOW);
     digitalWrite(2,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
   
    break;
    case '5':
    turnOff();
     digitalWrite(0,LOW);
     digitalWrite(2,LOW);
     digitalWrite(3,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
    
    break;
    case '6':
    turnOff();
     digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(1,LOW);
    digitalWrite(6,LOW);
    
    break;
    case '7':
    turnOff();
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    
    break;
    case '8':
    turnOff();
     digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    
    break;
    case '9':
    turnOff();
     digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
 
    break;
    
    case 'o':
    turnOffRGB();
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    break;




    
     case 'r':
    turnOffRGB();
    digitalWrite(5,LOW);
    break;
    
     case 'g':
    turnOffRGB();
    digitalWrite(6,LOW);  
    break;
    
     case 'y':
    turnOffRGB();
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    break;
    
     case 'b':
    turnOffRGB();
    digitalWrite(9,LOW);
    break;
    
     case 'v':
    turnOffRGB();
    digitalWrite(5,LOW);
    digitalWrite(9,LOW);
    break;
    
     case 'l':
    turnOffRGB();
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    break;
    
     case 'w':
    turnOffRGB();
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    break;


      
  case '?':
   digitalWrite (13, LOW);
    break;
      
  case '!':
  digitalWrite(13, HIGH);
    break;




  /*   case 'x':
     
      digitalWrite(A5, HIGH);
      delay(1000);
    
    
    break;

     case 'z':
  digitalWrite(A5, LOW);
    break;
  }    
*/
  
  }
}
