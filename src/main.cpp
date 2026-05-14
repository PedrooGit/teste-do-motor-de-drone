#include <Arduino.h>
#include <Servo.h>


Servo servoMotor;

#define pinServo 9
#define pinPot A3

int pot;
int ang;
int pot_porcem;


void setup() {
  Serial.begin(9600);
  servoMotor.attach(pinServo);
  pinMode(pinPot, INPUT);
}

void loop() {
  pot = analogRead(pinPot);
  ang = map(pot, 0, 1023, 0, 180);
  pot_porcem = map(pot, 0, 1023, 0, 100);
  servoMotor.write(ang);
  imprimir();
}

void imprimir(){
  delay(1000);
  for (int i = 0; i < 50; i++) {
    Serial.println();
  }
  Serial.print("O valor do potenciometro: ");
  Serial.print(pot_porcem);
  Serial.println("%");
}