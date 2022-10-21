// Connecting to Bluetooth HM10 and print help menut using AT
//https://makersportal.com/blog/2019/10/14/bluetooth-module-with-arduino 
// For changing the configuration of BLE HM-10

#include <SoftwareSerial.h>
SoftwareSerial BLESerial(2,3); // RX = 2, TX = 3

// Connect HM10      Arduino Uno
//     TXD          Pin 2 RX
//     RXD          Pin 3 TX

String str_ii = "";
void setup()
{
  BLESerial.begin(9600);
  Serial.begin(9600);
   ble_cmd("AT+NAMEFiresoft" , "Device Name: ");
   ble_cmd("AT+NAME" , "Device Name: ");
   ble_cmd("AT+LADDR" , "Local Address: ");
   ble_cmd("AT+RESET" , "");
    
}
void loop(){
  }

String ble_cmd(String cmd_str, String desc_str){
  str_ii = "";
  unsigned long t1 = millis();
  BLESerial.println(cmd_str);
  while(true){
    char in_char = BLESerial.read();
    if (int(in_char)==-1 or int(in_char)==42){
          if ((millis()-t1)>2000){ // 2 second timeout
        return "Err";
      }
      continue;
  }

  if(in_char == '\n'){
    Serial.print("Bluetooth " + desc_str);
    Serial.println(str_ii.substring(0,str_ii.length()));
    return str_ii;
  }
  str_ii += in_char;
  } 
}
