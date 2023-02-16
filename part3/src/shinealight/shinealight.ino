// LUX-O-MATIC - PART 3 - SHINE A LIGHT

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

// in setup()

#define PIN 5

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);


void setup() {
  matrix.begin();
  Serial.begin(115200);
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
}

#define LED_RED_HIGH 		(31 << 11)

int line = 0;
int column = 0;

void loop() {
  matrix.clear();
  if(line > 8)
  {
    line= 0;
    column++;
    if(column > 32)
      column=0;

  }
  matrix.drawPixel(column,line++,matrix.Color(255, 0, 0));
  matrix.show();
  Serial.print(".");
  delay(100);
}
