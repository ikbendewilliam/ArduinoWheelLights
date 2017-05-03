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

byte figurePosition = 0;
byte cOff[3] = {0, 0, 0};
int timeInBetween = 500;
int nextInterval = 1000;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(16);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  short delayTime = timeInBetween / FIGURE_SIZE;
  Serial.println(timeInBetween);
  Serial.println(delayTime);
  timeInBetween = 0;

  figurePosition = 0;
  while (figurePosition < FIGURE_SIZE) {
    for (int i = 0; i < LED_NUMBER; i++)
      setStripColor(i, FIGURE[figurePosition][i]);
    strip.show();
    figurePosition++;
    if (wait(delayTime)) break; // BREAK THE WHILE LOOP
  }
  if (!wait(1000)) // wait a full second
  {
    while (false)// readDigital == true
    {
      delay(1);
    }
  }
}

void setStripColor(int n, byte color[3])
{
  strip.setPixelColor(n, color[0], color[1], color[2]);
}

boolean wait(int delayTime)
{
  while (delayTime > 0)
  {
    delayTime--;
    timeInBetween++;
    delay(1);
    if (timeInBetween > nextInterval) // readDigital == true
    {
      nextInterval -= 5;
      return true;
    }
  }
  return false;
}

