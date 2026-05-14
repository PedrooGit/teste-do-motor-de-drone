#include <Arduino.h>  //add biblioteca para usar o arduino no vs code, tirar na interface do arduino ide
#include <Servo.h>  //add biblioteca para usar o motor do drone (servo como o motor)

Servo servoMotor; //add o motor no codigo

#define pinServo 9 //define o pino do servo, que vai receber o valor do potenciometro depois
#define pinPot A0 //define o pino do potenciometro


//vars para receberem valores que seram usados depois
int pot;
int ang;
int pot_porcem;


void setup() {
    Serial.begin(9600); //inicia a serial
    servoMotor.attach(pinServo);  //define o pino do servo para o pinServo
    pinMode(pinPot, INPUT); //define o pino do potenciometro
}

void loop() {
    pot = analogRead(pinPot); //lê o valor potenciometro
    ang = map(pot, 0, 1023, 0, 180); //colocar o valor lido do pot para o valor que o motor do drone entenda nos testes
    pot_porcem = map(pot, 0, 1023, 0, 100); //pega a porcentagem do valor do portenciometro, para saber quantos porcentro o drone esta operando
    servoMotor.write(ang); //manda para o drone o valor
    imprimir(); //traz a função imprimir
}

void imprimir(){
    delay(1000);  //delay de 1s
    for (int i = 0; i < 50; i++) {
        Serial.println(); // Imprime 50 linhas em branco p/ ler melhor
    }
    //imprime o valor da porcentagem
    Serial.print("O valor do potenciometro: ");
    Serial.print(pot_porcem);
    Serial.println("%");
}