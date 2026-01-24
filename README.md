# fruitjam_experiments
experiments / test code i used for [adafruit fruitjam](https://www.adafruit.com/product/6200)

## usbhost_keyboard_mouse_joypad_example
example on how to parse usb hid keyboard, joyopad and mouse using tiny usb's host mode and displaying the output to the screen. 
You can control the mouse and see a mouse curosr, show last key pressed or released as well as the mouse coordinates. 
The system for the mouse can work with any screen size, you can even use it on a part of the screen the mouse will not exceeed the ranges you specify.
for joypad's its best that you buy the snes controller from adafruit so it works with that.
The code will only work for generic input controllers and not xinput (xbox) or playstation controllers or switch controllers at least mine did not get detected.
I based the code on the doom port for adafruit fruitjam as well as the usbhost example from adafruit themselves
Adafruit's snes controller bug has been fixed now and (re)tested by Lord Rybec from adafruit discord, Thanks for that.
The following libraries are required for this example to compile:
- **Adafruit_dvhstx**: for video output
- **Adafruit_TinyUSB**: for usbhost mode for keyboard, joypad and mouse input
- **Adafruit_TLV320DAC3100**: for I2S sound output
- **PICO PIO USB:** for usbhost stuff

## i2stones_example
i2stones is a library / set of functions to play multiple tones, potentially played at the same time using i2s and Adafruit_TLV320DAC3100. 
I mainly needed this for the port of the crisp game lib portable. The example plays some sound effects and little musical pieces. The code
was largely created with the help of claude.ai and seems to work fine.
The following libraries are required for this example to compile:
- **Adafruit_TLV320DAC3100**: The driver for the DAC used in the fruitjam
