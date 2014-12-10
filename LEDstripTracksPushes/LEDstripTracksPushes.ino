#include <Adafruit_NeoPixel.h>
int YELLOWcounter = 0;
int GREENcounter = 0;
int REDcounter = 0;
int stripIndex = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 12, NEO_GRB + NEO_KHZ800);

void setColor(int* led, byte* color){
  for(int i = 0; i < 3; i++){  
    analogWrite(led[i], 255 - color[i]);
  }
}

void setColor(int* led, const byte* color){
  byte tempByte[] = {color[0], color[1], color[2]};
  setColor(led, tempByte);
}
void setup()
{  
 
  pinMode(21,OUTPUT);    // Red LED
  pinMode(20,OUTPUT);    // Yellow LED
  pinMode(19,OUTPUT);    // Green led
  
  Serial.begin(9600); 
 
  strip.begin();
  strip.show();
  digitalWrite(21, LOW);
  digitalWrite(20, LOW);
  digitalWrite(19, LOW);
  
}
 

void loop()
{
  if(analogRead(A6) < 512) {
    digitalWrite(19, HIGH);
    delay(500);
    strip.setPixelColor(stripIndex,strip.Color( 20, 20, 0));
    strip.show();
    ++YELLOWcounter;
    ++stripIndex;
  }
  Serial.print("Yellow:  ");
  Serial.print(YELLOWcounter);

   if(analogRead(A7) < 512) {
     digitalWrite(21, HIGH);
     delay(500);
    strip.setPixelColor(stripIndex,strip.Color(0, 30, 0));
    strip.show();
    ++GREENcounter;
    ++stripIndex;
  }
    Serial.print("   Green:   ");
    Serial.print(GREENcounter);

 if(analogRead(A5) < 512) {
    digitalWrite(20, HIGH);
    delay(500);
    strip.setPixelColor(stripIndex,strip.Color( 40, 0, 0));
    strip.show();
    ++REDcounter;
    ++stripIndex;
  }
  Serial.print("   Red:   ");
  Serial.println(REDcounter);
 
  digitalWrite(21, LOW);
  digitalWrite(20, LOW);
  digitalWrite(19, LOW);
  
}
