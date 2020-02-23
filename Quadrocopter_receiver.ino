/*
 Bachelor Arduino Quadrocopter Project
 by Magdalena Lipiec, AiR
 2019, Kielce Univeristy of Technology

RECEIVER MODULE
 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include <Wire.h>

RF24 radio(9, 10);                  // nRF24L01 piny(CE, CSN)
const byte address[6] = "00001";    //adres
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

//inicjalizacjia silnikow
Servo bldc1;
Servo bldc2;
Servo bldc3;
Servo bldc4;


// Max size of this struct is 32 bytes - NRF24L01 buffer limit
//throttle - potencjometr
//yaw - -
//pitch & roll - joystick prawy
struct Data_Package {
  
  byte sendThrottle;  //kontrola wysokosci
  byte sendYaw;       //obrot CW/CCW
  byte sendPitch;     //pochylenie przod/tyl
  byte sendRoll;      //pochylenie prawo/lewo

};
Data_Package data; //Create a variable with the above structure

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();             //ustawienie modulu jako ODBIORNIK
 // resetData();

//przypisanie kazdego silnika do odpowiednich pinow
bldc1.attach(5); 
bldc1.writeMicroseconds(1000); 

bldc2.attach(6); //CW
bldc2.writeMicroseconds(1000);

//bldc3.attach(9); //CW
bldc3.writeMicroseconds(1000);
 
//bldc4.attach(10); 
bldc4.writeMicroseconds(1000); 
}


void loop() {
  // Check whether we keep receving data, or we have a connection between the two modules
  currentTime = millis();
  if ( currentTime - lastReceiveTime > 1000 ) { // If current time is more then 1 second since we have recived the last data, that means we have lost connection
    resetData(); // If connection is lost, reset the data. It prevents unwanted behavior, for example if a drone jas a throttle up, if we lose connection it can keep flying away if we dont reset the function
  }
  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    lastReceiveTime = millis(); // At this moment we have received the data
  }
 
  // Controlling brushless motor with ESC
  int throttle = map(data.sendThrottle, 0, 255, 1000, 2000); // Map the receiving value form 0 to 255 to 0 1000 to 2000, values used for controlling ESCs
  int yaw = map(data.sendYaw, 0, 255, 1000, 2000);
  int pitch = map(data.sendPitch, 0, 255, 1000, 2000);
  int roll = map(data.sendRoll, 0, 255, 1000, 2000);

  
 //*****************************STEROWANIE**************************
 // WYSLIJ PWM DO ESC 
int wartosc = 200;
int wypoziomowanie = 0;


//******************************************************************

//THROTTLE - kontrola wysokosci   
  bldc1.writeMicroseconds(throttle); 
  bldc2.writeMicroseconds(throttle);
  bldc3.writeMicroseconds(throttle);
  bldc4.writeMicroseconds(throttle);

  


//wyswietl wartosci na monitorze  
  Serial.print("THROTTLE: ");
  Serial.println(throttle);
//  Serial.print("  YAW: ");
//  Serial.print(CW);
//  Serial.print(" ");
//  Serial.print(CCW);
 // Serial.print("  PITCH: ");
//  Serial.print(forward);
 // Serial.println("  ROLL: ");
  //Serial.println();

}
void resetData() {
  // Reset the values when there is no radio connection - Set initial default values
 // data.throttle = 127;
//  data.yaw = 127;
 // data.pitch = 127;
 // data.roll = 127;

}
