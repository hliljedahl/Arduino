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

#include <Tone.h>

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
int fKeyState  = 0;         // variable for reading the pushbutton status
int fFKeyState = 0;
int gKeyState  = 0;
int gFKeyState = 0;
int aKeyState  = 0;
int aFKeyState = 0;
int bKeyState  = 0;

int buzzState  =  0;
char lastTone1 = '0';
char lastTone2 = '0';
char key   = '0';
int note = 0;
int noteF = NOTE_F5;
int notef = NOTE_FS5;
int noteG = NOTE_G5;
int noteg = NOTE_GS5;
int noteA = NOTE_A5;
int notea = NOTE_AS5;
int noteB = NOTE_B5;

int loopvar = 0;

Tone buzzer[2];

void setup() {
  Serial.begin(9600);

  buzzer[0].begin(3);
  buzzer[1].begin(6);
  
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
  
  digitalWrite(rLED, HIGH);
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

  if (buzzer[0].isPlaying() || buzzer[1].isPlaying()) {
    digitalWrite(gLED, HIGH);
  }
  else {
    digitalWrite(gLED, LOW);
  }
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
  
  key = 'F';
  note = noteF;
  
  if (fKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }
///////////////////////////////////////////////////////////////////////////////
///////// F# KEY //////////////////////////////////////////////////////////////

  key = 'f';
  note = notef;
  
  if (fFKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }

///////////////////////////////////////////////////////////////////////////////
///////// G KEY //////////////////////////////////////////////////////////////

  key = 'G';
  note = noteG;
  
  if (gKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }

///////////////////////////////////////////////////////////////////////////////
///////// G# KEY //////////////////////////////////////////////////////////////

  key = 'g';
  note = noteg;
  
  if (gFKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }

///////////////////////////////////////////////////////////////////////////////
///////// A KEY //////////////////////////////////////////////////////////////

  key = 'A';
  note = noteA;
  
  if (aKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }

///////////////////////////////////////////////////////////////////////////////
///////// A# KEY //////////////////////////////////////////////////////////////
 
  key = 'a';
  note = notea;
  
  if (aFKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }

///////////////////////////////////////////////////////////////////////////////
///////// B KEY //////////////////////////////////////////////////////////////

  key = 'B';
  note = noteB;
  
  if (bKeyState == HIGH) {
    if (lastTone1 != key && lastTone2 != key) {
      if (buzzState == 0) {
        buzzer[0].play(note);
        buzzState = 1;
        lastTone1 = key;
      }
      else if (buzzState == 1) {
        buzzer[1].play(note);
        buzzState = 0;
        lastTone2 = key;
      }
    }
    else if (lastTone1 == key) {
      buzzer[0].play(note);
    }
    else if (lastTone2 == key) {
      buzzer[1].play(note);
    }
  }
  else {
    if (lastTone1 == key) {
      if (buzzer[0].isPlaying()) {
        buzzer[0].stop();
      }
    }
    if (lastTone2 == key) {
      if (buzzer[1].isPlaying()) {
        buzzer[1].stop();
      }
        //noTone(buzz2);
    }
  }

///////////////////////////////////////////////////////////////////////////////

}
