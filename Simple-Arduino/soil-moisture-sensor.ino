#define moisture_pin A1	/* Soil moisture sensor O/P pin */

void setup() {
  Serial.begin(9600);
  pinMode(moisture_pin, INPUT);	/* Define baud rate for serial communication */
}

void loop() {
  float moisture_percentage;
  int sensor_analog = 0;
  sensor_analog = analogRead(moisture_pin);
  moisture_percentage = 100 - ((sensor_analog/1023.00) * 100 );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("\n");
  Serial.print("Moisture Value = ");
  Serial.print(sensor_analog);
  Serial.print("\n\n");
  delay(1000);
}