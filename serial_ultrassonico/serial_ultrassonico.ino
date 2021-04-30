#include <Ultrasonic.h>

HC_SR04 sensorCafe(0,1); 
HC_SR04 sensorXicara(3,4); 

int pos,pos2;

int servoCafe = 10;
int servoXicara = 11;

void setup() {
  Serial.begin(9600);
  pinMode(servoCafe, OUTPUT);
  pinMode(servoXicara, OUTPUT);
}

void loop() {
 
 pos = sensorCafe.distance();      
 pos2 = sensorXicara.distance();   
 servoPos(servoXicara, 0);		 
 servoPos(servoCafe, 0);

 if (pos+10 <= 90) {               
  servoPos(servoCafe, pos);
  delay(2000);
  
 } else if (pos >= 91) {			
  servoPos(servoCafe, pos);
  delay(2000);
 };

 if (pos2 >= 100 && pos > 10){     
  servoPos(servoXicara, pos2);
  delay(15000);
 };
}
void servoPos (int servo, int pos)
{
  int microPulso = map(pos, 0,180,1000,2000);
  digitalWrite(servo, HIGH);
  delayMicroseconds(microPulso);
  digitalWrite(servo, LOW);
  delay(10);                   
}
