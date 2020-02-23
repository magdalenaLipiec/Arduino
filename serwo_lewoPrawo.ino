//MAGDALENA LIPIEC

void setup() {
  //pin 6(PWM) REGULACJA PREDKOSCI 
  //pin 7,8 STEROWANIE KIERUNKIEM OBROTÓW
  
  pinMode(6, OUTPUT); //sygnal PWM silnika nr1
  digitalWrite(6, HIGH);  //ustawiamy (na stale) stan wysoki na pinie 6

  pinMode(7, OUTPUT); //sygnaly sterujace kierunkiem obrotow
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(7, LOW);  //silnik nr1 OBROTY W LEWO
  digitalWrite(8, HIGH);
  delay(3000);
  
  digitalWrite(7, HIGH);  //silnik nr1 OBROTY W PRAWO
  digitalWrite(8, LOW); 
  delay(3000);

}
