const int pwmIn = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pwmIn,INPUT); 
}

void loop() {
  int pwmDisplay = pulseIn(pwmIn, HIGH, 25000);
  Serial.println(pwmDisplay);
  delay(5);
}
