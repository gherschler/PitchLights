/*
  PitchLights
  Reads a PWM signal from a servo controller and controls LED lights based on servo command.
  Attach servo control line to pin 12, 
  
*/

int servopin = 12;
int greenpin = 3;
int redpin = 5;
int servozero = 1455;
int servomax = 1900;
int servomin = 1100;
int ledBright = 0;

void setup() {
  Serial.begin(9600); //for debugging purposes
  pinMode(servopin,INPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(redpin,OUTPUT);
}

void loop() {
  int servovalue = pulseIn(servopin,HIGH);
//  Serial.println(servovalue); //for debugging purposes
  if (servovalue != 0) {
    if (servovalue < servozero) {
      ledBright = map(servovalue,servozero,servomin,0,255);
      ledBright = constrain(ledBright,0,255);
      analogWrite(greenpin,ledBright);
      digitalWrite(redpin,LOW);
    }
    else {
      ledBright = map(servovalue,servozero,servomax,0,255);
      ledBright = constrain(ledBright,0,255);
      analogWrite(redpin,ledBright);
      digitalWrite(greenpin,LOW);
    }
//    Serial.println(ledBright);
  }
  else {
    digitalWrite(greenpin,LOW);
    digitalWrite(redpin,LOW);
  }
  delay(1);
}
