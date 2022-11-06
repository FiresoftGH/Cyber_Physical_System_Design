#define LED_1_PIN 9
#define LED_2_PIN 10
#define LED_3_PIN 11
#define LED_4_PIN 12

#define POTENTIOMETER_PIN A0

#define BUTTON_PIN 5

unsigned long previousTimeLed1 = millis();
unsigned long previousTimeLed2 = millis();
long timeIntervalLed1 = 1000;
int ledState1 = LOW;
int ledState2 = LOW;
long duration;
int SampleTime = 1000;

const int trigPin = 4;
const int echoPin = 3;


unsigned long previousTimeSerialPrintPotentiometer = millis();
long timeIntervalSerialPrint = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as Output
  pinMode(echoPin, INPUT); // Same here but input
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  // task 1
  if(currentTime - previousTimeLed1 > timeIntervalLed1) {
    previousTimeLed1 = currentTime;

    if (ledState1 == HIGH) {
      ledState1 = LOW;
    }
    else {
      ledState1 = HIGH;
    }

    digitalWrite(LED_1_PIN, ledState1);
  }

  // task 2
      //if (Serial.available()) {
      //    int userInput = Serial.parseInt();
      //    if (userInput >= 0 && userInput < 256) {
      //      analogWrite(LED_2_PIN, userInput);
      //    }
      //}
      
  if(currentTime - previousTimeLed2 > 2000) {
    previousTimeLed2 = currentTime;

    if (ledState2 == HIGH) {
      ledState2 = LOW;
    }
    else {
      ledState2 = HIGH;
    }

    digitalWrite(LED_2_PIN, ledState2);
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
  
  if (digitalRead(BUTTON_PIN) == HIGH){
    Serial.println(duration);
  }
  else {
    delay(300);
  }

  // task 4
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  if (potentiometerValue > 512) {
    digitalWrite(LED_4_PIN, HIGH);
  }
  else {
    digitalWrite(LED_4_PIN, LOW);
  }

  // task 5
  if (currentTime - previousTimeSerialPrintPotentiometer > timeIntervalSerialPrint) {
    previousTimeSerialPrintPotentiometer = currentTime;
//    Serial.println(potentiometerValue);
    }
 
}