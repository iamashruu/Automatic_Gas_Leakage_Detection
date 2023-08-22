// const int RedLED = 11;
const int BuzzerNeg = 9;
const int Buzzer = 10;
const int Relay = 8; // Relay control pin
// const int IndicatorLED = 12; // Indicator LED connected to pin 12
const int MQ5 = A5;
const int SENSOR_THRESHOLD = 90;

void setup() {
  // pinMode(RedLED, OUTPUT);
  pinMode(BuzzerNeg, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Relay, OUTPUT); // Set relay control pin as OUTPUT
  // pinMode(IndicatorLED, OUTPUT); // Set indicator LED pin as OUTPUT
  pinMode(MQ5, INPUT);
  digitalWrite(Buzzer, LOW);
  digitalWrite(Relay, LOW); // Initialize relay to OFF state
  // digitalWrite(IndicatorLED, LOW); // Initialize indicator LED to OFF state
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(MQ5);

  Serial.print("Analog Sensor Value: ");
  Serial.println(analogSensor);

  if (analogSensor > SENSOR_THRESHOLD) {
    // digitalWrite(RedLED, HIGH);
    digitalWrite(BuzzerNeg, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Relay, HIGH); // Turn ON the relay
    // digitalWrite(IndicatorLED, HIGH); // Turn ON the indicator LED
  } else {
    // digitalWrite(RedLED, LOW);
    digitalWrite(BuzzerNeg, HIGH);
    digitalWrite(Buzzer, LOW);
    digitalWrite(Relay, LOW); // Turn OFF the relay
    // digitalWrite(IndicatorLED, LOW); // Turn OFF the indicator LED
  }
  
  // Added continuous buzzer sound when gas is detected
  if (analogSensor > SENSOR_THRESHOLD) {
    while (analogSensor > SENSOR_THRESHOLD) {
      digitalWrite(Buzzer, HIGH);
      delay(30); // Adjust the delay for the desired buzzer sound frequency
      digitalWrite(Buzzer, LOW);
      delay(30); // Adjust the delay for the desired buzzer sound frequency
      analogSensor = analogRead(MQ5); // Update the sensor reading
    }
  }

  delay(100);
}
