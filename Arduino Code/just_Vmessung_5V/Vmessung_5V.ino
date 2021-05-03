int analogPin = A1; // Pin, der gelesen werden soll: Pin A1
double Vcc = 4.9;
void setup()
{
  Serial.begin(9600); // Setup der seriellen Verbindung
  pinMode(analogPin, INPUT);
}

void loop()
{

  double U;
  int Vin;
  Vin = analogRead(analogPin); // Pin einlesen
  U = (double)Vin * Vcc / 1024;

  Serial.println(U); // Wert ausgeben
}
