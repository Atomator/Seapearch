//Motor Connections
//Change this if you wish to use another diagram
const int EnA = 10;
const int EnB = 5;
const int In1 = 9;
const int In2 = 8;
const int In3 = 7;
const int In4 = 6;
const int pwmForward = 11;
const int pwmTurn = 12;

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
  pinMode(pwmForward,INPUT); 
  pinMode(pwmTurn, INPUT);
}

void moveMotor(int motor1Speed, int motor2Speed)   //run both motors in the same direction
{
  // turn on motor A
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // set speed to 150 out 255
  analogWrite(EnA, motor2Speed);
  // turn on motor B
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed to 150 out 255
  analogWrite(EnB, motor1Speed);
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
  
  int pwmDisplay = pulseIn(pwmForward, HIGH, 25000);
  int pwmMap = map(pwmDisplay, 1488, 1886, 0, 255);
  Serial.println(pwmMap);
 
  moveMotor(pwmMap, pwmMap);

  delay(5);
}
