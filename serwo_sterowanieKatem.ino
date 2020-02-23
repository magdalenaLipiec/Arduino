//MAGDALENA LIPIEC, 2014
//Wpisz o ile stopni chcesz obrócić silniki

#include <Servo.h>  //biblioteka do sewro

Servo serwomechanizm; //tworzymy obiekt dzieki ktoremu mozna sie odwolac do serwo
String ileStopni = "";
int ileStopniInt = 0;


void setup() {
  Serial.begin(9600);
  serwomechanizm.attach(9);
  serwomechanizm.write(0);  //serwo zawsze zaczyna od zerwoej pozycji 
  analog.reaa
}

void loop() {
  Serial.println("Witaj! Podaj ilosc stopni o jaka ma sie obrocic serwo.");
  while( Serial.available() == 0) {}
 
  if(Serial.available() > 0) {  //czy arduino odebralo dane
    ileStopni = Serial.readStringUntil('\n'); //jesli tak odczytaj je do znaku konca lin.
    Serial.println("Serwo obrot o " + ileStopni + " stopni.");
  }

  ileStopniInt = ileStopni.toInt(); //zamiana sting na int

  if(ileStopniInt >= 0 && ileStopniInt <= 180) {
    serwomechanizm.write(ileStopniInt);
  }
    else{
      Serial.println("Podaj liczbe z odpowiedniego zakresu!");
      
    }
}
