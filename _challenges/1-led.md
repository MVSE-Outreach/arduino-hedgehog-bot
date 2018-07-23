---
title: LED
description: This is the first challenge - learn some programming and create some Morse code! 
alt_v1: https://docs.google.com/presentation/d/1DZbnwOQN-aU16YOYuVppmZkEunN-LtYr8j3dcDj1nHI/pub

requires_kit: board-only
language: C++
est_time: 10&mdash;20min
difficulty: Easy
completion: 
  - LEDs
  - loops
  - delays
  - Morse code

header_img: /assets/media/hedgehog-led-top.svg
header_bg: "#FCFDF6"
---

1.  #### Setup your computer
    1. Download Arduino IDE from [arduino.cc](https://www.arduino.cc/en/Main/Software),
        install and open it. 
    2. Click **File&rarr;Preferences**, and paste 
        `http://arduino.esp8266.com/stable/package_esp8266com_index.json` into 
        **Additional Boards Manager URLs**.
    3. Click **Tools&rarr;Board&rarr;Boards Manager...**, 
        then click **Type&rarr;Contributed** followed by 
        **esp8266 by ESP8266 Community**. Click **Install**.
    4. [Download the required libraries]({{"/assets/releases/libraries.zip" | relative_url}}){: .download}
    5. Extract the libraries and copy the folders inside to your Arduino libraries folder (on Windows, usually *Documents\Arduino\libraries*).

        In Windows 8.1, your default Documents folder may be in OneDrive.
        {: .requisite-warning .warning .compact}

2.  #### Connect the board
    1. Connect the WeMos board to your PC using the microUSB cable.
    2. Click **Tools&rarr;Board&rarr;Wemos D1 R2 & Mini**.
    2. Click **Tools&rarr;Port&rarr;COM*x***, where ***x*** is any number 
        greater than 1.

3.  #### LEDs and Loops
    A LED (Light Emitting Diode) is a little light which is built into your 
    WeMos. It's a great thing to use to try out some code. Before you start 
    coding, you need to know about comments, the setup and loop:
    ```c
    // this is a comment, started with a //
    // it is used to explain something in your code

    void setup() {
      // here, between the {} we're inside the setup
      // this happens first to set up things!
    }

    void loop() {
      // here, between the {} we're inside the loop
      // this happens after the setup
      // this then repeats over and over again forever!
    } 
    ```

4.  #### Blink Code
    The builtin LED is an Active LOW component meaning that setting it LOW 
    turns it on and setting it HIGH turns it off. Active HIGH components turn 
    on when set HIGH and turn off when set LOW.
    
    Have a look at the code below. This code will:
    1. turn off the LED for one second
    2. turn on the LED for one second
    3. repeat over and over!

    ```c 
    void setup() {
      pinMode(BUILTIN_LED, OUTPUT); // set up the LED
    }

    void loop() {
      digitalWrite(BUILTIN_LED, HIGH); // turn off LED
      delay(1000); // wait one second
      digitalWrite(BUILTIN_LED, LOW); // turn on LED
      delay(1000); // wait one second
    } 
    ```
    {: .ide}

    1. Copy the code above and paste into the Arduino IDE
    2. Press the upload button <i class="arduino-upload"></i>. You'll see the 
        code compiling and uploading in the black box at the bottom. When it's 
        done you should see '*Done Uploading*' just above the black box.
    3. You should see an LED flashing on and off once a second on the WeMos!
    4. Now try changing the size of the delays - what do you think will happen 
        if the delays are 2000 milliseconds instead of 1000? Upload the code to 
        see! 

5.  #### Morse Code
    Now you know how to change the speed of flashing of your LED, let's use that 
    to make some Morse code! Your challenge is to spell **SOS** using the LED. 
    
    Use the chart below for help. A dot is a short pulse of light, and a dash is 
    a long pulse. Don't forget to add an extra delay at the end of the word. 

    ![]({{"assets/media/morsecode.jpg" | relative_url}}){: .u-max-full-width}
