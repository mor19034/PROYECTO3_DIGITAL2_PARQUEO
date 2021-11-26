#define push PF_4
#define push2 PF_0
#define blue PF_2
int active, active2;
int push3;
int push1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(50);
  delay(100);
  Serial3.begin(115200);
  Serial3.setTimeout(50);
  delay(100);
  pinMode(push, INPUT_PULLUP);
  pinMode(push2, INPUT_PULLUP);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  active = digitalRead(push);
  active2 = digitalRead(push2);
/*
   // Antirrebote
  if (active == HIGH){
    push3 = 1;
  }
  if (active2 == HIGH){
    push1 = 1;
  }
  */
  if(active == 0 /*& push3 == 1*/){
    Serial3.write('0');
    Serial.write("0");
    digitalWrite(blue, HIGH);
    push3 = 0;
  }
  else{
    digitalWrite(blue, LOW);
  }
  if(active2 == 0/* & push1 == 1*/){
    Serial3.write('1');
    Serial.write("1");
    digitalWrite(blue, HIGH);
    push1 = 0;
  }
  else{
    digitalWrite(blue, LOW);
  }
    
}
