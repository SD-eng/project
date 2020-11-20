#include<ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial NodeSerial(D6,D7);
bool sensor = false;
String code;
int count = 0;
//String NumCode[] = code
int currentButtonState1 = D8;

void setup() 
{
  // Open serial communications and wait for port to open:
  pinMode(D6,INPUT);
  pinMode(D7,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  NodeSerial.begin(9600);
} 



void loop() 
{ 
  currentButtonState1 = digitalRead(sensor);
  //if(currentButtonState1 == HIGH)
  while(currentButtonState1 == true)
  {
    NodeSerial.write("~M00910001."); //โค้ดเปิดsetting
    delay(1000);
    NodeSerial.write("~M00210001."); //โค้ดเปิดโหมดออโต้
    delay(1000);
    NodeSerial.write("~M00910000."); //โค้ดปิดsetting
    if (NodeSerial.readString()) 
    {
    
        NodeSerial.write("~MA5F01B2c."); //โค้ดปิดการทำงาน
        currentButtonState1 == false;
        break;
    }
    //count == 0;
  }
  code = NodeSerial.readString();
  Serial.println(code);
  
}


    
