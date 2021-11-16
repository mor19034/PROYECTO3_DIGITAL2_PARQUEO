/*************************************************************
 * Parking System
 * By Pablo Moreno and Marco Duarte
 * Tiva C and Esp32
 * 
 */
/************************************************************/

#define BLUE PF_2
#define GREEN PF_3
#define RED PF_1

// Variables

int car1 = 0;
int car2 = 0;
int car3 = 0;
const int sensorPin1 = PD_0;
const int sensorPin2 = PD_1;
const int sensorPin3 = PD_2;

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin1 , INPUT);  //pin as a input
  pinMode(sensorPin2 , INPUT);  //definir pin como entrada
  pinMode(sensorPin3 , INPUT);  //definir pin como entrada
  
  pinMode(BLUE, OUTPUT);// Leds as a output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}
 
void loop(){
  
  // Declaring the reading of digital pins
  car1 = digitalRead(sensorPin1);//lectura digital de pin
  car2 = digitalRead(sensorPin2);//lectura digital de pin
  car3 = digitalRead(sensorPin3);//lectura digital de pin

  
// Parking slot 1
  if (car1 == LOW) {
      Serial.println("Detectado obstaculo");
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);  
  }
  else{
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
  }
// Parking slot 2

  if (car2 == LOW) {
      Serial.println("Detectado obstaculo");
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);  
  }
  else{
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
  }
  
// Parking slot 3

  if (car3 == LOW) {
      Serial.println("Detectado obstaculo");
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);  
  }
  else{
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
  }

 
}
