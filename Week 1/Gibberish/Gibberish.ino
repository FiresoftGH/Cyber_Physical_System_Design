const int LEDPin = 13;
const int LEDPin2 = 11;
char con_val = 'o';

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin,OUTPUT);
  pinMode(LEDPin2,OUTPUT);
}

void loop() {
  if (Serial.available()>0)
  {
    con_val = char(Serial.read());
    LEDcontrol(con_val);
  }
  delay(100);
}

void LEDcontrol(char con)
{
  if (con == '1')
  {
    Serial.print("From Arduino, LED is ON \n");
    digitalWrite(LEDPin,HIGH);
  }
  if (con == '0')
  {
    Serial.print("From Arduino, LED is OFF \n");
    digitalWrite(LEDPin,LOW);
    digitalWrite(LEDPin2,LOW);
  }
  if (con == '2')
  {
    double val = (analogRead(0)-512)/512.0;
    Serial.println(val);
  }
}
