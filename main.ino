#include <Servo.h>

Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;

int pos1 = 0; 
int pos2 = 0; 
int pos3 = 0; 
int pos4 = 0; 

int control = 0;

int buttonstate = 0;
int secondbutstate = 0;

int pin0 = A0;
int pin1 = A1;
int pin2 = A2;
int pin3 = A3;

int buttonpin = 2;
int buttonpin2 = 3;

int data0[] = {0,0,0,0};
int data1[] = {0,0,0,0};
int data2[] = {0,0,0,0};
int data3[] = {0,0,0,0};

int position1 = 0;
int position2 = 0;
int position3 = 0;
int position4 = 0;

void setup() {
pinMode(pin0, INPUT);
pinMode(pin1, INPUT);
pinMode(pin2, INPUT);
pinMode(pin3, INPUT);
pinMode(buttonpin, INPUT);
pinMode(buttonpin2, INPUT);
motor0.attach(5);
motor1.attach(6);
motor2.attach(9);
motor3.attach(10);
Serial.begin(9600);
}
 
void loop() {
pos1 = analogRead(pin0);
pos2 = analogRead(pin1);
pos3 = analogRead(pin2);
pos4 = analogRead(pin3);
position1 = map(pos1,0,1023,0,180);
position2 = map(pos2,0,1023,0,180);
position3 = map(pos3,0,1023,0,180);
position4 = map(pos4,0,1023,0,180);

motor0.write(position1);
motor1.write(position2);
motor2.write(position3);
motor3.write(position4);
 
buttonstate = digitalRead(buttonpin);
secondbutstate = digitalRead(buttonpin2);

  if(buttonstate == 1){	
    control += 1;
  }
  switch(control){
    case 1:
    	data0[0] = position1;
    	data0[1] = position2;
    	data0[2] = position3;
    	data0[3] = position4;
    	break;
    case 2:
    	data1[0] = position1;
    	data1[1] = position2;
    	data1[2] = position3;
    	data1[3] = position4;
    	break;
    case 3:
    	data2[0] = position1;
    	data2[1] = position2;
    	data2[2] = position3;
    	data2[3] = position4;
    	break;
    case 4:
    	data3[0] = position1;
    	data3[1] = position2;
    	data3[2] = position3;
    	data3[3] = position4;
    	break;
 
  }
 if(secondbutstate == 1){
  while(true){
    motor0.write(data0[0]);
    delay(100);
    motor1.write(data0[1]);
    delay(100);
    motor2.write(data0[2]);
    delay(100);
    motor3.write(data0[3]);
    delay(1000);
    motor0.write(data1[0]);
    delay(100);
    motor1.write(data1[1]);
    delay(100);
    motor2.write(data1[2]);
    delay(100);
    motor3.write(data1[3]);
    delay(1000);
    motor0.write(data2[0]);
    delay(100);
    motor1.write(data2[1]);
    delay(100);
    motor2.write(data2[2]);
    delay(100);
    motor3.write(data2[3]);
  	delay(1000);
    motor0.write(data3[0]);
    delay(100);
    motor1.write(data3[1]);
    delay(100);
    motor2.write(data3[2]);
    delay(100);
    motor3.write(data3[3]);
  	delay(1000);
  
  }
  }
  Serial.println(buttonstate);
  delay(100);
}