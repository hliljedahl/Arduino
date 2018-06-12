/*
  Synth

  7 keys synth.
  Congratz to the love of my life
  
  The circuit:
  - gLED attached from pin XX to ground
  - rLED attached from pin XX to ground
  
  - fKey attached to pin 3 from +5V
  - f#Key attached to pin 4 from +5V
  - gKey attached to pin 5 from +5V
  - g#Key attached to pin 8 from +5V
  - aKey attached to pin 9 from +5V
  - a#Key attached to pin 10 from +5V
  - bKey attached to pin 11 from +5V

  - buzzer attached to pin 3 from +5V

  - Note: 

  created 2018
  by LiljedahlLabs
  modified 30 Aug 2018
  by Hampus Liljedahl

  http://www.liljedahllabs.se/
*/

#define  C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03

// constants won't change. They're used here to set pin numbers:
const int fKey  = 2;     //11
const int fFKey = 4;     //10
const int gKey  = 5;     //9
const int gFKey = 8;     //8
const int aKey  = 9;     //5
const int aFKey = 10;    //4
const int bKey  = 11;    //2

const int buzz1 = 3;     //
const int buzz2 = 6;     //

const int gLED =  12;    //
const int rLED =  7;    //

// variables will change:
int fKeyState = 0;         // variable for reading the pushbutton status
int fFKeyState = 0;
int gKeyState = 0;
int gFKeyState = 0;
int aKeyState = 0;
int aFKeyState = 0;
int bKeyState = 0;

int buzzState = 0;
char lastTone1 = '0';
char lastTone2 = '0';

