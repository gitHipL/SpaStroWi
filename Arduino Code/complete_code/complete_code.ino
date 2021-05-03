//Resistance
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(3, 2); // RX | TX

//defines
#define measureIn1 4
#define measureIn2 5
#define measureIn3 6
#define measureIn4 7

#define resistanceIn A0 //pin used for resistance measurement
#define voltageIn A1    //pin used for voltage measurement

int Vin = 0;       //voltage at analog pin, used for measurement
double Vcc = 4.89; //supply voltage
double Rref;       //reference resistance

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //initialize lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{

  Serial.begin(9600); // Setup der seriellen Verbindung
  pinMode(resistanceIn, INPUT);
  lcd.begin(16, 2);
  lcd.print("Resistance:");

  Serial.begin(9600); // Setup der seriellen Verbindung
  pinMode(voltageIn, INPUT);
  lcd.begin(16, 2);
  lcd.print("Voltage:");
}

double getR()
{
  return ((Vin * Vcc / 1024) * Rref) / (Vcc - (Vin * Vcc / 1024));
}

void loop()
{
  int measure = 0b0000 | measureIn1 | measureIn2 | measureIn3 | measureIn4;
  Serial.print(measure);

  switch (measure)
  {

  //start of resistor measure
  case 0b0000:
    double R;
    Vin = analogRead(resistanceIn);
    Rref = 56;
    R = getR();
    lcd.setCursor(0, 1);
    lcd.print(R);

    break;
  case 0b0001:
    double R;
    Vin = analogRead(resistanceIn);
    Rref = 560;
    R = getR();
    lcd.setCursor(0, 1);
    lcd.print(R);

    break;
  case 0b0010:
    double R;
    Vin = analogRead(resistanceIn);
    Rref = 5600;
    R = getR();
    lcd.setCursor(0, 1);
    lcd.print(R);

    break;
  case 0b0011:
    double R;
    Vin = analogRead(resistanceIn);
    Rref = 56000;
    R = getR();
    lcd.setCursor(0, 1);
    lcd.print(R);

    break;
  case 0b0100:
    double R;
    Vin = analogRead(resistanceIn);
    Rref = 560000;
    R = getR();
    lcd.setCursor(0, 1);
    lcd.print(R);

    break;
  case 0b0101:
    double R;
    Vin = analogRead(resistanceIn);
    Rref = 5600000;
    R = getR();
    lcd.setCursor(0, 1);
    lcd.print(R);

    break;
  //end of resistor measure

  //start of voltage measure
  case 0b0110:
    double U;
    Vin = analogRead(voltageIn); // Pin einlesen
    U = (double)Vin * Vcc / 1024;
    lcd.setCursor(0, 1);
    lcd.print(U);

    break;
  case 0b0111:
    double U;
    Vin = analogRead(voltageIn); // Pin einlesen
    U = (double)(Vin * Vcc / 1024) * 10.49153;
    lcd.setCursor(0, 1);
    lcd.print(U);

    break;
  case 0b1000:
    double U;
    Vin = analogRead(voltageIn); // Pin einlesen
    U = (double)(Vin * Vcc / 1024) * 30.95;
    lcd.setCursor(0, 1);
    lcd.print(U);

    break;
  case 0b1001:
    double U;
    Vin = analogRead(voltageIn); // Pin einlesen
    U = (double)(Vin * Vcc / 1024) * 61.9;
    lcd.setCursor(0, 1);
    lcd.print(U);

    break;
  //end of voltage measure

  //start of current measure
  case 0b1010:

    break;
  case 0b1011:

    break;
  case 0b1100:

    break;
  case 0b1101:

    break;
  //end of current measure
  case 0b1110:

    break;
  case 0b1111:

    break;
  default:

    break;
  }
}
