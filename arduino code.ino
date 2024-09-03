#include <LiquidCrystal.h>

  LiquidCrystal lcd(10,9,5,4,3,2);

const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
    analogWrite(6,100);
    lcd.begin(16,2);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

    
}

void loop() {
long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance = ");
    lcd.setCursor(11,0);
    lcd.print(distance);
    lcd.setCursor(14,0);
    lcd.print("CM");
    
    delay(500);
    
}
