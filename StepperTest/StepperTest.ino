// Run a A4998 Stepstick from an Arduino UNO.
// Paul Hurley Aug 2015
int x; 
#define BAUD (9600)


void setup() 
{
  Serial.begin(BAUD);
  pinMode(6,OUTPUT); // Enable
  pinMode(5,OUTPUT); // Step
  pinMode(4,OUTPUT); // Dir
  digitalWrite(6,LOW); // Set Enable low
}

void loop() 
{
  digitalWrite(6,LOW); // Set Enable low
  digitalWrite(4,HIGH); // Set Dir high
  Serial.println("Loop 200 steps (1 rev)");
  for(x = 0; x < 2000; x++) // Loop 200 times
  {
    digitalWrite(5,HIGH); // Output high
    delay(1); // Wait
    digitalWrite(5,LOW); // Output low
    delay(1); // Wait
  }
  Serial.println("Pause");
  delay(3000); // pause one second

  digitalWrite(4,LOW); // Set Dir high
  Serial.println("Loop 200 steps (1 rev)");
  for(x = 0; x < 2000; x++) // Loop 200 times
  {
    digitalWrite(5,HIGH); // Output high
    delay(1); // Wait
    digitalWrite(5,LOW); // Output low
    delay(1); // Wait
  }
  Serial.println("Pause");
  delay(3000); // pause one second
}
