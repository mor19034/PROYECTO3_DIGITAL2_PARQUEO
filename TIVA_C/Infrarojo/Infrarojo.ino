#define BLUE PF_2
#define GREEN PF_3
#define RED PF_1

const int sensorPin = PD_0;

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin , INPUT);  //definir pin como entrada
  // put your setup code here, to run once:
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}
 
void loop(){
  int value = 0;
  //value = digitalRead(sensorPin);
  value = digitalRead(sensorPin);//lectura digital de pin
 
  if (value == LOW) {
      Serial.println("Detectado obstaculo");
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);  
  }
  else{
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
  }
  delay(1000);
}
