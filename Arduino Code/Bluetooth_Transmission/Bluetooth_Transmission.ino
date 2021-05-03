#include <SoftwareSerial.h> 
SoftwareSerial Serial1(3, 2); // RX | TX 
char flag = '0'; 
int LED = 13; 
void setup() 
{    
 Serial.begin(9600);
 Serial1.begin(9600); 
 pinMode(LED, OUTPUT); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
 if (Serial1.available()){
   flag = Serial1.read(); 

 }
   
 if (flag == '1') 
 { 
   digitalWrite(LED, HIGH); 
   Serial.println("LED On"); 
   Serial.println(flag); 
 } 
 else if (flag == '0') 
 { 
   digitalWrite(LED, LOW); 
   Serial.println("LED Off"); 
   Serial.println(flag); 
 } 
}  
