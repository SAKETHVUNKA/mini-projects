#include <Servo.h>

#define echoPin 7  // Echo Pin
#define trigPin 8  // Trigger Pin
#define BUZZERPin 9 // Buzzer Pin
#define ServoPin 10 // Servo Pin

int maximumRange = 100; // Maximum range needed (in cm)
int minimumRange = 0;   // Minimum range needed (in cm)
long duration, distance; // For storing pulse duration and distance
int pos; 

Servo myservo;  // Create Servo object

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BUZZERPin, OUTPUT);
  myservo.attach(ServoPin); // Attach servo to pin 10
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo duration
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; // Convert to cm

  if (distance >= maximumRange || distance <= minimumRange) {
    Serial.println("-1");
    digitalWrite(BUZZERPin, HIGH);

    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15); // Smooth movement
    }
  } else {
    Serial.println(distance);
    digitalWrite(BUZZERPin, LOW);

    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15); // Smooth movement
    }
  }

  delay(300); // Small delay before next measurement
}