#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize Servo
Servo myservo;
const int servoPin = A5; // D9 on Nucleo-F429ZI

// Ultrasonic sensor pins
const int trigPin = D2;
const int echoPin = D3;

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Function to get distance
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000);  // Timeout: 20ms
  int distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);

  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  // Wait until no hand is nearby (safe zone >10 cm)
  if (distance > 10 || distance <= 2) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Feeding Time!");

    // Countdown before feeding
    for (int i = 10; i >= 0; i--) {
      distance = getDistance();  // Check hand again
      if (distance <= 10 && distance > 2) {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Hand Detected!");
        lcd.setCursor(0, 1);
        lcd.print("Feeding Stopped!");
        delay(2000);
        return; // Exit loop early
      }

      lcd.setCursor(6, 1);
      lcd.print("   ");  // Clear previous
      lcd.setCursor(6, 1);
      lcd.print(i);
      delay(1000);
    }

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Dispensing");

    // Servo movement, checking for hand every loop
    for (int j = 0; j < 3; j++) {
      distance = getDistance();
      if (distance <= 10 && distance > 2) {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Hand Detected!");
        lcd.setCursor(0, 1);
        lcd.print("Stopped Mid-Feed");
        myservo.write(0);  // Reset servo
        delay(2000);
        return;
      }

      myservo.write(90);
      delay(500);
      myservo.write(180);
      delay(500);
      myservo.write(0);
      delay(500);
    }

    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Done! :)");
    delay(5000); // Pause before next loop

  } else {
    // Hand too close, don't feed
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Hand Detected!");
    lcd.setCursor(0, 1);
    lcd.print("Waiting to Clear");
    delay(500);
  }
}
