//MAGDALENA LIPIEC
int liczba =0;

void setup() {
  Serial.begin(9600);
}

void loop() {
    while(liczba<10) {
    Serial.println(liczba++);
    delay(1000);
  }

}
