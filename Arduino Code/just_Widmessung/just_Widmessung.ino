
int analogPin = A0;
double Vin = 0;
double Vcc = 4.90;
double Rref = 9795;



void setup() {
  Serial.begin(9600); // Setup der seriellen Verbindung
  pinMode(analogPin, INPUT); 
}

double getR(){
  return ((Vin*Vcc/1024)*Rref)/ (Vcc - (Vin*Vcc/1024));
 }


void loop() {
  double R;
  Vin = analogRead(analogPin);
  R = getR();
  
  Serial.println(R);
}
