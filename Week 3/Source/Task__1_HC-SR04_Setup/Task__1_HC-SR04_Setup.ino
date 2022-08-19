// Define Pin Numbers
const int trigPin = 9;
const int echoPin = 10;
// Define Variables
long duration;
int SampleTime = 1000; // Sampling Time

void setup() {
  Serial.begin(9600); // Starts the serial comminicator
  pinMode(trigPin, OUTPUT); // Sets the trigPin as Output
  pinMode(echoPin, INPUT); // Same here but input
  pinMode(13, OUTPUT);

}

void loop() {
  if (Serial.available() > 0){
    String incomingBytes = Serial.readString();
    SampleTime = incomingBytes.toInt();
    Serial.println(incomingBytes);
  }

// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

// Sets the trigPin on HIGH
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 // Read the echoPin, returns the sound wave travel time
  duration = pulseIn(echoPin, HIGH);

  Serial.println(duration);
  delay(SampleTime - 1); // Sampling Time
  
}
