// this code gives your Hedgehog Bot wifi connectivity!

// this stuff helps the arduino understand the wifi chip:
#include "dualStepper.h"
#include "U8glib.h"
#include "drawFace.h"
#include "SoftwareSerial.h"
U8GLIB_SH1106_128X64 u8g1(U8G_I2C_OPT_NONE);
char inChar, inData[6] = {0, 0, 0, 0, 0, '\0'},
             buttonData[7] = {0, 0, 0, 0, 0, 0, '\0'};
int charIndex = 0, buttonPress = -1;
boolean copyChar = false;
SoftwareSerial ESP8266Serial(A0,
                             A1); // call to SoftwareESP8266Serial(rxPin, txPin)

// this tells the arduino how the motors are wired up:
int left1 = 9, left2 = 8, left3 = 7, left4 = 6, right1 = 5, right2 = 4,
    right3 = 3, right4 = 2;

// This tells Hedgehog Bot your wifi info
#define auth "e3c48d32244648998f908a5e9ecac514" // Blynk Auth Token
#define SSID "BT Wifi" // Your Wifi ID
#define PASS "password" // Your Wifi password
String cmd = "###>";

// this is the setup function:
void setup() {
  motor.Enable(right1, right2, right3, right4, left1, left2, left3, left4);
  motor.Stop();
  // Serial.begin(1200); //for debugging purposes
  ESP8266Serial.begin(1200);
  WifiConnect();
  ESP8266Serial.flush();
}

// this loop runs over and over again forever:
void loop() {
  blynkButtons();
  if (buttonPress == 0) {
    motor.Forward();
  }
  delay(100);
}

void blynkButtons() {
  charIndex = 0;
  buttonData[9] = 0, 0, 0, 0, 0, 0, 0, 0, 0;

  while (ESP8266Serial.available()) {
    inChar = (char)ESP8266Serial.read();
    if (copyChar == true) {
      buttonData[charIndex] = inChar;
      charIndex++;
      if (inChar == '\r') {
        copyChar = false;
        break;
      }
    }
    if (inChar == 'V') {
      buttonData[0] = inChar;
      charIndex++;
      copyChar = true;
    }
  }
  ESP8266Serial.flush();
  // Serial.println(buttonData);
  if ((buttonData[0] == 'V') && (buttonData[1] == '0') &&
      (buttonData[4] == '1')) {
    buttonPress = 0;
  } else if ((buttonData[0] == 'V') && (buttonData[1] == '1') &&
             (buttonData[4] == '1')) {
    buttonPress = 1;
  } else if ((buttonData[0] == 'V') && (buttonData[1] == '2') &&
             (buttonData[4] == '1')) {
    buttonPress = 2;
  } else if ((buttonData[0] == 'V') && (buttonData[1] == '3') &&
             (buttonData[4] == '1')) {
    buttonPress = 3;
  } else if ((buttonData[0] == 'V') && (buttonData[1] == '4') &&
             (buttonData[4] == '1')) {
    buttonPress = 4;
  } else if ((buttonData[0] == 'V') && (buttonData[1] == '5') &&
             (buttonData[4] == '1')) {
    buttonPress = 5;
  } else if ((buttonData[0] == 'V') && (buttonData[1] == '6') &&
             (buttonData[4] == '1')) {
    buttonPress = 6;
  } else if (buttonData[4] == '0') {
    motor.Stop();
  }
}

void WifiConnect(void) {
  cmd += auth;
  cmd += ">";
  cmd += SSID;
  cmd += ">";
  cmd += PASS;
  cmd += ">#&\n\r";
  draw.Wifi1();
  delay(10);
  draw.Wifi2();
  delay(10);
  draw.Wifi3();
  while (1) {
    if (ESP8266Serial.find("INITIALISING")) {
      break;
    }
  }
  screenText(0, 16, "connecting to:", SSID, "authentication:", auth);
  delay(1000);

  ESP8266Serial.print(cmd);
  digitalWrite(13, LOW);
  while (1) {
    if (ESP8266Serial.available()) {
      inChar = (char)ESP8266Serial.read();
      inData[0] = inData[1];
      inData[1] = inData[2];
      inData[2] = inData[3];
      inData[3] = inData[4];
      inData[4] = inChar;

      if ((inData[0] == 'R') && (inData[1] == 'e') && (inData[2] == 'a') &&
          (inData[3] == 'd') && (inData[4] == 'y')) {
        screenText(0, 16, "Connection", "established!", "", "");
        break;
      }
    }
  }
  delay(2000);
  draw.Smile();
}

void screenText(int x_pos, int y_pos, char text1[], char text2[], char text3[],
                char text4[]) {
  u8g1.firstPage();
  do {
    u8g1.setFont(u8g_font_unifont);
    u8g1.drawStr(x_pos, y_pos, text1);
    u8g1.drawStr(x_pos, y_pos + 16, text2);
    u8g1.drawStr(x_pos, y_pos + 32, text3);
    u8g1.drawStr(x_pos, y_pos + 48, text4);
  } while (u8g1.nextPage());
}
