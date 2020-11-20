#include<ESP8266WiFi.h>
#include <SoftwareSerial.h>

SoftwareSerial NodeSerial(D6,D7);
String code;
int buttonPin1 = D8;
int currentButtonState1 = LOW;
void setup() 
{
  // Open serial communications and wait for port to open:

  
  pinMode(D6,INPUT);
  pinMode(D7,OUTPUT);
  pinMode(buttonPin1,INPUT);
  Serial.begin(9600);
  NodeSerial.begin(9600);
} 



void loop() 
{ 
  currentButtonState1 = digitalRead(buttonPin1);
  if(currentButtonState1 == HIGH)
  {
    
    NodeSerial.write("~M00910001."); //โค้ดเปิดsetting
    delay(1000);
    NodeSerial.write("~M00210001."); //โค้ดเปิดโหมดออโต้
    delay(1000);
    NodeSerial.write("~M00910000."); //โค้ดปิดsetting
    //delay(1000); 
    
    delay (10000);
    NodeSerial.write("~MA5F01B2c."); //โค้ดเปิดsetting
    code = NodeSerial.readString();
    Serial.println(code);
  }
}


   

    
