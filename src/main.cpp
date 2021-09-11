#include <Arduino.h>
#include <FastLED.h>
#include "settings.h"

CRGB leds[LED_COUNT];

uint32_t lastMessage = 0;
uint32_t counter = 0;
uint8_t espIndex = 0;

void showStatus(CRGB led1, CRGB led2) {
    FastLED.clear();
    leds[0] = led1;
    leds[1] = led2;
    FastLED.show();
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(BAUDRATE, SERIAL_8N1, BUS_RXD, BUS_TXD);
  log_i("Initializing");
  counter = random(1000);
  Serial.println();
  Serial.println();
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(255);
  showStatus(CRGB::Red, CRGB::Red);
  delay(1000);
  showStatus(CRGB::Red, CRGB::White);
  delay(1000);
  showStatus(CRGB::White, CRGB::White);
  delay(2000);
  Serial2.println(counter);
  log_i("Setup done");
}

void loop() {
  while(Serial2.available()) {
    String receivedCounterText = Serial2.readStringUntil('\n');
    uint32_t receivedCounter = receivedCounterText.toInt();
    if (espIndex == 0) {
      if (receivedCounter < counter) {
        espIndex = 1;
        counter = receivedCounter;
      } else {
        espIndex = 2;
      }
      
    }
    log_i("I am brother %d, counter: %d", espIndex, counter);
    counter++;
    int ledIndex = counter % 4;

    if ((espIndex == 1 && ledIndex == 0) || (espIndex == 2 && ledIndex == 2)) {
      showStatus(CRGB::Red, CRGB::Black);
    } else if ((espIndex == 1 && ledIndex == 1) || (espIndex == 2 && ledIndex == 3)) {
      showStatus(CRGB::Black, CRGB::Red);
    } else {
      showStatus(CRGB::Black, CRGB::Black);
    }

    Serial2.println(counter);
    delay(500);
  }

}