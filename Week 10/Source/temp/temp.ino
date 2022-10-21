#include <SoftwareSerial.h>
SoftwareSerial BLESerial(2,3);

long previousMillis_BLE = 0;
long previousMillis_SRE = 0;

int interval_BLE = 100;
int interval_SRE = 200;
void setup() {
  Serial.begin(9600);
  BLESerial.begin(9600);
  while (!Serial){
    ; // wait for serial port to connect
  }
  Serial.println("Ready to go");

}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_BLE > interval_BLE) {
    previousMillis_BLE = currentMillis;
    while (BLESerial.available() > 0){
      String in_str = BLESerial.readString();
//      if (in_str.length() == 0); else Serial.println(in_str);
      if (in_str == "poten"){
        while (BLESerial.readString() != "stop"){
          if (BLESerial.readString() == "stop"){
            break;
          }
          else {
            BLESerial.print((int) analogRead(A0));
            delay(3000);
          }
        }
      }
      else {
        Serial.print(in_str);
      }
    }
  }
  if (currentMillis - previousMillis_SRE > interval_BLE) {
    previousMillis_SRE = currentMillis;
    while (Serial.available() > 0){
      if (BLESerial.readString() == "poten"){
        BLESerial.print("");
      }
      else {
        BLESerial.print((String) Serial.readString());
      }
    }
  }
}
