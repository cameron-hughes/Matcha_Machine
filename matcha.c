//Libraries 

    // This #include statement was automatically added by the Particle IDE.
    #include <neopixel.h>

    // This #include statement was automatically added by the Particle IDE.
    #include <blynk.h>

    char auth[] = "664b93396a114343b57adce1127c37e2";

//Define
    //LED
        #include <neopixel.h>
        #define PIXEL_PIN D1
        #define PIXEL_COUNT 12
        #define PIXEL_TYPE WS2812B

        Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

    //Solenoid

        int solenoidPin = 0;

    //Buttons

        int pushButton1 = A0;
        int pushButton2 = A1;
        int pushButton3 = A2;
        int pushButton4 = A3;
        int buttonState1 = 0;
        int buttonState2 = 0;
        int buttonState3 = 0;
        int buttonState4 = 0;

    // Hbridge

        //standby
        int STBY = 4; //standby

         //Motor A
        int PWMA = 3; //Speed control
        int AIN1 = A6; //Direction
        int AIN2 = A7; //Direction

        //Motor B
        int PWMB = 2; //Speed control
        int BIN1 = A5; //Direction
        int BIN2 = A4; //Direction
        
    
    // Alexa
    int brewTea(String command);


// the setup routine runs once when you press reset:
void setup() {
    
    //Alexa
        Particle.function("brew", brewTea);
        
    //Phone app
        Serial.begin(9600); // See the connection status in Serial Monitor
        Blynk.begin(auth);  // Here your Arduino connects to the Blynk Cloud.
        
    // LED
        
        strip.begin();
        strip.show(); // Initialize all pixels to 'off'
        
    // solenoid
        pinMode(solenoidPin, OUTPUT);
        
    //Buttons
    
        pinMode(pushButton1, INPUT);
        pinMode(pushButton2, INPUT);
        pinMode(pushButton3, INPUT);
        pinMode(pushButton4, INPUT);
        
    //Buttons  

    
    // Pump and Motor 

        //standby
        
        pinMode(STBY, OUTPUT);

        //Motor

        pinMode(PWMA, OUTPUT);
        pinMode(AIN1, OUTPUT);
        pinMode(AIN2, OUTPUT);

        // Pump

        pinMode(PWMB, OUTPUT);
        pinMode(BIN1, OUTPUT);
        pinMode(BIN2, OUTPUT);

}
void loop() {
    
    //Startup 

    Blynk.run();
    fadeOut(1);
    buttonState1 = digitalRead(pushButton1);
    buttonState2 = digitalRead(pushButton2);
    buttonState3 = digitalRead(pushButton3);
    buttonState4 = digitalRead(pushButton4);
        
    // 2oz of Matcha
        
        
if (buttonState1 == HIGH) {
        
            rainbow(2);
        
            digitalWrite(STBY, HIGH);
            digitalWrite(AIN1, HIGH);
            digitalWrite(AIN2, LOW);
            analogWrite(PWMA, 0);
        
            digitalWrite(BIN1, LOW);
            digitalWrite(BIN2, HIGH);
            analogWrite(PWMB, 120);
            digitalWrite(solenoidPin, LOW);

        delay(5000);
        
            analogWrite(PWMA, 200);

            analogWrite(PWMB, 0);

        delay(1000);
        
            analogWrite(PWMA, 200);

        delay(1000);
        
            analogWrite(PWMA, 255);

        delay(15000);

            analogWrite(PWMA, 100);
            digitalWrite(solenoidPin, HIGH);

        delay(3000);
        
            analogWrite(PWMA, 0);
            digitalWrite(solenoidPin, HIGH);

        delay(3000);

            analogWrite(PWMB, 140);

        delay(500);

            analogWrite(PWMB, 0);
            analogWrite(PWMA, 0);

        delay(6000);

            Particle.publish("drink_complete", "Matcha_2oz",  PRIVATE);
        delay(1);
            loop();
        
} else if (buttonState2 == HIGH) {
        rainbow(2);
        
        digitalWrite(STBY, HIGH);
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        analogWrite(PWMA, 0);

        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        analogWrite(PWMB, 80);
        digitalWrite(solenoidPin, LOW);

    delay(16000);
    
         analogWrite(PWMB, 0);
    
    delay(90000);

        digitalWrite(solenoidPin, HIGH);
        
    delay(10000);
    
        digitalWrite(solenoidPin, LOW);
        analogWrite(PWMB, 80);
    
    delay(16000);
    
             analogWrite(PWMB, 0);
    
    delay(90000);

        digitalWrite(solenoidPin, HIGH);
        
    delay(20000);

            Particle.publish("drink_complete", "Tea_8oz",  PRIVATE);
            
    delay(1);
    
    loop();
     
} else if (buttonState3 == HIGH) {
        
            rainbow(2);
        
            digitalWrite(STBY, HIGH);
            digitalWrite(AIN1, HIGH);
            digitalWrite(AIN2, LOW);
            analogWrite(PWMA, 0);
        
            digitalWrite(BIN1, LOW);
            digitalWrite(BIN2, HIGH);
            analogWrite(PWMB, 120);
            digitalWrite(solenoidPin, LOW);

        delay(5500);
        
            analogWrite(PWMA, 200);

            analogWrite(PWMB, 0);

        delay(5000);
        
            analogWrite(PWMA, 255);

            analogWrite(PWMB, 0);

        delay(15000);

        analogWrite(PWMA, 200);

        
        analogWrite(PWMB, 100);


    delay(17000);

        analogWrite(PWMB, 0);

        analogWrite(PWMA, 150);
        
        digitalWrite(solenoidPin, HIGH);

    delay(8000);
    
            analogWrite(PWMB, 0);

        analogWrite(PWMA, 0);
        
        digitalWrite(solenoidPin, HIGH);

    delay(10000);

        analogWrite(PWMB, 200);
        
    delay(500);

        analogWrite(PWMB, 0);

    delay(4000);

            Particle.publish("drink_complete", "Matcha_8oz",  PRIVATE);
            
    delay(1);
    
    loop();
     
} else if (buttonState4 == HIGH) {
        
        rainbow(2);
        
        digitalWrite(STBY, HIGH);
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        analogWrite(PWMA, 200);
        
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        analogWrite(PWMB, 150);
        digitalWrite(solenoidPin, LOW);

    delay(40000);

        analogWrite(PWMB, 0);

        digitalWrite(solenoidPin, HIGH);

    delay(30000);

        Particle.publish("drink_complete", "Clean" , 0 , PRIVATE);
        
    delay(1);
    
    loop();
} else{
        digitalWrite(STBY, LOW);
        digitalWrite(solenoidPin, LOW);
}
}


