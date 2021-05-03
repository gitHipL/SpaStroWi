#include <LiquidCrystal.h>

int analogPin = A1; // Pin, der gelesen werden soll: Pin A1
double Vcc = 4.9;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600); // Setup der seriellen Verbindung
  pinMode(analogPin, INPUT); 
  lcd.begin(16, 2);
  lcd.print("Voltage:");
}

void loop() {
  double U;
  int Vin;
  Vin = analogRead(analogPin); // Pin einlesen
  U = (double) Vin*Vcc/1024;
  lcd.setCursor(0, 1);
  lcd.print(U);
  
  Serial.println(U); // Wert ausgeben
}
