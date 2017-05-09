#include <Adafruit_NeoPixel.h>
#include "figure.h"

static const int PIN = 6;
static const int LED_NUMBER = 8;
static const int PIN_MINUS = 8;
static const int PIN_PLUS = 9;
static const int PIN_SENSOR = 10;

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

  pinMode(PIN_MINUS, OUTPUT);
  pinMode(PIN_PLUS, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);

  digitalWrite(PIN_MINUS, LOW);
  digitalWrite(PIN_PLUS, HIGH);
  
  strip.begin();
  strip.setBrightness(128);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  for (int i = 0; i < LED_NUMBER; i++)
    setStripColor(i, cOff);
  strip.show();
  Serial.println("off");

  while (digitalRead(PIN_SENSOR) == HIGH)
  {
    delay(1);
  }
  Serial.println("on");

  figurePosition = 0;
  while (figurePosition < FIGURE_SIZE) {
    for (int i = 0; i < LED_NUMBER; i++)
      setStripColor(i, FIGURE[figurePosition][i]);
    strip.show();
    figurePosition++;
    delay(4);
  }
}

void setStripColor(int n, short color[3])
{
  strip.setPixelColor(n, color[0], color[1], color[2]);
}

