#include <Adafruit_NeoPixel.h>
#include "figure.h"

#define PIN 6
#define LED_NUMBER 8

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUMBER, PIN, NEO_GRB + NEO_KHZ800);

short figurePosition = 0;
short cOff[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(1);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  for (int i = 0; i < LED_NUMBER; i++)
    setStripColor(i, cOff);
  strip.show();
  Serial.println("off");

  int k = 0;
  while (k < 1000) // change to readDigital...
  {
    //    delayMicroseconds(1);
    delay(1);
    k++;
  }
  Serial.println("on");

  figurePosition = 0;
  while (figurePosition < FIGURE_SIZE) {
    for (int i = 0; i < LED_NUMBER; i++)
      setStripColor(i, FIGURE[figurePosition][i]);
    strip.show();
    figurePosition++;
    delay(50);
  }
}

void setStripColor(int n, short color[3])
{
  strip.setPixelColor(n, color[0], color[1], color[2]);
}

