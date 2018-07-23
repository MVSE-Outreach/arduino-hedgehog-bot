---
title: Wifi
description: This is the third challenge - time to control your robot wirelessly!
alt_v1: https://docs.google.com/presentation/d/1vFUuMN42MDI-51wy2UWQYLuFqFkslmOjGgieC3hui0A/pub

requires_workshop: Bot
language: C++
est_time: 10&mdash;20min
difficulty: Easy
completion: 
  - if statements
  - networking

header_img: /assets/media/hedgehog-wifi-top.svg
header_bg: "#FEF6FA"
---

1.  #### If statements
    For this Challenge, you need to learn about **if** statements.
    An if statement is saying "**if** this condition, then do this". For example:
    
    ```cpp
    if (x = 1) {
      Draw.smile(); // if x is 1 then draw a smile face on the screen
    } 
    ```

    You can also do **else if** statements.
    It's like saying "**else if** this condition, then do this."
    You write them following on from if statements. Here's an example:

    ```cpp
    if (x = 1) {
      Draw.smile(); // if x is 1 then draw a smile face on the screen
    }

    else if (x = 2) {
      Draw.wink(); // else if x is 2 then draw a wink face on the screen
    }

    else if (x = 3) {
      Draw.frown(); // else if x is 4 then draw a frown face on the screen
    }
    ```

2.  #### Creating a Wi-Fi remote
    You'll be using your phone or computer to remote control your robot over wifi!

    You'll be clicking different buttons to tell the robot what to do.

    In the code, you'l need to create else if statements to tell the robot what to do for the different buttons you press.

    Here's an example for turning the motor right:

    ```cpp
    else if (contains(webPage, "right")) {
      Motor.right();
    } 
    ```

3.  #### The code
    Below is the code for wifi enabling hedgehog bot. Copy and paste it into Arduino IDE. 

    ```cpp
    #include "drawFace.h"
    #include "espDualStepper.h"
    #include "ESP8266WiFi.h"
    #include "WebServer.h"
    #include "StringUtils.h"

    char wifiname[] = "wifiname"; // ***Type in the WiFi name in the quotes***
    char password[] = "password"; // ***Type in the Wifi password in the quotes***
    char ipString[24];

    WiFiServer Server(80);

    void setup() {
      Motor.start(D8, D7, D6, D5, D4, D3, D0, RX); // set up motors
      Draw.start(); // set up screen
      Draw.print("Connecting to ");
      Draw.println(wifiname);
      WiFi.begin(wifiname, password); // begin connecting to wifi
      
      while(WiFi.status() != WL_CONNECTED) { // != means not equal to.
        delay(500); // so this means while the wifi is not connected
        Draw.print("."); // print a "." to the screen
      }
      
      Server.begin(); // make the bot into a server so it can be controlled
      IPAddress myIp = WiFi.localIP();
      sprintf(ipString, "%d.%d.%d.%d", myIp[0], myIp[1], myIp[2], myIp[3]);
      Draw.println("IP:");
      Draw.print(ipString);
    }

    void loop() {
      WiFiClient client = Server.available();
      if(!client) {
        return;
      }
      while(!client.available()) {
        delay(1);
      }
      String webPage = client.readStringUntil('\r');
      client.flush();
      
      if (contains(webPage, "smile")) {
        Draw.smile(); // if you click the smile button, draw a smile on screen
      }
      
      // ***insert your else if statements here!***
      
      client.print(getWebPageHtml());
      client.flush();
      delay(1);
    } 
    ```
    {: .ide}

4.  #### Testing the Wi-Fi
    1.  Change the Wi-Fi name and password near the top of the code in the quotes to the one given to you by a helper.
    2.  Press the upload button <i class="arduino-upload"></i>. You'll see the code compiling and uploading in the black box at the bottom. When it's done you should see '*Done Uploading*' just above the black box.

    3.  You should see the screen saying *Connecting to Wi-Fi*! Wait for it to connect. 
    
        If it doesn't connect, check you've got the Wi-Fi name and password right and ask a helper. If you're at home, you'll need the SSID and passphrase for your home network; this is often found on a sticker on your Wi-Fi router.
        {: .requisite-warning .warning .compact}

5.  #### Remote control
    Once the robot is connected to the wifi it will say something like "IP:192.168.1.123" 
    1. Connect a Wi-Fi enabled device&mdash;such as a smartphone or laptop&mdash;to the same Wi-Fi network that you connected Hedgehog Bot to.
    2. Open a web browser on that device, such as *Firefox* or *Chrome*.
    3. Type in the IP address on your Hedgehog Bot's screen (such as 192.168.1.123) into the address box (which is normally at the top), and press <kbd>Enter</kbd>.

    If all has gone well, a remote control will pop up.

    Only the smile button should work. If you click it, a smile should show on the screen of your bot!

6.  #### Fixing the remote
    Now it's time to program the other remote control buttons! Back to the code. In the loop, create else if statements for all these commands: 

    ```cpp
    Motor.forward();
    Motor.reverse();
    Motor.left();
    Motor.right();
    Motor.stop();

    Draw.smile();
    Draw.frown();
    Draw.wink();
    ```

    Here's an example for drawing a frown on the screen:

    ```cpp
    else if (contains(webPage, "frown")) {
      Draw.frown();
    } 
    ```

    Upload the code and test out the remote. Have you managed to get all the buttons to work? Don't forget the stop button, otherwise your motors will move forever! 