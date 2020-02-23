//MAGDALENA LIPIEC

void setup() {
  //pin 6 i 5(PWM) REGULACJA PREDKOSCI 
  //pin 7,8 i 2,4 STEROWANIE KIERUNKIEM OBROTÓW
  
  pinMode(6, OUTPUT); //sygnal PWM silnika nr1

  //pinMode(5, OUTPUT); //sygnal PWM silnika nr2
  
  pinMode(7, OUTPUT); //sygnaly sterujace kierunkiem obrotow silnik nr1
  pinMode(8, OUTPUT);

  //pinMode(2, OUTPUT); //sygnaly sterujace kierunkiem obrotow silnik nr2
  //pinMode(4, OUTPUT);
}

void loop() {

 analogWrite(6, 100);  //niska predkosc obrotow silnik nr1
 digitalWrite(7, LOW);  //silnik nr1 OBROTY W LEWO
 digitalWrite(8, HIGH); //silnik nr! OBROTY W PRAWO
 delay(3000);

 analogWrite(6, 255); //maksymalna predkosc obrotow silnik nr1
 digitalWrite(7, LOW);  //silnik nr1 OBROTY W PRAWWO
 digitalWrite(8, HIGH);
 delay(3000);

 
 
 

}
