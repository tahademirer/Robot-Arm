//author @demirer
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <EEPROM.h>

Servo servo1; //taban
Servo servo2; //sağ
Servo servo3; // sol
Servo servo4; //kıskaç

char auth[] = "39504203aba941328018c642e93621d9";
char ssid[] = "TurkTelekom_TDDAB";
char pass[] = "f3YN20vu";
int program1[10][4]; // 10 Adımlık Program
int program2[15]; // 15 Adımlık program
int program3[20]; // 20 adımlık daha uzun program

//tek boyutlu array ile deniyorum
int servo1PosSave[]={1,1,1,1,1,1,1,1};
int servo2PosSave[]={1,1,1,1,1,1,1,1};
int servo3PosSave[]={1,1,1,1,1,1,1,1};
int servo4PosSave[]={1,1,1,1,1,1,1,1};
// programlar uzunluk seviyelerine göre seçilebilir

const int button1 = D1;
const int button2 = D2;
int button1Pressed = 0;
boolean button2Pressed = false;

const int interruptButton = D0;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  servo1.attach(15); // NodeMCU D8 pin
  servo2.attach(14); // D5 
  servo3.attach(12); // D6
  servo4.attach(13); // D7
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(interruptButton, INPUT);
 }
  
void loop()
{
  
  // program kaydetme tuşu v5
  // program çalıştırma tuşu v6
  // programı silme tuşu v7
  
  Blynk.run();
  
  //interrupt ve timer kısmı 
  if(interruptButton == HIGH){
    ESP.deepSleep(5000);
  }
  //program kaydetme
  /*if(BLYNK_READ(V5)==true){
    for(int i = 0; i<=program1.length; i++){
        
         program1[i][0]= servo1.position();
         program1[i][1]= servo2.position();
         program1[i][2]= servo3.position();
         program1[i][3]= servo4.position(); 
        
    }
    
    EEPROM.put(0,program1);
  }

  //programı çalıştır
  if(BLYNK_READ(V6)==true){
    EEPROM.get(0, program1);
    for(int i = 0; i<program1.length; i++){
      servo1.write(program1[i][0];
      servo2.write(program1[i][1];
      servo3.write(program1[i][2];
      servo4.write(program1[i][3];
    }
    // şimdilik tek program çalıştırıyor.
    */
    //ikinci yaklaşım
    
  if(digitalRead(button1) == HIGH){
    button1Pressed++;
    switch(button1Pressed){
      case 1:
        servo1PosSave[0] = servo1.read();
        servo2PosSave[0] = servo2.read();
        servo3PosSave[0] = servo3.read();
        servo4PosSave[0] = servo4.read();
        Serial.println("Position #1 Saved");
     
        delay(1500);
       break;
       case 2:
        servo1PosSave[1] = servo1.read();
        servo2PosSave[1] = servo2.read();
        servo3PosSave[1] = servo3.read();
        servo4PosSave[1] = servo4.read();
        Serial.println("Position #2 Saved");
       
        delay(1500);
       break;
       case 3:
        servo1PosSave[2] = servo1.read();
        servo2PosSave[2] = servo2.read();
        servo3PosSave[2] = servo3.read();
        servo4PosSave[2] = servo4.read();
        Serial.println("Position #3 Saved");
       
        delay(1500);
       break;
       case 4:
        servo1PosSave[3] = servo1.read();
        servo2PosSave[3] = servo2.read();
        servo3PosSave[3] = servo3.read();
        servo4PosSave[3] = servo4.read();
        Serial.println("Position #4 Saved");
          
        
        delay(1500);
       break;
       case 5:
        servo1PosSave[4] = servo1.read();
        servo2PosSave[4] = servo2.read();
        servo3PosSave[4] = servo3.read();
        servo4PosSave[4] = servo4.read();
        Serial.println("Position #5 Saved");
       
        delay(1500);
       break;
       case 6:
        servo1PosSave[5] = servo1.read();
        servo2PosSave[5] = servo2.read();
        servo3PosSave[5] = servo3.read();
        servo4PosSave[5] = servo4.read();
        Serial.println("Position #6 Saved");
        
        delay(1500);
       break;
       case 7:
        servo1PosSave[6] = servo1.read();
        servo2PosSave[6] = servo2.read();
        servo3PosSave[6] = servo3.read();
        servo4PosSave[6] = servo4.read();
        Serial.println("Position #7 Saved");
        
        delay(1500);
       break;
       case 8:
        servo1PosSave[7] = servo1.read();
        servo2PosSave[7] = servo2.read();
        servo3PosSave[7] = servo3.read();
        servo4PosSave[7] = servo4.read();
        Serial.println("Position #8 Saved");
        
        delay(1500);
       break;
       
    }
  }
  //buton 2'ye basılınca programı çalıştır.
  if(digitalRead(button2) == HIGH){
    button2Pressed = true;
  }
  
  if(button2Pressed){
    for(int i=0; i<8; i++){
      servo1.write(servo1PosSave[i]);
      servo2.write(servo2PosSave[i]);
      servo3.write(servo3PosSave[i]);
      servo4.write(servo4PosSave[i]);
      
      delay(2000);
    }
  }
  delay(100);

  //PROGRAMI EEPROM ÜZERİNE KAYDEDİYORUZ
//  int a = servo2PosSave.length+servo1PosSave.length+servo3PosSave;
  
  EEPROM.put(0, servo1PosSave);
  EEPROM.put(8, servo2PosSave);
  EEPROM.put(16, servo3PosSave);
  EEPROM.put(24,servo4PosSave);

  //EEPROM içinden oku
  eepromRead();
}
  
  
void eepromRead(){
  for(int i = 0; i<32; i++){
    Serial.println(EEPROM.read(i));
      
  }
}
BLYNK_WRITE(V1) // TABAN
{
   servo1.write(param.asInt());
}

BLYNK_WRITE(V2) // SAĞ
{
  servo2.write(param.asInt());
}
BLYNK_WRITE(V3) // SOL
{
  servo3.write(param.asInt());
}
BLYNK_WRITE(V4) // KISKAÇ
{
  servo4.write(param.asInt());
}
