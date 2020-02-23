//MAGDALENA LIPIEC

int axisX = 0;
int axisY = 0;


void setup() {

  pinMode(3, OUTPUT); //dioda axisY [PWM]
  pinMode(5, OUTPUT); //dioda axisX [PWM]
  
  Serial.begin(9600);
  Serial.println("axisX \t axisY");
}

void loop() {

  axisX = analogRead(A0);
  axisY = analogRead(A1);
  
  Serial.print(axisX );
  Serial.print(" \t");
  Serial.println(axisY); 

  analogWrite(3, axisY);  //sterowanie jasnoscia diody  axisY
  analogWrite(5, axisX);  //sterowanie jasnoscia diody  axisX

  delay(100);
    
}
