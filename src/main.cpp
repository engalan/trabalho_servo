#include <Arduino.h>
#include <Servo.h>

#define BAUD          9600
#define BOTAO_DEC     7
#define BOTAO_CRE     6
#define SERVO_PIN     9
#define MAX           180
#define MIN           0
#define INI_POS       90

// EXCLUIR APÒS TESTES
#define LED1          4
#define LED2          5
//EXCLUIR APÓS TESTES


void configSerial();
void controle();
void configPins();
void configServo();
void ativaServo(int cont);

Servo servo_motor;

void setup() {
  configSerial();
  configPins();
  configServo();
}

void loop() {
  controle();
  delay(1000);
}

void controle(){

  int pos = servo_motor.read();
  Serial.print("Angulo atual = ");
  Serial.println(pos);
  
  while (digitalRead (BOTAO_CRE) == 0 && pos <= MAX){
    //EXCLUIR APÓS TESTES
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    //EXCLUIR APÓS TESTES

    Serial.println("Incrementando");
    ativaServo(pos);
    Serial.print("Setando Angulo para: ");
    Serial.println(pos);
    pos ++;
  }
  while (digitalRead(BOTAO_DEC) == 0 && pos > MIN){
    //EXCLUIR APÓS TESTES
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    //EXCLUIR APÓS TESTES
   
    Serial.println("Decrementando");
    ativaServo(pos);
     Serial.print("Setando Angulo para: ");
    Serial.println(pos);
    pos --;
  }
}

void configSerial(){
  Serial.begin(BAUD);
}

void configPins(){
  
  //EXCLUIR APÓS TESTES
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  //EXCLUIR APÓS TESTES

  pinMode(BOTAO_CRE, INPUT_PULLUP);
  pinMode(BOTAO_DEC, INPUT_PULLUP);
}

void configServo(){
  servo_motor.attach(SERVO_PIN);
}

void ativaServo(int cont){
  servo_motor.write(cont);
}

