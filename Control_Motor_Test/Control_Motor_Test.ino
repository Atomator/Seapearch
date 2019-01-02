//Motor Connections
//Change this if you wish to use another diagram
const int EnA = 10;
const int EnB = 5;
const int In1 = 9;
const int In2 = 8;
const int In3 = 7;
const int In4 = 6;
const int pwmIn = 11;

void setup()
{
  // All motor control pins are outputs
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  Serial.begin(9600);
  pinMode(pwmIn,INPUT); 
}

void goStraight(int pwmSpeed)   //run both motors in the same direction
{
  // turn on motor A
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // set speed to 150 out 255
  analogWrite(EnA, pwmSpeed);
  // turn on motor B
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed to 150 out 255
  analogWrite(EnB, pwmSpeed);
  delay(5);
}

void stopMotor()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void loop()
{
  
  int pwmDisplay = pulseIn(pwmIn, HIGH, 25000);
  int pwmMap = map(pwmDisplay, 890, 2087, 0, 255);
  Serial.println(pwmMap);
 
  goStraight(pwmMap);

  delay(5);
}
