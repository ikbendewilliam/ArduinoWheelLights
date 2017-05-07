#include <Adafruit_NeoPixel.h>

static const int PIN = 6;
static const int LED_NUMBER = 8;

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUMBER, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for (int i = 0; i < LED_NUMBER; i++)
    strip.setPixelColor(i, 0, 235, 200);
//    strip.setPixelColor(i, i * 64 % 255, (LED_NUMBER - i) * 16 % 255, (i * i * 255) % 255);

  strip.show();
}

