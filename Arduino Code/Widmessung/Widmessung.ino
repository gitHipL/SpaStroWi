#include <LiquidCrystal.h>

int analogPin = A0;
double Vin = 0;
double Vcc = 4.89;
double Rref = 9940;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600); // Setup der seriellen Verbindung
  pinMode(analogPin, INPUT); 
  lcd.begin(16, 2);
  lcd.print("Resistance:");
}

double getR(){
  return ((Vin*Vcc/1024)*Rref)/ (Vcc - (Vin*Vcc/1024));
 }


void loop() {
  double R;
  Vin = analogRead(analogPin);
  R = getR();
  lcd.setCursor(0, 1);
  lcd.print(R);
  
  Serial.println(Vin);
}
