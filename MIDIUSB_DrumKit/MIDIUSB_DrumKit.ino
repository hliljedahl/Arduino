/*
 * MIDIUSB_DrumKit.ino
 *
 * Created: 4/6/2015 10:47:08 AM
 * Author: gurbrinder grewal
 * 
 * Modified by Hampus Liljedahl (2018)
 * LiljedahlLabs.se
 */ 

#include "MIDIUSB.h"

#define snarePin A0
#define hihatPin A1
#define crashPin A2

void setup() {
  Serial.begin(115200);
}

void loop() {
  int snare = analogRead(snarePin);
  int hihat = analogRead(hihatPin);
 // int crash = analogRead(crashPin);
  
  //Serial.println(snare);
  if (snare > 300 ){
    int vel = map(snare, 300, 1023, 1, 127);
    noteOn(0, 38, vel);   // Channel 0, E3
    MidiUSB.flush(); 
    delay(1);
    noteOff(0, 38, vel);  // TurnOff E3
    MidiUSB.flush();
    //delay(4);
  }
  if (hihat > 200 ){
    //if (hihat > 300 ){
      int vel = map(hihat, 300, 1023, 1, 127);
      noteOn(1, 42, vel);   // Channel 1, A#3
      MidiUSB.flush();
      //delay(4);
      noteOff(1, 42, vel);  // Turn Off A#3
      MidiUSB.flush();
      //delay(4);
   }
    /*
    else {
      int vel = map(hihat, 100, 600, 1, 100);
      noteOn(2, 42, vel);   // Channel 1, F#3
      MidiUSB.flush();
      noteOff(2, 42, vel);  // TurnOff F#3
      MidiUSB.flush(); 
    }*/
  /*if (crash > 30 ){
    int vel = map(snare, 30, 1023, 1, 100);
    noteOn(3, 50, vel);   // Channel 0, E3
    MidiUSB.flush(); 
    noteOff(3, 50, vel);  // TurnOff E3
    MidiUSB.flush();
  }*/

  
  /*
  Serial.println("Sending note on");
  noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
  MidiUSB.flush();
  delay(500);
  Serial.println("Sending note off");
  noteOff(0, 48, 64);  // Channel 0, middle C, normal velocity
  MidiUSB.flush();
  delay(1500);
  */
  // controlChange(0, 10, 65); // Set the value of controller 10 on channel 0 to 65
}


/************************************************************************
 *************************************************************************
 * First parameter is the event type (0x09 = note on, 0x08 = note off).
 * Second parameter is note-on/note-off, combined with the channel.
 * Channel can be anything between 0-15. Typically reported to the user as 1-16.
 * Third parameter is the note number (48 = middle C).
 * Fourth parameter is the velocity (64 = normal, 127 = fastest).
 */
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

/************************************************************************
 *************************************************************************
 * First parameter is the event type (0x0B = control change).
 * Second parameter is the event type, combined with the channel.
 * Third parameter is the control number number (0-119).
 * Fourth parameter is the control value (0-127).
 */
void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
/************************************************************************/

