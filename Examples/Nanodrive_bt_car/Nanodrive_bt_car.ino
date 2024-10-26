#include<BluetoothSerial.h>
// bt code for bt _controlled bot using Nanodrive development board
// by sudeep mullaguri 

const int motor_pin_A1=4;//First motor 1 pin
const int motor_pin_A2=5;//First motor 2 pin  
const int motor_pin_B1=6;//Second motor 1 pin
const int motor_pin_B2=7;//Second motor 2 pin

BluetoothSerial bt;

void setup(){
  // intializing serial for bluetooth communication 
  Serial.begin(9600);
  bt.begin("Nanodrive_btcar")// name of the device

  pinMode(motor_pin_A1,OUTPUT);
  pinMode(motor_pin_A2,OUTPUT);
  pinMode(motor_pin_B1,OUTPUT);
  pinMode(motor_pin_B2,OUTPUT);
}
void Forward(){
  digitalWrite(motor_pin_A1,HIGH);
  digitalWrite(motor_pin_A2,LOW);
  digitalWrite(motor_pin_B1,HIGH);
  digitalWrite(motor_pin_B2,LOW);
}

void Back(){
  digitalWrite(motor_pin_A1,LOW);
  digitalWrite(motor_pin_A2,HIGH);
  digitalWrite(motor_pin_B1,LOW);
  digitalWrite(motor_pin_B2,HIGH);
}

void Left(){
  digitalWrite(motor_pin_A1,LOW);
  digitalWrite(motor_pin_A2,HIGH);
  digitalWrite(motor_pin_B1,HIGH);
  digitalWrite(motor_pin_B2,LOW);
}

void Right(){
  digitalWrite(motor_pin_A1,HIGH);
  digitalWrite(motor_pin_A2,LOW);
  digitalWrite(motor_pin_B1,LOW);
  digitalWrite(motor_pin_B2,HIGH);
}
void Stop(){
  digitalWrite(motor_pin_A1,LOW);
  digitalWrite(motor_pin_A2,LOW);
  digitalWrite(motor_pin_B1,LOW);
  digitalWrite(motor_pin_B2,LOW);
}

void get_commands(){
 char command = Serial.read();
  switch(command){
     case 'F':
     Forward();
     break;
     case 'B':
     Back();
     break;
     case 'R':
     Forward()
     break;
     case 'L':
     Left();
     break;
     case 'S':
     Right();
     break;
     default:
     Stop();
    
    
  }
}
void loop(){
  get_commands();
}
