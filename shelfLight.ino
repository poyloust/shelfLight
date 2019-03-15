#include <Adafruit_NeoPixel.h>

int state = 0;
int preState = 0;
long currentMillis;
long preMillis = 0;

int intensity = 0;

#define PIN            6
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
   pinMode(7,INPUT);
   Serial.begin(9600);
   pixels.begin(); 
}

void loop() {
  currentMillis = millis();
  state = digitalRead(7);
  
  if(state == HIGH){
    if(state == preState){
      if (intensity < 255){
        if (currentMillis - preMillis >= 15){
            intensity++;
            preMillis = currentMillis;
        }
      }
    }
  }
  if (state == LOW){
    if(state == preState)
      if(intensity > 50){
        if (currentMillis - preMillis >= 15){
          fadeOut();
          preMillis = currentMillis;
        }
      }
        if(intensity <=50){
         if (currentMillis - preMillis >= 40){
          fadeOut(); 
          preMillis = currentMillis;  
         }
        }
  }

  for (int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(220,70,15));
    pixels.setBrightness(intensity);
  }
  pixels.show(); 
  preState = state;
 }

void fadeOut(){
  if(intensity>0){
    intensity -= 1;
  }
}
