//MAGDALENA LIPIEC, 2014
//Wpisz, który kolor diody chcesz zapalić

String odebraneDane = "";  //pusty ciag odebranych danych
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(7, OUTPUT); //dioda zielona
  pinMode(8, OUTPUT); //dioda zolta
  digitalWrite(7, LOW); //wylaczamy diody
  digitalWrite(8, LOW);
} 
 
void loop() {

  if(Serial.available()>0) {  //jesli ardek odebral dane tp
    odebraneDane = Serial.readStringUntil('\n');
  }

  switch( odebraneDane) {
    case "zielona":
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    break;
  
  case "zolta":
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  break

  }
}
