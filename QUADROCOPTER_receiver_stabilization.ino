/*
 Bachelor Arduino Quadrocopter Project
 DESIGN OF THE QUADROCOPTER CONTROL SYSTEM 
 by Magdalena Lipiec, AiR
 2019, Kielce Univeristy of Technology

RECEIVER MODULE
 */

#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include <MPU9250.h>  //akcelerometr


//MODUL RC
RF24 radio(7, 8);                  // nRF24L01 piny(CE, CSN)
const byte address[6] = "00001";    //adres
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

//MPU9250
// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;

//INICJALIZACJA SILNIKOW
Servo bldc1;
Servo bldc2;
Servo bldc3;
Servo bldc4;


// Max size of this struct is 32 bytes - NRF24L01 buffer limit

//KANALY
struct Data_Package {
  byte sendThrottle;  //kontrola wysokosci
  byte sendYaw;       //obrot CW/CCW
  byte sendPitch;     //pochylenie przod/tyl
  byte sendRoll;      //pochylenie prawo/lewo

};
Data_Package data; //Create a variable with the above structure

void setup() {

//MODUL RC
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();             //ustawienie modulu jako ODBIORNIK
  resetData();


//MPU9250
// serial to display data
  while(!Serial) {}
  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
  // setting the accelerometer full scale range to +/-8G 
  IMU.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  // setting the gyroscope full scale range to +/-500 deg/s


//PRZYPISANIE SILNIKOW DO PINOW
bldc1.attach(5); 
bldc1.writeMicroseconds(1000); 

bldc2.attach(6); //CW
bldc2.writeMicroseconds(1000);

bldc3.attach(9); //CW
bldc3.writeMicroseconds(1000);
 
bldc4.attach(10); 
bldc4.writeMicroseconds(1000); 
}


void loop() {

//MODUL RC
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


//MPU9250
  IMU.readSensor();
 (IMU.getAccelX_mss(),6);
 (IMU.getAccelY_mss(),6);

 
//STEROWANIE SILNIKAMI PRZEZ ESC
  double throttle = map(data.sendThrottle, 0, 255, 1000, 2000); // Map the receiving value form 0 to 255 to 0 1000 to 2000, values used for controlling ESCs
  int yaw = map(data.sendYaw, 0, 255, 1000, 2000);
  int pitch = map(data.sendPitch, 0, 255, 1000, 2000);
  int roll = map(data.sendRoll, 0, 255, 1000, 2000);

  
 //*****************************STEROWANIE**************************
 // WYSLIJ PWM DO ESC 
int wartosc = 200;

//STABILIZACJA
//wartosci
int PID = 10;
float osX = ((IMU.getAccelX_mss())*PID);
float osY = ((IMU.getAccelY_mss())*PID);

//predkosci silnikow
int throttle1 = throttle;
int throttle2 = throttle + osX;
int throttle3 = throttle + osY;
int throttle4 = throttle + osX + osY;
//
//
//******************************************************************

//THROTTLE - kontrola wysokosci   
  bldc1.writeMicroseconds(throttle1); 
  bldc2.writeMicroseconds(throttle2); 
  bldc3.writeMicroseconds(throttle3);
  bldc4.writeMicroseconds(throttle4); 

  
//*****************************************************************

Serial.print(throttle1);
Serial.print("     ");
Serial.print(throttle2);
Serial.print("     ");
Serial.print(throttle3);
Serial.print("     ");
Serial.print(throttle4);
Serial.println("     ");
}

void resetData() {
  // Reset the values when there is no radio connection - Set initial default values
 // data.throttle = 127;
//  data.yaw = 127;
 // data.pitch = 127;
 // data.roll = 127;
}
