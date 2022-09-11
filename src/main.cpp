#include <Arduino.h>
#include <Servo.h>

#define BAUD                9600
#define MAX                 180
#define MIN                 0
#define INI_POS             90
#define MOTOR_1_PIN         5
#define MOTOR_2_PIN         4
#define MOTOR_3_PIN         3
#define MOTOR_4_PIN         2
#define FATOR_DE_CONVERSAO  512

#define POT_MOTOR_1   A5
#define POT_MOTOR_2   A4
#define POT_MOTOR_3   A3
#define POT_MOTOR_4   A2

void configSerial();
void configServos();
uint32_t ADCConverter(uint32_t read_value);
void controleMotor1();
void controleMotor2();
void controleMotor3();
void controleMotor4();

Servo motor_1;
Servo motor_2;
Servo motor_3;
Servo motor_4;

void setup() {
  configSerial();
  configServos();
}

void loop() {
  controleMotor1();
  controleMotor2();
  controleMotor3();
  controleMotor4();
  delay(1000);
}

void configSerial(){
  Serial.begin(BAUD);
}

void configServos(){
  motor_1.attach(MOTOR_1_PIN);
  motor_2.attach(MOTOR_2_PIN);
  motor_3.attach(MOTOR_3_PIN);
  motor_4.attach(MOTOR_4_PIN);
}

uint32_t ADCConverter(uint32_t read_value){
  uint32_t conversao = ((read_value * INI_POS)/FATOR_DE_CONVERSAO);
  return conversao;
}

void controleMotor1(){
  int pot_1 = analogRead(POT_MOTOR_1);
  motor_1.write(ADCConverter(pot_1));
}
void controleMotor2(){
  int pot_2 = analogRead(POT_MOTOR_2);
  motor_2.write(ADCConverter(pot_2));
}
void controleMotor3(){
  int pot_3 = analogRead(POT_MOTOR_3);
  motor_3.write(ADCConverter(pot_3));
}
void controleMotor4(){
  int pot_4 = analogRead(POT_MOTOR_4);
  motor_4.write(ADCConverter(pot_4));
}
