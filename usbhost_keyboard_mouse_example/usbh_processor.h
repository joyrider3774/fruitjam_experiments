#ifndef USBH_PROCESSOR_H
#define USBH_PROCESSOR_H

#include "Adafruit_TinyUSB.h"

typedef void (*onKeyboardKeyDownUpCallback)(uint8_t scancode,  bool keydown); 

void setKeyDownUpCallBack(onKeyboardKeyDownUpCallback callback);
void setMouseRange(int16_t minx, int16_t miny, int16_t w, int16_t h);
int16_t getMouseX();
int16_t getMouseY();
bool mouseButtonPressed(uint8_t button);
bool keyPressed(uint8_t key);
void USBHidUpdate(Adafruit_USBH_Host *host) ;
const char* getKeyName(uint8_t key);
void setMouse(int16_t x, int16_t y);

#endif