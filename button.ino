//MAGDALENA LIPIEC
//button setup

bool przycisk;
void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600);

 pinMode(7, INPUT);
 //przycisk = 1;
 
}

void loop() {
przycisk = digitalRead(7);

  Serial.println(przycisk);
}
