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

void moveMotor(int motorRight, int motorLeft)   //run both motors in the same direction
{
  // turn on motor right
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  // set speed to motorRight
  analogWrite(EnA, motorRight);
  
  // turn on motor left
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  // set speed to motorLeft
  analogWrite(EnB, motorLeft);
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

  // Puts pulse from pin 12 (pwmForward) into a variable
  int pwmDisplay = pulseIn(pwmForward, HIGH, 25000);
  // Maps values from 0 to 255 for use as pwm
  int pwmMap = map(pwmDisplay, 1488, 1886, 0, 255);
  // Prints to console for debugging
  Serial.println(pwmMap);

  // Sets each motor value to pwmMap
  moveMotor(pwmMap, pwmMap);

  delay(5);
}
