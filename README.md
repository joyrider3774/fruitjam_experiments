# fruitjam_experiments
experiments / test code i used for [adafruit fruitjam](https://www.adafruit.com/product/6200)

## usbhost_keyboard_mouse_joypad_example
example on how to parse usb hid keyboard, joyopad and mouse using tiny usb's host mode and displaying the output to the screen. 
You can control the mouse and see a mouse curosr, show last key pressed or released as well as the mouse coordinates. 
The system for the mouse can work with any screen size, you can even use it on a part of the screen the mouse will not exceeed the ranges you specify.
for joypad's its best that you buy the snes controller from adafruit so it works with that. I could not test it with it but i did test with my ps1 controller.
The code will only work for generic input controllers and not xinput (xbox) or playstation controllers or switch controllers at least mine did not get detected.
