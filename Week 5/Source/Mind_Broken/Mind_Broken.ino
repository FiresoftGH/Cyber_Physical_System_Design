#include <EEPROM.h>

char a[20] = "Serial_Number";
char b[20] = "Arduino";
char c[20] = "DATE";

void setup() {

  Serial.begin(9600);
  EEPROM.put(0, a);
  EEPROM.put(50, b);
  EEPROM.put(100, c);

}

void loop() {
  
 }
