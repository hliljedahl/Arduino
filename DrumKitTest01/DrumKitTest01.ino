#define snarePin A0
#define hihatPin A1

void setup() {
  Serial.begin(115200);
}

void loop() {
  int snare = analogRead(snarePin);
  int hihat = analogRead(hihatPin);
  Serial.print("snare: ");
  Serial.println(snare);
  Serial.print("hihat: ");
  Serial.println(hihat);
  if (snare > 50 ){
    int vel = map(snare, 50, 1023, 1, 127);

  }
  if (hihat > 50 ){
    if (hihat > 500 ){
      int vel = map(hihat, 500, 1023, 40, 127);

    }
    else {
      int vel = map(hihat, 50, 500, 1, 100);

    }
    
  }
}
