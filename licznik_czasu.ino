//MAGDALENA LIPIEC
//aplikacja liczy czas od wciśnięcia przysciku start do wcisniecia przyscisku stop

#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

unsigned long czas;


void setup() {
  lcd.begin(16, 2); 
  lcd.clear();
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.setCursor(0,1);

  pinMode(8, INPUT_PULLUP); //START
  pinMode(9, INPUT_PULLUP); //STOP

  czas = millis();

}

void loop()
{

  if ((digitalRead(8) == LOW)) {  //jak damy impuls
  
  
  lcd.setCursor(0, 0); 
  lcd.print(" WCISNIETO START"); 
  
  lcd.setCursor(0,1);
  lcd.print(czas);

  Serial.println(czas);
  
  delay(3000); 
  
  }

  if ((digitalRead(9) == LOW)) {  //jak damy impuls
  
  
  lcd.setCursor(0, 0); 
  lcd.print("WCISNIETO STOP"); 
  lcd.setCursor(0,1);
  lcd.print("WYKRES");
  delay(3000); 
  }

  else {
    lcd.clear();
  }
}
