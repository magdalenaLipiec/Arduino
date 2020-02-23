//MAGDALENA LIPIEC

String odebraneDane = "";  //pusty ciag odebranych danych

void setup() {
  Serial.begin(9600);
  

}

void loop() {
    if( Serial.available() > 0) { //czy arduno odebralo dane
      odebraneDane = Serial.readStringUntil('\n');  //jesli tak to odczytaj je do znaku konca linii
      Serial.println("Witaj " +odebraneDane ); //wyswyetl komunikat
    }

}
