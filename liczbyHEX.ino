//MAGDALENA LIPIEC
//liczy hex

int potencjometr = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("liczba \t HEX \t OCT \t BIN\n");
  

}

void loop() {
  int potencjometr = analogRead(A5);
  Serial.print("Odczyt: ");
  Serial.print(potencjometr, DEC);
  Serial.print("[DEC]\t");
  Serial.print(potencjometr, HEX);
  Serial.print("[HEX]\t");
  Serial.print(potencjometr, OCT); 
  Serial.print("[OCT]\t");
  Serial.print(potencjometr, BIN); 
  Serial.print("[BIN]\n");
  
  
  delay(1000);
}
