int enableLeft = 9;
int redLeft = 8; 
int yellowLeft = 7;
int enableRight = 10;
int yellowRight = 12;
int redRight = 11;
int pulseCounter = 0;

volatile int leftCounter = 0, rightCounter = 0;

void leftMotorISR()
{
  leftCounter++;
  //Serial.println(leftCounter);
}

  void rightMotorISR() {
  rightCounter++;
  //Serial.println(rightCounter);
  }


void setup() {
  // put your setup code here, to run once:

  pinMode(enableLeft, OUTPUT);
  pinMode(redLeft, OUTPUT);
  pinMode(yellowLeft, OUTPUT);
  
  pinMode(enableRight, OUTPUT);
  pinMode(yellowRight, OUTPUT);
  pinMode(redRight, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(3), rightMotorISR, RISING);
}

  
void forward() {
  analogWrite(enableLeft, 100);
  digitalWrite(redLeft, HIGH);  
  digitalWrite(yellowLeft, LOW);
  
  analogWrite(enableRight, 100);
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, LOW); 

  void back() {
  analogWrite(enableLeft, 100);
  digitalWrite(redLeft, LOW);  
  digitalWrite(yellowLeft, HIGH);
  
  analogWrite(enableRight, 100);
  digitalWrite(yellowRight, LOW); 
  digitalWrite(redRight, HIGH); 

  int error = abs(leftCounter - rightCounter);

  if(0 < error < 20){
    analogWrite(enableRight, 100);
    analogWrite(enableLeft, 100);
  }

  else{
    if(leftCounter > rightCounter) {
      while(error > 20) {
        analogWrite(enableRight, 100);
        analogWrite(enableLeft, 92);
      }
    }

    if(rightCounter > leftCounter) {
      while(error > 20) {
        analogWrite(enableLeft, 100);
        analogWrite(enableRight, 92);
      }
    }
  }
}

void turnleft() {
  digitalWrite(enableLeft, HIGH);
  digitalWrite(redLeft, HIGH);
  digitalWrite(yellowLeft,LOW);

  digitalWrite(enableRight, HIGH);
  digitalWrite(redRight, HIGH);
  digitalWrite(yellowRight, LOW);
}

void turnright() {
  digitalWrite(enableLeft, HIGH);
  digitalWrite(redLeft, LOW);
  digitalWrite(yellowLeft,HIGH);

  digitalWrite(enableRight, HIGH);
  digitalWrite(redRight, LOW);
  digitalWrite(yellowRight, HIGH);
}

void stoppeth(){
  digitalWrite(enableLeft, HIGH);   // left 111, right 111 (stoppeth)
  digitalWrite(redLeft, HIGH); 
  digitalWrite(yellowLeft, HIGH);  
  
  digitalWrite(enableRight, HIGH); 
  digitalWrite(yellowRight, HIGH); 
  digitalWrite(redRight, HIGH);
  
 }


void loop() {
  // put your main code here, to run repeatedly:

  while(leftCounter < 100 or rightCounter < 100)
    {
       forward();
      delay(2500);
      turnleft();
      delay(720);
      stoppeth();
      delay(500);
      forward();
      delay(2500);
      turnleft();
      delay(740);
      stoppeth();
      delay(500);
      forward();
      delay(2500);
      turnleft();
      delay(825);
      stoppeth();
      delay(500);
      forward();
      delay(2600);
      
      forward();
      delay(2300);
      turnright();
      delay(750);
      stoppeth();
      delay(500);
      forward();
      delay(2500);
      turnright();
      delay(750);
      stoppeth();
      delay(500);
      forward();
      delay(2425);
      turnright();
      delay(750);
      stoppeth();
      delay(500);
      forward();
      delay(2525);

      back();
      delay(2500);
      turnright();
      delay(720);
      stoppeth();
      delay(500);
      back();
      delay(2500);
      turnright();
      delay(740);
      stoppeth();
      delay(500);
      back();
      delay(2500);
      turnright();
      delay(825);
      stoppeth();
      delay(500);
      back();
      delay(2600);
      
      back();
      delay(2300);
      turnleft();
      delay(750);
      stoppeth();
      delay(500);
      back();
      delay(2500);
      turnleft();
      delay(750);
      stoppeth();
      delay(500);
      back();
      delay(2425);
      turnleft();
      delay(750);
      stoppeth();
      delay(500);
      back();
      delay(2525);
    } 
      stoppeth();
      exit(0);
}

