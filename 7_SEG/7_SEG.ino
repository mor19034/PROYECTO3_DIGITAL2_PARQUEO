const int A = 27;
const int B = 14;
const int C = 12;
const int D = 13;
const int E = 6;
const int F = 5;
const int G = 14;
 
const int N = 7;
const int SEGMENTOS[N] = {A,B,C,D,E,F,G};

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);

  
}


void loop()
{
  
  digitalWrite(27, HIGH); // A
  digitalWrite(14, HIGH); // B
  digitalWrite(12, HIGH); // C
  digitalWrite(13, HIGH); // D
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  /*
  delay(1000);
  digitalWrite(27, HIGH); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, HIGH); //
  digitalWrite(13, HIGH); //
  digitalWrite(9, HIGH); //
  digitalWrite(10, HIGH); //
  digitalWrite(11, LOW); //
  delay(1000);
  digitalWrite(27, LOW); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, HIGH); //
  digitalWrite(13, LOW); //
  digitalWrite(9, LOW); //
  digitalWrite(10, LOW); //
  digitalWrite(11, LOW); //
  /*
  //0
    if (status2 == '1') {
      Serial.print('1');
      digitalWrite(33, HIGH); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, HIGH); //
      digitalWrite(12, HIGH); //
      digitalWrite(25, HIGH); //
      digitalWrite(26, LOW); //
      delay(1000);
    }
    else if (status2 == '2') {
      //1
      digitalWrite(33, LOW); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, LOW); //
      digitalWrite(12, LOW); //
      digitalWrite(25, LOW); //
      digitalWrite(26, LOW); //
      delay(1000);
    }
    else if (status2 == '2') {
      //2
      digitalWrite(33, HIGH); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, LOW); //
      digitalWrite(14, HIGH); //
      digitalWrite(12, HIGH); //
      digitalWrite(25, LOW); //
      digitalWrite(26, HIGH); //
      delay(1000);
    }
    else if (status2 == '3') {
      //3
      digitalWrite(33, HIGH); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, HIGH); //
      digitalWrite(12, LOW); //
      digitalWrite(25, LOW); //
      digitalWrite(26, HIGH); //
      delay(1000);
    }
    else if (status2 == '4') {
      //4
      digitalWrite(33, LOW); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, LOW); //
      digitalWrite(12, LOW); //
      digitalWrite(25, HIGH); //
      digitalWrite(26, HIGH); //
      delay(1000);
    }
    else  if (status2 == '5') {
      //5
      digitalWrite(33, HIGH); //
      digitalWrite(32, LOW); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, HIGH); //
      digitalWrite(12, LOW); //
      digitalWrite(25, HIGH); //
      digitalWrite(26, HIGH); //
      delay(1000);
    }
    else if (status2 == '6') {
      //6
      digitalWrite(33, LOW); //
      digitalWrite(32, LOW); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, HIGH); //
      digitalWrite(12, HIGH); //
      digitalWrite(25, HIGH); //
      digitalWrite(26, HIGH); //
      delay(1000);
    }
    else if (status2 == '7') {
      //7
      digitalWrite(33, HIGH); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, LOW); //
      digitalWrite(12, LOW); //
      digitalWrite(25, LOW); //
      digitalWrite(26, LOW); //
      delay(1000);
    }
    else if (status2 == '8') {
      //8
      digitalWrite(33, HIGH); //
      digitalWrite(32, HIGH); //
      digitalWrite(27, HIGH); //
      digitalWrite(14, HIGH); //
      digitalWrite(12, HIGH); //
      digitalWrite(25, HIGH); //
      digitalWrite(26, HIGH); //
      delay(1000);
    }
  }
  */
}
