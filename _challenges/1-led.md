---
title: LED
description: This is the first challenge - learn some programming and create some Morse code! 
alt_v1: https://docs.google.com/presentation/d/1DZbnwOQN-aU16YOYuVppmZkEunN-LtYr8j3dcDj1nHI/pub

core_challenge: 1
requires_kit: board-only
language: C++
est_time: 15&mdash;45min
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

    You have two options: Arduino IDE is very simple&mdash;and therefore better for beginners and the very young, hence why we install it on our laptops&mdash;but we generally recommend Visual&nbsp;Studio&nbsp;Code.

    ##### Option 1: Arduino IDE

    {: .spoiler}
    1. Download Arduino IDE from [arduino.cc](https://www.arduino.cc/en/Main/Software),
        install and open it.
    2. Click **File&rarr;Preferences** (**Arduino&rarr;Preferences** on Mac), and paste 
        `http://arduino.esp8266.com/stable/package_esp8266com_index.json` into 
        **Additional Boards Manager URLs**.
    3. Click **Tools&rarr;Board&rarr;Boards Manager...**, 
        then click **Type&rarr;Contributed** followed by 
        **esp8266 by ESP8266 Community**. Click **Install**.
    4. [Download the required libraries]({{"/assets/releases/libraries.zip" | relative_url}}){: .download}
    5. Extract the libraries and copy the folders inside to your Arduino libraries folder (usually *Documents\Arduino\libraries*).

        In Windows 8.1, your default Documents folder may be in OneDrive.
        {: .requisite-warning .warning .compact}
        
        If using macOS, or your hedgehog is not recognised by Windows, [Download the CH341 driver](https://wiki.wemos.cc/downloads){: .download}. Support for CH340/CH341 is included in most versions of the Linux kernel, so there does not appear to be a driver for this platform.
        {: .requisite-warning .warning .compact}

    6. Click **Tools&rarr;Upload Speed** and choose **115200**.

    ##### Option 2: Visual Studio Code

    {: .spoiler data-spoiler-text="<em class="hidden-print">Click to show instructions</em>"}
    1. Download Visual Studio Code from [code.visualstudio.com](https://code.visualstudio.com), install and open it.
    2. Open the Extensions sidebar <i class="vscode-extensions"></i>.
    3. Search for and install the extension **PlatformIO IDE**.
    4. Wait for the panel that pops up at the bottom of the screen to ask you to restart VS Code, and do so.
    5. [Download the starter workspace]({{"/assets/releases/hedgehog-starter.zip" | relative_url}}){: .download} (You might need to click **Save** if you're using Edge or Firefox), and extract it somewhere (Windows: Open folder, right-click **hedgehog-starter** and click **Extract all...**; Mac: double-click it).
    6. In Visual Studio Code, click **File&rarr;Open Folder** and open the extracted starter (it's normally in Downloads).
    7. If you don't see a row of icons in the bottom-left corner after a few seconds, including a tick and upload icon <i class="arduino-upload"></i>, restart VS Code.
    8. From the Explorer sidebar (pages icon), open **src/main.cpp**.
    9. We also recommend changing a few settings to make Visual Studio Code easier to use for beginners:
    
        - If you don't like the color theme, click the settings cog at the bottom of the activity bar (next to the sidebar, with the big icons), click **Color Theme** and choose an option from the pop-up list.
        - In Settings (**File&rarr;Preferences&rarr;Settings**), Set **C_Cpp: Autocomplete** to **disabled**.
        - Right-click the top of the sidebar and choose **Hide Sidebar**.
        - Right-click the activity bar and choose **Hide Activity Bar**.
        - Nearly all notifications can be disabled by clicking _Don't Show Again_ when they pop up.
    
    10. Connect the WeMos board to your PC using the microUSB cable, **and skip to step 3**.
        
        If using macOS, or your hedgehog is not recognised when you come to upload your code, [Download the CH341 driver](https://wiki.wemos.cc/downloads){: .download}.
        {: .requisite-warning .warning .compact}

2.  #### Connect the board
    1. Connect the WeMos board to your PC using the microUSB cable.
    2. Click **Tools&rarr;Board&rarr;LOLIN(Wemos) D1 R2 & Mini**.

        The board may also be called **Wemos D1 R2 & Mini**.
        {: .requisite-warning .warning .compact}

    3. Click **Tools&rarr;Port&rarr;COM*x***, where ***x*** is any number greater than 1.

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

    ##### Troubleshooting

    {: .spoiler data-spoiler-text="<em class="hidden-print">Click to show</em>"}
    - If you see a long error in Arduino IDE about stuff being missing or undeclared, double check
      the board in the Tools menu and that **esp8266** is installed in
      **Boards Manager**.

    - If you see `espcomm_sync failed`, your computer and board are struggling
      to talk to each other - try a different USB port, restarting your
      computer or asking a helper, who may replace your board.

    - If you receive an error _Please specify 'upload_port' for environment or use global '--upload-port' option_, your hedgehog has not been recognised: try unplugging it
      and plugging it back in (using a different USB port if you can).

    - Visual Studio Code might get confused on some Windows laptops (like versions of the Lenovo Thinkpad X1), and auto-detect your Hedgehog on the wrong COM port. To fix this,
      open Device Manager and look for **USB-SERIAL CH340 (COM*x*)** under **Ports (COM & LPT)** (_x_ can be any number). Add a line to `platformio.ini` that reads
      `upload_port = COMx` (where _x_ is the number you saw).
      
    - If you see an error when you try to upload your code that reads "_You are not logged in. Please log in to PIO Account..._", double check you tapped the upload icon 
      <i class="arduino-upload"></i> and not the "_PlatformIO: Upload to remote device_" icon next to it.

5.  #### Morse Code
    Now you know how to change the speed of flashing of your LED, let's use that 
    to make some Morse code! Your challenge is to spell **SOS** using the LED. 
    
    Use the chart below for help. A dot is a short pulse of light, and a dash is 
    a long pulse. Don't forget to add an extra delay at the end of the word. 

    ![]({{"assets/media/morsecode.jpg" | relative_url}}){: .u-max-full-width}
