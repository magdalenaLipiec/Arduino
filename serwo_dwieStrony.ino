//MAGDALENA LIPIEC, 2014
//Obtrót serwa w jedną i drugą stronę 


#include <Servo.h> //Biblioteka odpowiedzialna za serwa
 
Servo serwomechanizm;  
int pozycja = 0; 
int petla = 1;
int zmiana = 1; 
 
void setup() 
{ 
  serwomechanizm.attach(9);  //Serwomechanizm podłączony do pinu 9
} 
 
void loop() 
{  
  if(petla == 1){
    if(pozycja < 180){
    serwomechanizm.write(pozycja);
    pozycja = pozycja + zmiana;  
    delay(50);                      
  }
    else{
      petla = 2;
    }
  }
    if(petla == 2){
      if(pozycja > 0){
        serwomechanizm.write(pozycja);
        pozycja = pozycja - zmiana;
        delay(50);
      }
        else{
          petla = 1;
        }
    }
}
