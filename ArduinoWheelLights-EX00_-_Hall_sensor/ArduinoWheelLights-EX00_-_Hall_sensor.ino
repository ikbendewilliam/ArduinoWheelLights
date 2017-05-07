static const int PIN_MINUS = 8;
static const int PIN_PLUS = 9;
static const int PIN_SENSOR = 10;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MINUS, OUTPUT);
  pinMode(PIN_PLUS, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);

  digitalWrite(PIN_MINUS, LOW);
  digitalWrite(PIN_PLUS, HIGH);
}

void loop() {
  while (digitalRead(PIN_SENSOR) == HIGH)
  {
    doNothing();
  }
  Serial.println("Found signal");
  while (digitalRead(PIN_SENSOR) == LOW)
  {
    doNothing();
  }
}

void doNothing()
{
  delay(1);
  }

