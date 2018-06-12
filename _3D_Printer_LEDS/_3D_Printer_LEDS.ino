
const int WhitePin = 6; // Analog output pin that the LED is attached to
const int RedPin = 10; // Analog output pin that the LED is attached to
const int GreenPin = 11; // Analog output pin that the LED is attached to
const int BluePin = 9; // Analog output pin that the LED is attached to
const int PowerOut = 4; //Signal till relä
const int LED2 = 5;   //Utsignal till nivå 2
const int LED3 = 3;   //Utsignal till nivå 3

volatile byte state = LOW;
int count = 0;
boolean flag = true;

int rel = 4;

int RED = 0;        // value read from the RED
int GREEN = 0;        // value read from the GREEN
int BLUE = 0;        // value read from the BLUE

int RedOut = 0;        // value output to the PWM (analog out)
int GreenOut = 0;        // value output to the PWM (analog out)
int BlueOut = 0;        // value output to the PWM (analog out)
int WhiteOut = 0;        // value output to the PWM (analog out)

int PowerR = 0;
int Pot1IN = 0;
int Pot2IN = 0;

int But1 = 0;       //Knapp till printern
int But2 = 0;
int But3 = 0;
int Pot1 = 0;       //Dimmer till nivå två
int Pot2 = 0;       //Dimmer till nivå tre

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(rel,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);
}

void loop() {
  
  // read the analog in value:
  RedOut = analogRead(A1);
  GreenOut = analogRead(A3);
  BlueOut = analogRead(A2);
  
  PowerR = analogRead(A0);
  
  Pot1IN = analogRead(A4);
  Pot2IN = analogRead(A5);
    
 // Serial.println(RedOut);
 // Serial.println(GreenOut);
 // Serial.println(BlueOut);

///////////////////////////////////////////////////////////////
//Läser och sätter ljusstyrkan på nivå 2 //////////////////////
///////////////////////////////////////////////////////////////
  if(Pot1IN < 50){
    digitalWrite(LED2,LOW);
  }
  else if(Pot1IN > 950){
    digitalWrite(LED2,HIGH);
    
  }else if(Pot1IN > 50 && Pot1IN < 950){
    int setlight = map(Pot1IN, 50, 950, 10, 250);
    analogWrite(LED2, setlight);
  }
///////////////////////////////////////////////////////////////
//Läser och sätter ljusstyrkan på nivå 3 //////////////////////
///////////////////////////////////////////////////////////////
  if(Pot2IN < 50){
    digitalWrite(LED3,LOW);
  }
  else if(Pot2IN > 950){
    digitalWrite(LED3,HIGH);
    
  }else if(Pot2IN > 50 && Pot2IN < 950){
    int setlight2 = map(Pot2IN, 50, 950, 10, 250);
    analogWrite(LED3, setlight2);
  }

   //Serial.println(Pot1IN);
   //Serial.println(Pot2IN);
///////////////////////////////////////////////////////////////
//Läser och sätter på eller av printern ///////////////////////
///////////////////////////////////////////////////////////////
  if(PowerR > 300 || state == 1){
    digitalWrite(rel, LOW);
    Serial.println("ON");
  }else{
    digitalWrite(rel,HIGH);
    Serial.println("OFF");
  }
  count++;
  if(count>200){
    flag = true;
    count = 0;
  }
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
  //WhiteOut=0;
  //if(RED>
  /*/ map it to the range of the analog out:
  RedOut = map(RED, 0, 780, 0, 255);
  GreenOut = map(GREEN, 0, 780, 0, 255);
  BlueOut = map(BLUE, 0, 780, 0, 255);
  */

///////////////////////////////////////////////////////////////
// Läser och justerar färgkoderna på Printern /////////////////
///////////////////////////////////////////////////////////////
if(state){
  if (RedOut > 600 && GreenOut > 600){
    if (BlueOut > 600){
       analogWrite(WhitePin, 255);
       analogWrite(RedPin, 0);
       analogWrite(GreenPin, 0);
       analogWrite(BluePin, 0); 
       Serial.println("White");
    }
  }
  else if (RedOut > 600){
    analogWrite(WhitePin, 0);
    analogWrite(RedPin, 255);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
    Serial.println("Red");

  }
  else if (GreenOut > 600){
    analogWrite(WhitePin, 0);
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 255);
    analogWrite(BluePin, 0);
    Serial.println("Green");
  }
  else if (BlueOut > 600){
    analogWrite(WhitePin, 0);
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 255);
    Serial.println("Blue");
  }else{
    analogWrite(WhitePin, 0);
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
  //  Serial.println("Black");
  }
}else{
    analogWrite(WhitePin, 0);
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
  //  Serial.println("Black");
  }  
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////    
  delay(5);
}

void blink() {
  if(flag){
   state = !state;   
   flag = false;
  }

  //delay(50);
  //Serial.println(state);
}
