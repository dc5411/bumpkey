#include <Keyboard.h>
#include <SoftwareSerial.h> 
                             
int estado=0;

void setup() {

  Serial1.begin(38400); 
  Serial.begin(38400); 
  Keyboard.begin();
}

void loop() {
 if(Serial1.available()>0){
 estado = Serial1.read();
 }
 
  if (estado =='1'){
  Keyboard.begin();
  delay(500);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  Keyboard.write(KEY_RETURN);     
  delay(500);
  Keyboard.println("shutdown -t 0 -f -s");
  delay(50);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
  estado=0;
  } 

}
