//MAGDALENA LIPIEC, 2014
//HEX DEC

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

  if(odebraneDane == "zielona") { //jesli wpiszemy zielona to zapali sie zeilona
    digitalWrite(7, HIGH);
    digitalWrite(8,LOW);
  }

  else if(odebraneDane == "zolta") {  //jesli wpiszemy zeolta to zapali sie zolta
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
  }

  else if ((odebraneDane != "zolta") || (odebraneDane != "zielona") || (odebraneDane > 0)) {
    Serial.println("Napisz zielona lub zolta");
  }
}    
