#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 12, NEO_GRB + NEO_KHZ800);

int YELLOWcounter = 0;
int GREENcounter = 0;
int REDcounter = 0;

int greenPins[] = {47, 49, 48, 41, 43, 46, 44, 45, 50};
int redPins[] = {38, 37, 39, 34, 35, 36, 33, 32, 30};
int yellowPins[] = {31, 29, 25, 27, 23, 22, 24, 28, 26};

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
 
 
 for(int i = 22; i < 54; i++){
  pinMode(i, OUTPUT);
  digitalWrite(i, LOW);
  }
}

void loop()
{
  
 if(analogRead(A6) < 512) {
    digitalWrite(19, HIGH);
    digitalWrite(yellowPins[YELLOWcounter], HIGH);
    delay(500);
    ++YELLOWcounter;
    
  }


   if(analogRead(A7) < 512) {
     digitalWrite(21, HIGH);
     digitalWrite(greenPins[GREENcounter], HIGH);
     delay(500);
    ++GREENcounter;
  }

 if(analogRead(A5) < 512) {
    digitalWrite(20, HIGH);
    digitalWrite(redPins[REDcounter], HIGH);
    delay(500);
    ++REDcounter;
  }
 
  digitalWrite(21, LOW);
  digitalWrite(20, LOW);
  digitalWrite(19, LOW);

  if(YELLOWcounter > REDcounter && YELLOWcounter > GREENcounter)  // SHOW YELLOW
  {
    for(int i = 0; i< strip.numPixels(); i++)
    {
      strip.setPixelColor(i,strip.Color( 20, 20, 0));
    }      
    strip.show();
  }

  else if(REDcounter > YELLOWcounter && REDcounter > GREENcounter)  // SHOW RED
  {  
    for(int i = 0; i< strip.numPixels(); i++)
    {
      strip.setPixelColor(i,strip.Color( 30, 0, 0));
    }      
      strip.show(); 
  }
  
  else if(GREENcounter > YELLOWcounter && GREENcounter > REDcounter)  //SHOW GREEN
  {   
    for(int i = 0; i< strip.numPixels(); i++)
    {
      strip.setPixelColor(i,strip.Color( 0, 20, 0));
    }      
      strip.show();
  }
    
  else if(YELLOWcounter == GREENcounter && YELLOWcounter == REDcounter)  //SHOW ALL COLORS  
  {     
    for(int i = 0; i< strip.numPixels(); i++)
    {
      strip.setPixelColor(i,strip.Color( 20, 20, 20));
    }      
      strip.show();
  }
    
   else if(YELLOWcounter == REDcounter)    //SHOW YELLOW AND RED
   {
      for(int i = 0; i< strip.numPixels(); i++)
      {
        if(i%2 == 0) strip.setPixelColor(i,strip.Color( 20, 20, 0));
        else strip.setPixelColor(i,strip.Color( 30, 0, 0));
      }      
        strip.show();
    }
      
    else if((YELLOWcounter) == (GREENcounter)){  //SHOW GREEN AND YELLOW
        
         for(int i = 0; i< strip.numPixels(); i++)
    {
         if(i%2 == 0) strip.setPixelColor(i,strip.Color( 20, 20, 0));
        else strip.setPixelColor(i,strip.Color( 0, 20, 0));
    }      
      strip.show();
  
  }
        else if((REDcounter) == (GREENcounter)){  //SHOW RED AND GREEN
          
         for(int i = 0; i< strip.numPixels(); i++)
    {
             if(i%2 == 0) strip.setPixelColor(i,strip.Color( 0, 20, 0));
        else strip.setPixelColor(i,strip.Color( 30, 0, 0));
    }      
      strip.show();
  
  }

  
}






void setColor(int* led, byte* color){
  for(int i = 0; i < 3; i++){  
    analogWrite(led[i], 255 - color[i]);
  }
}

void setColor(int* led, const byte* color){
  byte tempByte[] = {color[0], color[1], color[2]};
  setColor(led, tempByte);
}
