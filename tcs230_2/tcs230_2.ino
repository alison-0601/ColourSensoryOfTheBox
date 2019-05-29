#define S0 7
#define S1 9
#define S2 12
#define S3 11
#define sensorOut 10

int dataR = 0;
int dataG = 0;
int dataB = 0;

#include "pitches.h"

// notes in the melody:
int melody[] = {
 //NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4, NOTE_C4, NOTE_G3
 NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 8
};

int melody1[] = {
 NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4
};
int noteDurations1[] = {
  8, 8, 8, 8, 6, 16, 4
};

int melody2[] = {
 NOTE_C4, NOTE_C4, NOTE_D4,  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4
};
int noteDurations2[] = {
  8, 8, 8, 8, 6, 16, 4
};

int thisNote;
int noteDuration;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);//LOW
  
  Serial.begin(9600);

  
}

void loop() {
  
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  dataR = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
 //dataR = map(dataR, 25,160,255,0);
  // Printing the value on the serial monitor
  /*Serial.print("R= ");//printing name
  Serial.print(dataR);//printing RED color frequency
  Serial.print("  ");*/
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);//HIGH
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  dataG = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //dataG = map(dataG, 25,200,255,0);
  // Printing the value on the serial monitor
  /*Serial.print("G= ");//printing name
  Serial.print(dataG);//printing RED color frequency
  Serial.print("  ");*/
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);//LOW
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  dataB = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //dataB = map(dataB, 20,170,255,0);
  // Printing the value on the serial monitor
  /*Serial.print("B= ");//printing name
  Serial.print(dataB);//printing RED color frequency
  Serial.println("  ");*/
  delay(200);

/*Serial.print("R=");
Serial.print(dataR);
Serial.print(" ");
Serial.print("G=");
Serial.print(dataG);
Serial.print(" ");
Serial.print("B=");
Serial.println(dataB);
*/

if(dataR>20 && dataR<160 && dataG>20 &&dataG<160 && dataB>20 &&dataB<160)
{
  if(dataR < dataG && dataR < dataB)
  {
    Serial.print("R= ");//printing name
    Serial.println(dataR);//printing RED color frequency

    /*for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration1 = 3000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);}*/
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 3000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  //delay(2000);

  }
  if(dataG < dataR && dataG < dataB)
  {
    Serial.print("G= ");//printing name
    Serial.println(dataG);//printing RED color frequency

   for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration2 = 3000 / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration2);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration2 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  }
  if(dataB < dataR && dataB < dataR)
  {
    Serial.print("B= ");//printing name
    Serial.println(dataB);//printing RED color frequency

     for (int thisNote = 0; thisNote < 7; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration1 = 3000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);}
  }
}
}