int loopvar = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LEDs as an output:
  pinMode(gLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  // initialize the buzzera as an output:
  pinMode(buzz1, OUTPUT);
  pinMode(buzz2, OUTPUT);
  // initialize the pushbuttons as an input:
  pinMode(fKey, INPUT);
  pinMode(fFKey, INPUT);
  pinMode(gKey, INPUT);
  pinMode(gFKey, INPUT);
  pinMode(aKey, INPUT);
  pinMode(aFKey, INPUT);
  pinMode(bKey, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  fKeyState = digitalRead(fKey);
  fFKeyState = digitalRead(fFKey);
  gKeyState = digitalRead(gKey);
  gFKeyState = digitalRead(gFKey);
  aKeyState = digitalRead(aKey);
  aFKeyState = digitalRead(aFKey);
  bKeyState = digitalRead(bKey);

  if (loopvar == 20000) {
    Serial.print("lastTone1: ");
    Serial.println(lastTone1);
    Serial.print("lastTone2: ");
    Serial.println(lastTone2);
    Serial.print("buzzState: ");
    Serial.println(buzzState);
    Serial.println("     ");
    loopvar = 0;
  }
  loopvar++;

///////////////////////////////////////////////////////////////////////////////
///////// F KEY //////////////////////////////////////////////////////////////
  if (fKeyState == HIGH) {
    //Serial.println("fKey");
    if (lastTone1 == 'F') {
      tone(buzz1, F5);
    }
    else if (lastTone2 == 'F') {
      tone(buzz2, F5);
    }
    else {
      
    }
  }
  
  
  /*if (fKeyState == HIGH) {
    //Serial.println("fKey");
    if (lastTone1 == 'F') {
      tone(buzz1, F5);
      if (lastTone1 =! 'F') {
        buzzState = 1;
      }
     lastTone1 = 'F';
    }else {
     tone(buzz2, F5); // Send 1KHz sound signal...
     if (lastTone2 =! 'F') {
        buzzState = 0;
      }
     lastTone2 = 'F';
    }
  }
  else {
    if (lastTone1 == 'F') {
        noTone(buzz1);
    }
    if (lastTone2 == 'F') {
        noTone(buzz2);
    }
  }
  */
///////////////////////////////////////////////////////////////////////////////
///////// F# KEY //////////////////////////////////////////////////////////////
  if (fFKeyState == HIGH) {
    //Serial.println("f#Key");
    if (buzzState == 0) {
      tone(buzz1, Gb5);
      if (lastTone1 =! 'f') {
        buzzState = 1;
      }
     lastTone1 = 'f';
    }else {
     tone(buzz2, Gb5); // Send 1KHz sound signal...
     if (lastTone2 =! 'f') {
        buzzState = 0;
      }
     lastTone2 = 'f';
    }
  }
  else {
    if (lastTone1 == 'f') {
        noTone(buzz1);
    }
    if (lastTone2 == 'f') {
        noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////
///////// G KEY //////////////////////////////////////////////////////////////
  if (gKeyState == HIGH) {
   // Serial.println("gKey");
    if (buzzState == 0) {
      tone(buzz1, G5);
      if (lastTone1 =! 'G') {
        buzzState = 1;
      }
     lastTone1 = 'G';
    }else {
     tone(buzz2, G5); // Send 1KHz sound signal...
     if (lastTone2 =! 'G') {
        buzzState = 0;
      }
     lastTone2 = 'G';
    }
  }
  else {
    if (lastTone1 == 'G') {
        noTone(buzz1);
    }
    if (lastTone2 == 'G') {
        noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////
///////// G# KEY //////////////////////////////////////////////////////////////
  if (gFKeyState == HIGH) {
    //Serial.println("g#Key");
    if (buzzState == 0) {
      tone(buzz1, Ab5);
      if (lastTone1 =! 'g') {
        buzzState = 1;
      }
     lastTone1 = 'g';
    }else {
     tone(buzz2, Ab5); // Send 1KHz sound signal...
     if (lastTone2 =! 'g') {
        buzzState = 0;
      }
     lastTone2 = 'g';
    }
  }
  else {
    if (lastTone1 == 'g') {
        noTone(buzz1);
    }
    if (lastTone2 == 'g') {
        noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////
///////// A KEY //////////////////////////////////////////////////////////////
  if (aKeyState == HIGH) {
    //Serial.println("aKey");
    if (buzzState == 0) {
      tone(buzz1, LA5);
      if (lastTone1 =! 'A') {
        buzzState = 1;
      }
     lastTone1 = 'A';
    }else {
     tone(buzz2, LA5); // Send 1KHz sound signal...
     if (lastTone2 =! 'A') {
        buzzState = 0;
      }
     lastTone2 = 'A';
    }
  }
  else {
    if (lastTone1 == 'A') {
        noTone(buzz1);
    }
    if (lastTone2 == 'A') {
        noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////
///////// A# KEY //////////////////////////////////////////////////////////////
  if (aFKeyState == HIGH) {
    //Serial.println("a#Key");
    if (buzzState == 0) {
      tone(buzz1, Bb5);
      if (lastTone1 =! 'a') {
        buzzState = 1;
      }
     lastTone1 = 'a';
    }else {
     tone(buzz2, Bb5); // Send 1KHz sound signal...
     if (lastTone2 =! 'a') {
        buzzState = 0;
      }
     lastTone2 = 'a';
    }
  }
  else {
    if (lastTone1 == 'a') {
        noTone(buzz1);
    }
    if (lastTone2 == 'a') {
        noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////
///////// B KEY //////////////////////////////////////////////////////////////
  if (bKeyState == HIGH) {
    //Serial.println("bKey");
    if (buzzState == 0) {
      tone(buzz1, B5);
      if (lastTone1 =! 'B') {
        buzzState = 1;
      }
     lastTone1 = 'B';
    }else {
     tone(buzz2, B5); // Send 1KHz sound signal...
     if (lastTone2 =! 'B') {
        buzzState = 0;
      }
     lastTone2 = 'B';
    }
  }
  else {
    if (lastTone1 == 'B') {
        noTone(buzz1);
    }
    if (lastTone2 == 'B') {
        noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////


  
  
  
}
