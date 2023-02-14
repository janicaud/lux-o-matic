// LUX-O-MATIC - PART 3 - SHINE A LIGHT

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 5

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);


void setup() {
  matrix.begin();
}

#define LED_RED_HIGH 		(31 << 11)

int position = 0;

void loop() {
  matrix.fillScreen(0);
  if(position > 32)
    position= 0;
  matrix.drawPixel(1,2 + position++,LED_RED_HIGH);
  matrix.show();
  delay(100);
}
