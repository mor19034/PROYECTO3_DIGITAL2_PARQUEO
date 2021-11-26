/*************************************************************
 * Parking System
 * By Pablo Moreno and Marco Duarte
 * Tiva C and Esp32
 * 
 */
/************************************************************/

// The pins of the Tiva are define

/*Define the Tiva Leds*/
#define BLUE PF_2
#define GREEN PF_3
#define RED PF_1
/*Parking Slot 1*/
#define LED1 PA_6
#define LED2 PA_7
/*Parking Slot 2*/
#define LED3 PC_4
#define LED4 PC_5
/*Parking Slot 3*/
#define LED5 PC_6
#define LED6 PC_7
/*Parking Slot 4*/
#define LED7 PD_6
#define LED8 PD_7

// Variables

int car1 = 0;
int car2 = 0;
int car3 = 0;
int car4 = 0;
const int sensorPin1 = PD_0;
const int sensorPin2 = PD_1;
const int sensorPin3 = PD_2;
const int sensorPin4 = PD_3;

void setup() {
  //Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin1 , INPUT);  //pin as a input
  pinMode(sensorPin2 , INPUT);  
  pinMode(sensorPin3 , INPUT);  
  pinMode(sensorPin4 , INPUT);
  // Leds as a output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
}
 
void loop(){
  
  // Declaring the reading of digital pins
  car1 = digitalRead(sensorPin1);//lectura digital de pin
  car2 = digitalRead(sensorPin2);//lectura digital de pin
  car3 = digitalRead(sensorPin3);//lectura digital de pin
  car4 = digitalRead(sensorPin4);//lectura digital de pin

  
// Parking slot 1
  if (car1 == LOW) {
      //Serial.println("Detectado obstaculo");
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);  
      
  }
  else{
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
  }
// Parking slot 2

  if (car2 == LOW) {
      //Serial.println("Detectado obstaculo");
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);  
  }
  else{
      digitalWrite(LED4, LOW);
      digitalWrite(LED3, HIGH);
  }
  
// Parking slot 3

  if (car3 == LOW) {
      //Serial.println("Detectado obstaculo");
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);  
  }
  else{
      digitalWrite(LED6, LOW);
      digitalWrite(LED5, HIGH);
  }

 // Parking slot 4

  if (car4 == LOW) {
      //Serial.println("Detectado obstaculo");
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, HIGH);  
  }
  else{
      digitalWrite(LED8, LOW);
      digitalWrite(LED7, HIGH);
  }
  delay(1000);
}
