int outPin = 2; // IR sensor

//ultrasonic
int trigPin = 13; // 'trig' pin defintion
int echoPin = 11; // 'echo' pin definition
double pingTime; // variable to hold
double DIST_SCALE = 108.5767;// **MODIFY TO YOUR OWN**
double SPEED_OF_SOUND = 331.0; // Approx. speed of sound
double convert = 1000000.0; // factor to scale pingTime

//right wheel
int enA = 9;
int in1 = 8;
int in2 = 7;

//left wheel
int enb = 3;
int in3 = 5;
int in4 = 4;


int speed = 200;
int turnSpeed = 50;
int turnCounter = 0;
bool pastMaze = false;

void setup() {
  Serial.begin(9600);
  pinMode(outPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.println("Done setup");
}

void turnLeft(){
  // right backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, turnSpeed);

  //left forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, turnSpeed);
}

void turnRight(){
  // right forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, turnSpeed);
  
  //left backward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, turnSpeed);

  delay(2000); 
}

void forward(){
  // right forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speed);

  //left forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enb, speed);
}

void backward(){
  // right backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speed);

  //left backward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enb, speed);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enb, 0);
}

void loop() {
  int out = digitalRead(outPin); // 1 for black, 0 for white;

  digitalWrite(trigPin, LOW); // Set pin to low before pulse
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH); // Send ping
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Set pin to low again
  pingTime = pulseIn(echoPin, HIGH); // Receive the echo from the pulse 
  double dist = DIST_SCALE*0.5*(SPEED_OF_SOUND*(pingTime/convert)); // Convert to distance

  turnLeft();
  delay(800);
  stop();
  delay(800);

  /*if (dist < 5){
      if (turnCounter%2 == 0){
        turnRight();
      }
      else{
        turnLeft();
      }

      turnCounter += 1;
      if (turnCounter == 4){
        pastMaze = true;
        forward();
        delay(3000); 
      }
    }
    else{
      forward();
    }
  }

  stop(); */

}

//system.out.println("Hello World");
