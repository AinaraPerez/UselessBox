#include <Servo.h>

Servo boxServo;  
Servo handServo;

int switchStatus=0, action=1, boxClosed=25, boxOpen=60, handClosed=40, handOpen=168;
const int boxServoPin   =  12;
const int handServoPin    = 3;
const int frontSwitchPin = 4;

void setup() {
  Serial.begin(9600); //activamos los displays

  pinMode(frontSwitchPin, OUTPUT);
  digitalWrite(frontSwitchPin,HIGH);
  
  boxServo.attach(boxServoPin);
  handServo.attach(handServoPin);
  boxServo.write(boxClosed); //caja cerrada
  handServo.write(handClosed); //dedo tumbado
}

void loop() {    

  switchStatus = digitalRead(frontSwitchPin);
  
  if (switchStatus == LOW) {
 
    // <<------------- ACTION 1 ------------->> //
    // ---------------------------------------- //
    // Abrimos y cerramos la caja normal
    if (action == 1) {
      Serial.println("Action 1");
      boxServo.write(boxOpen);                  
      delay(1000);   
      handServo.write(handOpen);
      delay(1000);
      handServo.write(handClosed);
      delay(1000);
      boxServo.write(boxClosed);
      action++;
    }
    // <<------------- ACTION 2 ------------->> //
    // ---------------------------------------- //
    // Abrimos y cerramos la caja normal, pero al final hacemos amago de abrirla
    else if (action == 2) { 
      Serial.println("Action 2");
      boxServo.write(boxOpen);                  
      delay(1000);  
      handServo.write(handOpen);
      delay(1000);
      handServo.write(handClosed);
      delay(1000);
      boxServo.write(boxClosed);
      delay(500); 
      //hacemos un amago de abrirla
      boxServo.write(50);
      delay(2000);
      boxServo.write(boxClosed);
      action++;
    } 
    // <<------------- ACTION 3 ------------->> //
    // ---------------------------------------- //
    // Abrimos caja, forcejeamos con la mano y finalmente cerramos la caja lentamente
    else if (action == 3) {
      Serial.println("Action 3");
      boxServo.write(boxOpen);    
      delay(2000);
      //muevo la mano para delante y para detrás 
      for (int i = 0; i < 8; i++) {
        handServo.write(160);
        delay(170);
        handServo.write(140);
        delay(170);
      }
      delay(1000);
      //y finalmente hacemos que cerramos switch lentamente
      for (int i = 140; i <= 168; i++) {        
        handServo.write(i);
        delay(20);
      }
      delay(500);
      handServo.write(handClosed);
      delay(1000);
      boxServo.write(boxClosed);
      action++;
    } 
    // <<------------- ACTION 4 ------------->> //
    // ---------------------------------------- //
    // Abrimos y cerramos sin mover el dedo, y después cerramos la caja rápidamente
    else if (action == 4) {
      Serial.println("Action 4");
      boxServo.write(boxOpen);    
      delay(2000);
      boxServo.write(boxClosed);
      delay(2000);
      //y cerramos rápidamente
      boxServo.write(boxOpen);
      delay(500);
      handServo.write(handOpen);
      delay(1000);
      handServo.write(handClosed);
      delay(500);
      boxServo.write(boxClosed);
      action++;
    } 
    // <<------------- ACTION 5 ------------->> //
    // ---------------------------------------- //
    // Abrimos y cerramos 4 veces la caja, y al final la cerramos abrimos y cerramos la caja
    else if (action == 5) {
      Serial.println("Action 5");
      for (int i = 0; i < 7; i++) {
        boxServo.write(65);
        delay(250);
        boxServo.write(20);
        delay(250);
      }
      delay(1000);
      boxServo.write(boxOpen);
      delay(3000);
      handServo.write(handOpen);
      delay(1000);
      handServo.write(handClosed);
      delay(400);
      boxServo.write(boxClosed);
      action++;
    } 
    // <<------------- ACTION 6 ------------->> //
    // ---------------------------------------- //
    // Abrimos, esperamos, y cerramos el switch muy lentamente y nos asomamos despues
    else if (action == 6) {
      Serial.println("Action 6");
      boxServo.write(boxOpen);     
      delay(3000);
      for (int i = 40; i <= 173; i++) {        
        handServo.write(i);
        delay(20);
      }
      delay(3000);
      for (int i = 173; i > handClosed; i--) {
        handServo.write(i);
        delay(20);
      }
      boxServo.write(boxClosed);
      delay(1000);
      boxServo.write(50);
      delay(2000);
      boxServo.write(boxClosed);
      action++;
    }
    // <<------------- ACTION 7 ------------->> //
    // ---------------------------------------- //
    // Abrimos muuuuy lentamente, luego abrimos y cerramos rápido, y cerramos switch normal
    else if (action == 7) {
      Serial.println("Action 7");
      for (int i = boxClosed; i < boxOpen; i++) {
        boxServo.write(i);
        delay(50);
      }
      delay(1000);
      for (int i = 0; i < 7; i++) {
        boxServo.write(boxOpen);
        delay(250);
        boxServo.write(boxClosed);
        delay(250);
      }
      delay(1000);
      boxServo.write(boxOpen);                  
      delay(1000);
      handServo.write(handOpen);
      delay(1000);
      handServo.write(handClosed);
      delay(1000);
      //cerramos la caja
      boxServo.write(boxClosed);
      action++;
    }
    // <<------------- ACTION 8 ------------->> //
    // ---------------------------------------- //
    // Abrimos y cerramos switch rápido, pero cerramos la caja lentamente
    else if (action == 8) {
      Serial.println("Action 8");
      boxServo.write(boxOpen);    
      delay(500);
      handServo.write(handOpen);
      delay(1000);
      handServo.write(handClosed);
      for (int i = boxOpen; i > boxClosed; i--) {
        boxServo.write(i);
        delay(200);
      }
      action++;
    } 
    // <<------------- ACTION 9 ------------->> //
    // ---------------------------------------- //
    // Abro la caja lento, bajo rápido, lo mismo dos veces y al final cerramos
    else if (action == 9) {
      Serial.println("Action 9");
      for (int i = boxClosed; i < boxOpen; i++) {
        boxServo.write(i);
        delay(50);
      }
      delay(800);
      boxServo.write(boxClosed);    
      delay(800);
      for (int i = boxClosed; i < boxOpen; i++) {
        boxServo.write(i);
        delay(50);
      }
      delay(2500);
      handServo.write(handOpen);
      delay(1000);
      handServo.write(155);
      delay(250);
      handServo.write(handOpen);
      delay(250);
      handServo.write(155);
      delay(250);
      handServo.write(handOpen);
      delay(250);
      handServo.write(155);
      delay(250);
      handServo.write(handOpen);
      delay(250);
      handServo.write(155);
      delay(250);
      handServo.write(handClosed);
      delay(500);
      boxServo.write(boxClosed);
      action++;
    }
    // <<------------- ACTION 10 ------------>> //
    // ---------------------------------------- //
    // Abro la caja y la cierro y espero a mitad de altura, subiendo y bajando, hasta que toquen switch otra vez para cerrarlo
    else if (action == 10) {
      Serial.println("Action 10");
      boxServo.write(boxOpen);    
      delay(500);
      handServo.write(handOpen);
      delay(1000);
      //////INICIO DE CICLO DE JUEGO
      for (int cont = 0; cont < 5; cont ++) {
        handServo.write(150);
        delay(1000);
        do {
          for (int i = boxOpen; i > 40; i--) {
            switchStatus = digitalRead(frontSwitchPin); //validación intermedia para salir de golpe
            if (switchStatus == LOW) { break; } //validación intermedia para salir de golpe
            boxServo.write(i);
            delay(50);
          }
          for (int i = 40; i < boxOpen; i++) {
            switchStatus = digitalRead(frontSwitchPin); //validación intermedia para salir de golpe
            if (switchStatus == LOW) { break; } //validación intermedia para salir de golpe
            boxServo.write(i);
            delay(50);
          }
          switchStatus = digitalRead(frontSwitchPin);
        } while (switchStatus == HIGH);
        Serial.println("Salimos de bucle");
        handServo.write(handOpen);
        delay(500);
      }
      //////FIN DE CICLO DE JUEGO
      handServo.write(handClosed);
      delay(1000);
      boxServo.write(boxClosed);
      action=1;
    } 
  } else {
    Serial.println("status high");
  }
  delay(1000);
  
  
}
