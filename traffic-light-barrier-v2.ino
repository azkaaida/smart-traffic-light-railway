#include <Servo.h>
//#include <HCSR04.h>
//#define MAX_DISTANCE 500

// Servo untuk 2 palang
Servo servo; // 1 pin untuk 2 servo (paralel)
int posisi;

// Buzzer 
int buzzerKA = 2;

// Ultrasonic
int echo1 = 8;
int trigger1 = 6;
int echo2 = 4;
int trigger2 = 3;

long durasi1, durasi2;
int jarak1, jarak2;
int batas = 10;

// Lampu lalu lintas
int abang1 = 7;
int kuning1 = 9;
int ijo1 = 10;

int abang2 = 11;
int kuning2 = 12;
int ijo2 = 13;

// Delay lampu lalu lintas
int dijo1 = 10000;
int dkuning1 = 2000;
int dabang1 = 10000;
int dijo2 = 10000;
int dkuning2 = 2000;
int dabang2 = 10000;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servo.attach(5);
//pinMode(5, OUTPUT);

pinMode(trigger1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(trigger2, OUTPUT);
pinMode(echo2, INPUT);

pinMode(abang1, OUTPUT);
pinMode(kuning1, OUTPUT);
pinMode(ijo1, OUTPUT);
pinMode(abang2, OUTPUT);
pinMode(kuning2, OUTPUT);
pinMode(ijo2, OUTPUT);

pinMode(buzzerKA, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly
normaly:  
  //Lampu siji ijo - Lampu loro abang
  digitalWrite(ijo1, HIGH);
  digitalWrite(kuning1, LOW);
  digitalWrite(abang1, LOW);
  digitalWrite(ijo2, LOW);
  digitalWrite(kuning2, LOW);
  digitalWrite(abang2, HIGH);
  delay(dijo1);

  //Lampu siji wes kuning - Lampu loro abang jekan santee
  digitalWrite(ijo1, LOW);
  digitalWrite(kuning1, HIGH);
  digitalWrite(abang1, LOW);
  digitalWrite(ijo2, LOW);
  digitalWrite(kuning2, LOW);
  digitalWrite(abang2, HIGH);
  delay(dkuning1);

  //Lampu siji wes abang - Lampu loro cakut kuning
  digitalWrite(ijo1, LOW);
  digitalWrite(kuning1, LOW);
  digitalWrite(abang1, HIGH);
  digitalWrite(ijo2, LOW);
  digitalWrite(kuning2, HIGH);
  digitalWrite(abang2, LOW);
  delay(dkuning2);

  //Lampu siji jek abang - Lampu loro ijooo yeaaah
  digitalWrite(ijo1, LOW);
  digitalWrite(kuning1, LOW);
  digitalWrite(abang1, HIGH);
  digitalWrite(ijo2, HIGH);
  digitalWrite(kuning2, LOW);
  digitalWrite(abang2, LOW);
  delay(dijo2);

  //Lampu siji jek abang santee - Lampu loro mulai kuning
  digitalWrite(ijo1, LOW);
  digitalWrite(kuning1, LOW);
  digitalWrite(abang1, HIGH);
  digitalWrite(ijo2, LOW);
  digitalWrite(kuning2, HIGH);
  digitalWrite(abang2, LOW);
  delay(dkuning2);

  //Lampu siji mulai kuning - Lampu loro abang
  digitalWrite(ijo1, LOW);
  digitalWrite(kuning1, HIGH);
  digitalWrite(abang1, LOW);
  digitalWrite(ijo2, LOW);
  digitalWrite(kuning2, LOW);
  digitalWrite(abang2, HIGH);
  delay(dkuning1);


// Baca sensor
  digitalWrite(trigger1, LOW);
  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger1, HIGH);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1, LOW);
  digitalWrite(trigger2, LOW);

  durasi1 = pulseIn(echo1, HIGH);
  jarak1 = durasi1*0.03483/2;
  
  durasi2 = pulseIn(echo2, HIGH);
  jarak2 = durasi2*0.03483/2;
  
  Serial.print("Distance1: ");
  Serial.println(jarak1);
  Serial.print("Distance2: ");
  Serial.println(jarak2);


// Kondisi kereta

  if (jarak1 <= batas || jarak2 <= batas)
  { 
    // Logika: Jalan yang menyebrangi rel -> Merah
    digitalWrite(ijo2, LOW);
    digitalWrite(kuning2, LOW);
    digitalWrite(abang2, HIGH);
    
    // Buzzer ON
    digitalWrite(buzzerKA, HIGH);   
    
    //palang_mudhun:
      servo.write(0);
      delay(100);
    
  }

  else
  {
    // Buzzer OFF
    digitalWrite(buzzerKA, LOW);

    // palang_munggah:
      servo.write(90);
      delay(15);
    
    goto normaly;
  }
}
