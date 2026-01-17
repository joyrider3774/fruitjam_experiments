//FOR FRUITJAM

#include <pio_usb.h>
#include <tusb.h>
#include <Adafruit_TinyUSB.h>
#include <Adafruit_dvhstx.h>
#include "usbh_processor.h"

#if defined(ADAFRUIT_FEATHER_RP2350_HSTX)
DVHSTXPinout pinConfig = ADAFRUIT_FEATHER_RP2350_CFG;
#elif defined(ADAFRUIT_METRO_RP2350)
DVHSTXPinout pinConfig = ADAFRUIT_METRO_RP2350_CFG;
#elif defined(ARDUINO_ADAFRUIT_FRUITJAM_RP2350)
DVHSTXPinout pinConfig = ADAFRUIT_FRUIT_JAM_CFG;
#elif (defined(ARDUINO_RASPBERRY_PI_PICO_2) || defined(ARDUINO_RASPBERRY_PI_PICO_2W))
DVHSTXPinout pinConfig = ADAFRUIT_HSTXDVIBELL_CFG;
#else
// If your board definition has PIN_CKP and related defines,
// DVHSTX_PINOUT_DEFAULT is available
DVHSTXPinout pinConfig = DVHSTX_PINOUT_DEFAULT;
#endif

#define KEY_SPACE 0x2C
#define KEY_RIGHT 0x4F
#define KEY_LEFT  0x50
#define KEY_DOWN  0x51
#define KEY_UP    0x52

Adafruit_USBH_Host USBHost;

DVHSTX16 tft(pinConfig, DVHSTX_RESOLUTION_320x240, true);

static int16_t prevmousex = 0;
static int16_t prevmousey = 0;

volatile uint8_t lastkey = 0;
volatile bool lastpressed = false;

void KeyboardCallBack(uint8_t scancode, bool pressed)
{
  lastkey = scancode;
  lastpressed = pressed;
}

void setup1()
{
#ifdef PIN_5V_EN
  pinMode(PIN_5V_EN, OUTPUT);
  digitalWrite(PIN_5V_EN, PIN_5V_EN_STATE);
#endif

  pio_usb_configuration_t pio_cfg = PIO_USB_DEFAULT_CONFIG;
  pio_cfg.pin_dp = PIN_USB_HOST_DP;
  pio_cfg.tx_ch      = 9; //saw doom port doing this also
  USBHost.configure_pio_usb(1, &pio_cfg);
  USBHost.begin(1);
  delay(4000); //needs to be high enough increase if needed
}

void loop1()
{
  USBHost.task();
}


void setup() {
  Serial.begin(115200);
  if (!tft.begin()) { // Blink LED if failed
    Serial.printf("failed to setup display\n");
    pinMode(LED_BUILTIN, OUTPUT);
    for (;;)
    digitalWrite(LED_BUILTIN, (millis() / 500) & 1);
  }
  tft.setCursor(0,0);
  tft.fillScreen(tft.color565(255,255,255));
  setMouseRange(0,0, tft.width(), tft.height());
  setMouse(tft.width() >> 1, tft.height()>>1);
  setKeyDownUpCallBack(KeyboardCallBack);
  tft.setTextColor(tft.color565(0,0,0));
}



void loop() 
{
  if (keyPressed(KEY_SPACE))
  {
    tft.fillScreen(tft.color565(0,255,0));
    tft.setCursor(25,25);
    tft.setTextSize(5);
    tft.println("SPACE KEY");
    tft.setTextSize(1);
  }
  else if(mouseButtonPressed(0))
    tft.fillScreen(tft.color565(0,0,255));
  else if(mouseButtonPressed(1))
    tft.fillScreen(tft.color565(255,0,0));
  else
    tft.fillScreen(tft.color565(255,255,255)); 
  
  tft.setCursor(0,0); 
  char Text[40];
  if(lastkey != 0)
  {
    sprintf(Text, "Key %s was %s", getKeyName(lastkey),  lastpressed ? "pressed": "released");
    tft.println(Text);
  }
  else
  {
    tft.println("Press or Release a key");
  }
  

  int16_t mousex = getMouseX();
  int16_t mousey = getMouseY();
  sprintf(Text, "Mouse: %d,%d", mousex, mousey);
  tft.println(Text);

  tft.fillRect(mousex -2, mousey-2, 4, 4, tft.color565(255,0,255));

  if(keyPressed(KEY_DOWN))
    setMouse(getMouseX(), getMouseY() + 1);
  if(keyPressed(KEY_UP))
    setMouse(getMouseX(), getMouseY()- 1);
  if(keyPressed(KEY_LEFT))
    setMouse(getMouseX()-1, getMouseY());
  if(keyPressed(KEY_RIGHT))
    setMouse(getMouseX()+1, getMouseY());
  
  tft.swap();
}

