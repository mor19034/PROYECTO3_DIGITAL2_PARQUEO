int status1;
const int led = 36;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.setTimeout(50);
delay(100);
Serial2.begin(115200);
Serial2.setTimeout(50);
delay(100);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
if (Serial2.available()){
  status1 = Serial2.read();
  Serial.print(status1);
  if(status1 == '0'){
    //Serial.print("0");
    //digitalWrite(led, HIGH);
    
  }
  else{
    digitalWrite(led, LOW);
  }
  
}

}
