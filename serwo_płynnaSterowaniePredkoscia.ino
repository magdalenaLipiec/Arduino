//MAGDALENA LIPIEC
//płynne sterowanie prędkością silników

void setup() {
  //pin 6 i 5(PWM) REGULACJA PREDKOSCI 
  //pin 7,8 i 2,4 STEROWANIE KIERUNKIEM OBROTÓW
  
  pinMode(6, OUTPUT); //sygnal PWM silnika nr1

  pinMode(5, OUTPUT);  //sygnal PWM silnika nr2
  
  
  pinMode(7, OUTPUT); //sygnaly sterujace kierunkiem obrotow silnik nr1
  pinMode(8, OUTPUT);

  pinMode(2, OUTPUT); //sygnaly sterujace kierunkiem obrotow silnik nr2
  pinMode(4, OUTPUT);


  digitalWrite(7, LOW); // silnik nr1 OBROTY W LEWO
  digitalWrite(8, HIGH);  

  digitalWrite(2, LOW); //silnik nr2 OBROTY W LEWO
  digitalWrite(4, HIGH);
}

void loop() {

  for (int i = 0; i <= 255; i++) {
    analogWrite(6, i);  //spokojne rozpedzanie silnika nr1
    analogWrite(5, i);  //spokojne rozpedzanie silnika nr2
    delay(25);
  }

  for(int i = 255; i >= 0; i--) {
    analogWrite(6, i);  //spokojne hamowanie silnika nr1
    analogWrite(5, i);  //spokojne hamowanie silnika nr2
    delay(25);
  }

}
