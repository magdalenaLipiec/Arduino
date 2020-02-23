//created by Magdalena Lipiec, 2014 
//odczyt z analoga
//sterowanie serwem potencjometrem

String odebraneDane = "";  //pusty ciag odebranych danych
 
void setup() 
{ 
  Serial.begin(9600);
} 
 
void loop() 
{  
  int potencjometr = analogRead(A5);

  if(Serial.available()>0) { //czy ardek odebral dane
    odebraneDane = Serial.readStringUntil('\n');  //jesli tak to odczytaj do konca znaku linii
  }

  if (odebraneDane == "D") {  //chce w systemie dziesietnym
    Serial.println(potencjometr, DEC);
  } else if (odebraneDane == "H") {
    Serial.println(potencjometr, HEX);
  } else if(odebraneDane == "O") {
    Serial.println(potencjometr, OCT); 
  } else if (odebraneDane  == "B") {
    Serial.println(potencjometr, BIN);
  }

  delay(200);
      

  }    
 
