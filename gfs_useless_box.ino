//n=nichts, b=beides, t=ton, l=licht, s=schalter
int s;
int r;
#include <Arduino.h>


const int RED = 6;
const int GREEN = 5;
const int BLUE = 3;
#define STEPPER_PIN_1 10
#define STEPPER_PIN_2 11
#define STEPPER_PIN_3 12
#define STEPPER_PIN_4 13
int step_number = 0;
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0


int tempo=144; 


int buzzer = 9;





int melody[] = {

 
  
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
  

  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,

};


int notes=sizeof(melody)/sizeof(melody[0])/2; 
//pin(9)

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;


void setup() {
pinMode(4,INPUT_PULLUP);
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
}




void loop() {
s=digitalRead(4);
if(s==1) randomSeed(analogRead(A1));
r=random(1,5);
if(r==1) nichts(); 
if(r==2) beides();
if(r==3) Ton();
if(r==4) licht();
}

void nichts(){
 OneStep(false);
  delay(2);
}
void OneStep(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}

void beides() {
for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

   
    divider = melody[thisNote + 1];
    if (divider > 0) {
      
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
     
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }
}

for (int i = 0; i < 7; i++) {
    switch(i) {
      case 0: // red
        analogWrite(RED, 255);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 0);
        break;
      case 1: 
        analogWrite(RED, 255);
        analogWrite(GREEN, 127);
        analogWrite(BLUE, 0);
        break;
      case 2: 
        analogWrite(RED, 255);
        analogWrite(GREEN, 255);
        analogWrite(BLUE, 0);
        break;
      case 3: 
        analogWrite(RED, 0);
        analogWrite(GREEN, 255);
        analogWrite(BLUE, 0);
        break;
      case 4: 
        analogWrite(RED, 0);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 255);
        break;
      case 5: 
        analogWrite(RED, 75);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 130);
        break;
      case 6: 
        analogWrite(RED, 148);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 211);
        break;
         OneStep(false);
         delay(2);
}
}
}
void Ton() {
for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

   
    divider = melody[thisNote + 1];
    if (divider > 0) {
      
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
     
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

   
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    
    delay(noteDuration);
    
    
    noTone(buzzer);
  }
  OneStep(false);
  delay(2);
}

void licht() {
for (int i = 0; i < 7; i++) {
    switch(i) {
      case 0: // red
        analogWrite(RED, 255);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 0);
        break;
      case 1: 
        analogWrite(RED, 255);
        analogWrite(GREEN, 127);
        analogWrite(BLUE, 0);
        break;
      case 2: 
        analogWrite(RED, 255);
        analogWrite(GREEN, 255);
        analogWrite(BLUE, 0);
        break;
      case 3: 
        analogWrite(RED, 0);
        analogWrite(GREEN, 255);
        analogWrite(BLUE, 0);
        break;
      case 4: 
        analogWrite(RED, 0);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 255);
        break;
      case 5: 
        analogWrite(RED, 75);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 130);
        break;
      case 6: 
        analogWrite(RED, 148);
        analogWrite(GREEN, 0);
        analogWrite(BLUE, 211);
        break;
    }

    
    delay(1000);
  }
  OneStep(false);
  delay(2);
}
