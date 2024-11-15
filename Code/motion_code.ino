#include <Wire.h>
#include <LiquidCrystal_I2C.h>

float maxamp = 2;
float minamp = 0;

float jitter_min = 10000;
float jitter_max = 12000;

int bias_h_bridge = 0;
int h_bridge_active = 0;
int go = 0;
int quiet = 0;

void setup() {

    pinMode(7, INPUT_PULLUP);    // pin used to detect the first TTL and start the program

  // put your setup code here, to run once:
//h-bridge 1
  pinMode(8, OUTPUT);    // sets the digital pin 12 as output for h bridge
  pinMode(9, OUTPUT);    // sets the digital pin 13 as output for h bridge
//h-bridge 2
  pinMode(10, OUTPUT);    // sets the digital pin 12 as output for h bridge
  pinMode(11, OUTPUT);    // sets the digital pin 13 as output for h bridge
//h-bridge 3
  pinMode(12, OUTPUT);    // sets the digital pin 12 as output for h bridge
  pinMode(13, OUTPUT);    // sets the digital pin 13 as output for h bridge


//set write in the beginning
  Serial.begin(9600);

  randomSeed(42);
}

void loop() {
  // put your main code here, to run repeatedly:

//    go = digitalRead(7);   // read if ttl happened
//-------------------------------------
//    h_bridge_active = 1;
    h_bridge_active = random(0,2);

    bias_h_bridge = 0;

    quiet = random(0,10);
    
    if(quiet<=10)
    {
    setH_Bridge(bias_h_bridge,h_bridge_active);
    }
//    Serial.print("TTL active:");
//    Serial.print(go);
    Serial.print("h_bridge_selected:");
    Serial.print(h_bridge_active);
    Serial.print(" ,bias: ");
    Serial.println(bias_h_bridge);
    
    delay(random(jitter_min,jitter_max));
 //-----------------------
    

// 9 low and 8 high is left when looking into bore
}

void setH_Bridge(int bridge, int bias)
{
  if (bridge == 0)
  {
   //fist disabling the other h bridges
//   digitalWrite(10, LOW); // sets the digital pin 10 on
//   delay(100);
//   digitalWrite(11, LOW); // sets the digital pin 11 on    
//   delay(100);
//   digitalWrite(12, LOW); // sets the digital pin 12 on
//   delay(100);
//   digitalWrite(13, LOW); // sets the digital pin 13 on    
//   delay(100);
  
    if(bias==0)
    {
      digitalWrite(8, HIGH); // sets the digital pin 12 on
      delay(100);
      digitalWrite(9, LOW); // sets the digital pin 13 on
    }
    if(bias==1)
    {
      digitalWrite(8, LOW); // sets the digital pin 12 on
      delay(100);
      digitalWrite(9, HIGH); // sets the digital pin 13 on      
    }
//    if(bias==2)
//    {
//      digitalWrite(8, LOW); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(9, LOW); // sets the digital pin 13 on      
//    }
//      if (bridge == 1)
//  {
//   //fist disabling the other h bridges
//   digitalWrite(8, LOW); // sets the digital pin 8 on
//   delay(100);
//   digitalWrite(9, LOW); // sets the digital pin 9 on    
//   delay(100);
//   digitalWrite(12, LOW); // sets the digital pin 12 on
//   delay(100);
//   digitalWrite(13, LOW); // sets the digital pin 13 on    
//   delay(100);
//   
//    if(bias==0)
//    {
//      digitalWrite(10, HIGH); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(11, LOW); // sets the digital pin 13 on
//    }
//    if(bias==1)
//    {
//      digitalWrite(10, LOW); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(11, HIGH); // sets the digital pin 13 on      
//    }
//    if(bias==2)
//    {
//      digitalWrite(10, LOW); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(11, LOW); // sets the digital pin 13 on      
//    }
//  }
//
//  if (bridge == 2)
//  {
//   //fist disabling the other h bridges
//   digitalWrite(8, LOW); // sets the digital pin 8 on
//   delay(100);
//   digitalWrite(9, LOW); // sets the digital pin 9 on    
//   delay(100);
//   digitalWrite(10, LOW); // sets the digital pin 10 on
//   delay(100);
//   digitalWrite(11, LOW); // sets the digital pin 11 on    
//   delay(100);
//   
//    if(bias==0)
//    {
//      digitalWrite(12, HIGH); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(13, LOW); // sets the digital pin 13 on
//    }
//    if(bias==1)
//    {
//      digitalWrite(12, LOW); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(13, HIGH); // sets the digital pin 13 on      
//    }
//    if(bias==2)
//    {
//      digitalWrite(12, LOW); // sets the digital pin 12 on
//      delay(100);
//      digitalWrite(13, LOW); // sets the digital pin 13 on      
//    }
//  }
  }


}
