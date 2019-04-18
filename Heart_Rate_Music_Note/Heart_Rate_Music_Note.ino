/*
Heart Rate Badge with heart-shaped neopixel display
written by Becky Stern for Adafruit Industries
Based on sample code from http://learn.parallax.com/KickStart/28048
*/

#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 12, NEO_GRB + NEO_KHZ800);

//Definitions  
const int HR_RX = 2;
byte oldSample, sample;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(20, 0, 0), 50); // Red
  
  Serial.begin(9600);
  pinMode (HR_RX, INPUT);  //Signal pin to input  
  
  Serial.println("Waiting for heart beat...");

 // Wait until a heart beat is detected  
  while (!digitalRead(HR_RX)) {};
  Serial.println ("Heart beat detected!");
}

void loop() {
  sample = digitalRead(HR_RX);  //Store signal output 
  if (sample && (oldSample != sample)) {
    Serial.println("Beat");
    heartBeat();
  }
  oldSample = sample;           //Store last signal received 
  

for (volatile int i=0; i<strip.numPixels(); i++){
      strip.setPixelColor(i, strip.Color(20, 0, 0)); 
    }
    strip.show();
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void heartBeat (){
  Serial.println("heartbeat");
for (volatile int i=0; i<strip.numPixels(); i++){
      strip.setPixelColor(i, strip.Color(255, 0, 0)); 
    }
    strip.show();
   delay(10);
}