//Alexa 

int brewTea(String command)
{
  if(command == "tea")
  {
    alexaIFTTT();
    return 8;
  }
  else return -1;
}

void alexaIFTTT(){
        
            rainbow(2);
        
            digitalWrite(STBY, HIGH);
            digitalWrite(AIN1, HIGH);
            digitalWrite(AIN2, LOW);
            analogWrite(PWMA, 0);
        
            digitalWrite(BIN1, LOW);
            digitalWrite(BIN2, HIGH);
            analogWrite(PWMB, 120);
            digitalWrite(solenoidPin, LOW);

        delay(5000);
        
            analogWrite(PWMA, 150);

            analogWrite(PWMB, 0);

        delay(1000);
        
            analogWrite(PWMA, 200);

        delay(1000);
        
            analogWrite(PWMA, 255);

        delay(15000);

            analogWrite(PWMA, 100);
            digitalWrite(solenoidPin, HIGH);

        delay(3000);
        
            analogWrite(PWMA, 0);
            digitalWrite(solenoidPin, HIGH);

        delay(3000);

            analogWrite(PWMB, 140);

        delay(500);

            analogWrite(PWMB, 0);
            analogWrite(PWMA, 0);

        delay(6000);

            Particle.publish("drink_complete", "Matcha_2oz",  PRIVATE);
            
         delay(1);
}



void fadeOut(uint8_t wait) {  
  uint16_t i, j;  
  
  for(j=254; j>0; j--) {  
    for(i=0; i<strip.numPixels(); i++) {  
      strip.setBrightness(i+j);  
    }  
    strip.show();  
    delay(wait);  
  }  
 blackout();  
 }  

  void blackout() {  
    strip.setPixelColor(0, 0, 0, 0);  
    strip.setPixelColor(1, 0, 0, 0);  
    strip.setBrightness(255);  
    strip.show();  
  }  


// LED void
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
