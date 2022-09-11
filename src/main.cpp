#include <Arduino.h>
#include <Servo.h>

#define BAUD          9600
#define BOTAO_DEC     7
#define BOTAO_CRE     6
#define SERVO_PIN     9
#define MAX           180
#define MIN           0
#define INI_POS       90

void configSerial();
void controle();
void configPins();
void configServo();
void ativaServo(int cont);

Servo servo_motor;
int count = servo_motor.read();

void setup() {
  configSerial();
  configPins();
  configServo();
}

void loop() {
  controle();
  delay(100);
}

void controle(){

  int pos = servo_motor.read();
  
  if (digitalRead (BOTAO_CRE) == 0 && pos < MAX){
    ativaServo(count);
    count  ++;
  }
  if (digitalRead(BOTAO_DEC) == 0 && pos > MIN){
    ativaServo(count);
    count  --;
  }
}

void configSerial(){
  Serial.begin(BAUD);
}

void configPins(){
  
  pinMode(BOTAO_CRE, INPUT_PULLUP);
  pinMode(BOTAO_DEC, INPUT_PULLUP);
}

void configServo(){
  servo_motor.attach(SERVO_PIN);
}

void ativaServo(int cont){
  servo_motor.write(cont);
}

