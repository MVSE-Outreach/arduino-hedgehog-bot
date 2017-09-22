//this stuff helps the arduino understand the screen and motor:
#include "dualStepper.h"
#include "U8glib.h"
#include "drawFace.h"
U8GLIB_SH1106_128X64 u8g1(U8G_I2C_OPT_NONE);

//this tells the arduino how the motors are wired up:
int left1 = 9, left2 = 8, left3 = 7, left4 = 6, right1 = 5, right2 = 4, right3 = 3, right4 = 2;

//this is the setup function:
void setup(){
  motor.Enable(right1, right2, right3, right4, left1, left2, left3, left4);
  motor.Stop();
}

//this loop runs over and over again forever:
void loop() {
  draw.Smile(); //this displays a smile on the Hedgehog Bot's screen
  delay(1000);
  motor.Right(); //this makes the motors to turn right
  delay(1000);
  motor.Stop(); //this tells the motors to stop
  delay(1000);
}
