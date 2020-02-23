//MAGDALENA LIPIEC

#define LED_R 10
#define LED_G 11
#define kontraktron 0

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);

  pinMode(kontraktron, INPUT_PULLUP);

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
}

void loop() {
  if (digitalRead(kontraktron) == LOW) {    //jesli czujnik jest zwarty
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
  }
  else {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
  }

}
