//Motor Connections
//Change this if you wish to use another diagram
const int EnA = 10;
const int EnB = 5;
const int In1 = 9;
const int In2 = 8;
const int In3 = 7;
const int In4 = 6;
const int pulseForward = 11;
const int pulseTurn = 12;

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
  pinMode(pulseForward,INPUT); 
  pinMode(pulseTurn, INPUT);
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

  // Puts pulse from pin 11 (pulseForward) into a variable
  int pwmForward = pulseIn(pulseForward, HIGH, 25000);
  // Maps elev stick values from 0 to 255 for use as pwm
  int mapForward = map(pwmForward, 1488, 1886, 0, 255);
  
  // Puts pulse from pin 12 (pulseForward) into a variable
  int pwmTurn = pulseIn(pulseTurn, HIGH, 25000);
  
  // Prints to console for debugging
  // Serial.println(mapForward);

  // 1484 is the middle value, higher than that means the stick is going left, and lower than that means the stick is going right

  // Turns the sub left by slowing down the left motor
  if (pulseTurn > 1490){
    int mapTurn = map(pulseTurn, 1490, 1873, mapForward, 0);
    // moveMotor(mapForward, mapTurn);
    Serial.print("motorRight: ");
    Serial.println(mapForward);
    Serial.print("motorLeft: ");
    Serial.println(mapTurn);
  }

  // Turns the sub right by slowing down the right motor
  if (pulseTurn < 1470){
    int mapTurn = map(pulseTurn, 1470, 1077, mapForward, 0);
    // moveMotor(mapTurn, mapForward);
    Serial.print("motorRight: ");
    Serial.println(mapTurn);
    Serial.print("motorLeft: ");
    Serial.println(mapForward);
  }

  else {
    // Sets each motor value to pwmMap
    // moveMotor(mapForward, mapForward);
  }
  
  delay(5);
}
