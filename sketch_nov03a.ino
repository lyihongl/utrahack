#include <Servo.h>

Servo myservo;
Servo myservo1; 
int pos = 0;


void setup() {
    Serial.begin(9600);
    myservo.attach(9);
    myservo1.attach(10);
//    myservo1.write(180);
}

void loop() {

  
  //**reading from analog in**//
  //for sensors to read well into analog reading, should use 20k Ohm resistance
  int fsrReading_0 = analogRead(0);
  int fsrReading_1 = analogRead(1);
//  Serial.println(fsrReading_0);
//  Serial.println(fsrReading_1);

  //** reversing the value so that pressing the sensor causes increased values **//
  fsrReading_0 = 1023 - fsrReading_0;
  fsrReading_1 = 1023 - fsrReading_1;


  if(fsrReading_0<950 && pos< 165){
    pos += 1;
    myservo.write(pos);
    myservo1.write(180-pos);

    delay((int)(fsrReading_0/4));
  }
//   Serial.println(pos);
  if(fsrReading_1<950 && pos>40){
    pos -= 1; 
    myservo.write(pos);
    myservo1.write(180-pos);

    delay((int)(fsrReading_1/8));
    }
    Serial.println(pos);
//   if(fsrReading_1<950||fsrReading_0<950){
//    fsrReading_1<950?Serial.println(fsrReading_1):Serial.println(fsrReading_0);
//   }
    
  }
  //analogWrite(11, led);
