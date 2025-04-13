#define echoPin 35 // attach pin 27 ESP32 to pin Echo of AJ-SR04T
#define trigPin 34 //attach pin 26 ESP32 to pin Trig of AJ-SR04T

// defines variables
long duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baud rate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with ESP32");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);  //
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseInLong(echoPin, HIGH);
  // Calculating the distance
  distance = duration / 58; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");// working  code for aj-sr04m
}
