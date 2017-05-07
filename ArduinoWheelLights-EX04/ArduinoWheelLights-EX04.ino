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

byte figurePosition = 0;
byte cOff[3] = {0, 0, 0};
int timeInBetween = 500;
bool isLow = false;

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
  bool continueLoop = false;
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
    if (wait(delayTime))
    {
      figurePosition = FIGURE_SIZE;
      continueLoop = true;// BREAK THE WHILE LOOP
    }
  }
  if (!continueLoop)
  {
    while (!sensorPulse())
    {
      delay(1);
      timeInBetween++;
    }
  }
}

void setStripColor(int n, bool colorOn)
{
  if (colorOn)
    strip.setPixelColor(n, 60, 200, 60);
  else
    strip.setPixelColor(n, 0, 0, 0);
}

boolean wait(int delayTime)
{
  while (delayTime > 0)
  {
    delayTime--;
    timeInBetween++;
    delay(1);
    if (sensorPulse())
      return true;
  }
  return false;
}

bool sensorPulse()
{
  if (digitalRead(PIN_SENSOR) == LOW && !isLow)
  {
    isLow = true;
    return true;
  }

  if (digitalRead(PIN_SENSOR) == HIGH)
    isLow = false;
  return false;
}


