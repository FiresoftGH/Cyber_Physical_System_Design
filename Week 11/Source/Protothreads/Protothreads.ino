#include <pt.h>
#define LED_1_PIN 9

static struct pt pt1;

static int protothreadBlinkLED1(struct pt *pt)
{
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt)
  while (1){
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTImeBlink > 1000);
    digitalWrite(LED_1_PIN, HIGH);
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    digitalWrite(LED_1_PIN, LOW);
  }
  PT_END(pt);

  }
}
void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  PT_INIT(&pt1);

}

void loop() {
  protothreadBlinkLED1(&pt1);

}
