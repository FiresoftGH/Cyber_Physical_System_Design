#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  Wire.requestFrom(8, 1);    // request 6 bytes from peripheral device #8

  while (Wire.available()) { // peripheral may send less than requested
    byte c = Wire.read(); // receive a byte as character
    Serial.println(c);         // print the character

  if (c >= 255/2) {
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
    }
    else {
      digitalWrite(12, LOW);
      digitalWrite(8, HIGH);
    }
  }

  delay(500);
}
