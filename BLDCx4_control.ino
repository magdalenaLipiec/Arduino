//MAGDALENA LIPIEC
//sterowanie 4 silnikami bldc

#include <Servo.h>
//Servo bldc1; //inicjalizacja silnikow
Servo bldc2;
Servo bldc3;
Servo bldc4;


void setup() {

//int wartosc = 200; 


//bldc1.attach(5);  //przypisanie silnika do pinu 5
//bldc1.writeMicroseconds(1000);

bldc2.attach(6);
bldc2.writeMicroseconds(1000);

bldc3.attach(9);
bldc3.writeMicroseconds(1000);

bldc4.attach(10);
bldc4.writeMicroseconds(1000);


Serial.begin(9600);
}

void loop() {

//ustawienie wyskosci drona
int high = analogRead(A0); //zmienna high odczytuje wartosc z analoga
int mappedhigh = map(high, 0, 1023, 1000, 2000); 
//bldc1.writeMicroseconds(high); //ustawienie odpowiednich obrotow wszytskich silnikow
bldc2.writeMicroseconds(mappedhigh);
bldc3.writeMicroseconds(mappedhigh);
bldc4.writeMicroseconds(mappedhigh);

Serial.println(mappedhigh);
delay(100);
}
