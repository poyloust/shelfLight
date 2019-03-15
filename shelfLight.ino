#include <Adafruit_NeoPixel.h>
int state = 0;

#define PIN            6
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
   pinMode(7,INPUT);
   Serial.begin(9600);
   pixels.begin(); 
}

void loop() {
  state = digitalRead(7);
  if (state == HIGH){
    Serial.print('1');
    for (int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(225,60,0)); // Moderately bright green color.
    }
    pixels.show(); // This sends the updated pixel color to the hardware.

    }
    else{
      pixels.clear();    // turn all LEDs off
      pixels.show();
     }
}
