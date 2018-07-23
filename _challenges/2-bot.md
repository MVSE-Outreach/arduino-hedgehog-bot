---
title: Bot
description: This is the second challenge - build your robot and get it moving! 
alt_v1: https://docs.google.com/presentation/d/1WIN4TMjElcPm9t5xDhwrXADAptzXfMISy4myXoclRKg/pub

requires_kit: all
language: C++
est_time: 10&mdash;20min
difficulty: Easy
completion: 
  - wiring
  - programming
  - dancing

header_img: /assets/media/hedgehog-bot-top.svg
header_bg: "#F7FCFB"
---

1.  #### Setup your computer
    If you've not installed the Arduino IDE and required libraries, complete *Setup your computer* [from the first challenge]({{"challenges/1-led" | relative_url}}).

1.  #### Build the body
    Follow the video below. Ask a helper if you're stuck or a body part is hard to click in to another part.
    <iframe width="800" height="415" class="video-iframe u-max-full-width" src="https://www.youtube.com/embed/TCppJ16i6oc" frameborder="0" allowfullscreen></iframe>

2.  #### Wiring the screen
    Plug 4 wires from the WeMos into the back of the screen. The screen should still be mounted on the body. *You don't need to use the exact wire colours.*

    ![VIN&rarr;+ GND&rarr;- D4&rarr;IN1 D3&rarr;IN2 D0&rarr;IN3 RX&rarr;IN4]({{"/assets/media/oledfritzing.png" | relative_url}}){: .u-max-full-width}

3.  #### Wiring the left motor
    Plug 6 wires from the WeMos into the left motor driver. If you look at the bot with the **screen facing you**, the driver is on the left side of the body. *You don't need to use the exact wire colours.*
    
    ![VIN&rarr;+ GND&rarr;- D4&rarr;IN1 D3&rarr;IN2 D0&rarr;IN3 RX&rarr;IN4]({{"/assets/media/lmotorfritzing.png" | relative_url}}){: .u-max-full-width}

3.  #### Wiring the right motor
    Plug 6 wires from the WeMos into the right motor driver. If you look at the bot with the **screen facing you**, the driver is on the right side of the body. *You don't need to use the exact wire colours.*
    
    ![VIN&rarr;+ GND&rarr;- D4&rarr;IN1 D3&rarr;IN2 D0&rarr;IN3 RX&rarr;IN4]({{"/assets/media/rmotorfritzing.png" | relative_url}}){: .u-max-full-width}

4.  #### Plugging things in
    Plug the motor cables into the drivers. The white connector should click in to the white socket on the driver. Do this for both motors.

    ![VIN&rarr;+ GND&rarr;- D4&rarr;IN1 D3&rarr;IN2 D0&rarr;IN3 RX&rarr;IN4]({{"/assets/media/motorwire.jpg" | relative_url}}){: .u-max-full-width}

5.  #### Code
    Now you've built your bot, it's time to test the screen and motors.

    Have a look at the code below. This code will:
    1. draw a smile face on the robot screen
    2. turn the robot motors right for a second
    3. stop the motors for a second
    4. repeat over and over!

    ```cpp
    #include "drawFace.h"
    #include "espDualStepper.h"

    void setup() {
        Draw.start(); // set up screen
        Motor.start(D8, D7, D6, D5, D4, D3, D0, RX); // set up motors
    }

    void loop() {
        Draw.smile(); // this draws a smile face on the Hedgehog's screen
        delay(1000);
        Motor.right(); // this makes the motors to turn right
        delay(1000);
        Motor.stop(); // this tells the motors to stop
        delay(1000);
    } 
    ```
    {: .ide}

    1. Copy the code above and paste into the Arduino IDE.
    2. Press the upload button <i class="arduino-upload"></i>. You'll see the 
        code compiling and uploading in the black box at the bottom. When it's 
        done you should see '*Done Uploading*' just above the black box.

    If the screen isn't displaying or the motors aren't moving ask a helper to check your wiring. 

7.  #### Dance!
    Now you've built your bot it's time to make it dance!

    Use the following commands inside the loop to make the bot dance. Don't forget delays!
    
    ```cpp
    Motor.forward();
    Motor.reverse();
    Motor.left();
    Motor.right();
    Motor.stop();

    Draw.smile();
    Draw.frown();
    Draw.wink();

    delay();
    ```
