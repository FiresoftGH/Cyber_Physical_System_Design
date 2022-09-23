#include <EEPROM.h>
char a[20];
char b[20];
char c[20];

void setup() {
  Serial.begin(9600);
  EEPROM.get(0, a);
  EEPROM.get(50, b);
  EEPROM.get(100, c);
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);

}

void loop() {
  // put your main code here, to run repeatedly:

}
