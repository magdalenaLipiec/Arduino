/*
 Bachelor Arduino Quadrocopter Project
 DESIGN OF THE QUADROCOPTER CONTROL SYSTEM 
 by Magdalena Lipiec, AiR
 2019, Kielce Univeristy of Technology

 TRANSMITTER MODULE
 */

#include <SPI.h>
#include <nRF24L01.h>   //biblioteka modulu RC 
#include <RF24.h>       //bibliotek modulu RC
#include <Wire.h>


RF24 radio(49, 48);                  // nRF24L01 piny(CE, CSN)
const byte address[6] = "00001";    // adres

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
//throttle & yaw - joystick lewy
//pitch & roll - joystick prawy0
struct Data_Package {
  
  byte sendThrottle;  //kontrola wysokosci
  byte sendYaw;       //obrot CW/CCW
  byte sendPitch;     //pochylenie przod/tyl
  byte sendRoll;      //pochylenie prawo/lewo


};
Data_Package data; //utworz zmienna o powyzszej strukturze



//*********************************************
void setup() {
  Serial.begin(9600); 
  
//zdefiniowanie komunikacji rc
  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);


  
// Set initial default values
// Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
 
  //data.pitch = 127;
  //data.roll = 127;
}


//*********************************************
void loop() {
//odczytanie wszystkicg wejsc analogowych i zmapowanie ich na jedną wartosc bajtowa
  data.sendThrottle = map(analogRead(A0), 0, 1023, 0, 255); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.sendYaw = map(analogRead(A1), 0, 1023, 0, 255);
  data.sendPitch = map(analogRead(A2), 0, 1023, 0, 255);
  data.sendRoll = map(analogRead(A3), 0, 1023, 0, 255);


//wyslij wszystkie dane ze struktury do odbiornika
  radio.write(&data, sizeof(Data_Package));

  Serial.print("potencjometr: ");
  Serial.println(data.sendThrottle);
  //Serial.print("  YAW: ");
  //Serial.print(data.sendYaw);
  //Serial.print("  PITCH: ");
  //Serial.print(data.sendPitch);
  //Serial.print("  ROLL: ");
  //Serial.println(data.sendRoll);

 
}
