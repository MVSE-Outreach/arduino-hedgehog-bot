# Laptop setup for the Hedgehog Bot workshop

These instructions will show you how to set up a laptop ready to be used for
the hedgehog bot workshop.

* [ ] Install the [Arduino IDE](https://www.arduino.cc/en/main/software)
* [ ] Install the [ESP8266 Arduino core](https://github.com/esp8266/Arduino)
  * Open the Arduino IDE
  * Navigate to *File > Preferences* (`<Ctrl-,>` to quickly launch it)
  * Paste `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
    into the *Additional Board Manager URLs* field.
  * Open *Tools > Board > Boards Manager*, search for `esp8266`, select the latest version and click *Install*
* [ ] Verify Wemos connectivity
  * Open the Arduino IDE
  * Check for any listings under *Tools > Port*, take note of them
  * Plug in a Wemos
  * There should now be an additional listing under *Tools > Port* representing the Wemos
  * If there isn't a listing, then install the [CH340
    Drivers](http://www.nerdkits.com/usb-serial/ch341.php) and try again, it
    should show up after a driver install.
* [ ] Verify programming support
  * Open the Arduino IDE
  * Open *File > Examples > ESP8266 > Blink*
  * Click the upload button (right of the tick button)
  * Verify that the wemos LED has started blinking and the program has successfully uploaded
