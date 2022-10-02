// Photo Frame Controller by Ben Considine
// Based on GxEPD2_HelloWorld.ino by Jean-Marc Zingg

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <GFX.h>

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// select the display class and display driver class in the following file (new style):
// #include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
// #include "GxEPD2_display_selection.h"
// #include "GxEPD2_display_selection_added.h"

// alternately you can copy the constructor from GxEPD2_display_selection.h or GxEPD2_display_selection_added.h to here

// constructor and pin-out for it78_1872x1404 high-res EPD - using Adafruit HUZZAH32
GxEPD2_BW < GxEPD2_it78_1872x1404, GxEPD2_it78_1872x1404::HEIGHT / 8 > display(GxEPD2_it78_1872x1404(/*CS=5*/ 12, /*DC=*/ 18, /*RST=*/ 16, /*BUSY=*/ 17));


const char test_message[] = "This is a test!";


void setup()
{
  display.init(115200);
  helloWorld();
  // printMsg(test_message);
  display.hibernate();
}

const char HelloWorld[] = "Hello World!";
const char dot[] = ".";

void helloWorld()
{
  display.setRotation(2);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(HelloWorld);
  }
  while (display.nextPage());
}

// void printPaddingBox(int16_t x, int16_t y, uint16_t bw, uint16_t bh, uint16_t pad)
// {

// }



void printMsg(const char* message)
{
  uint16_t padding = 20;
  display.setRotation(2);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_WHITE);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(message, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setPartialWindow(x - padding, y - padding, tbw + 2 * padding, tbh  + 2 * padding);
  display.firstPage();
  do
  {
    // print padding text box
    // for (int i = 0; i < tbw + 2 * padding; i++){
    //   for (int j = 0; j < tbh + 2 * padding; j++){
    //     // display.setCursor(x + i - padding, y + j - padding);
    //     // display.print(dot);
    //     display.fillScreen(GxEPD_WHITE);
    //   }
    // }
    display.fillScreen(GxEPD_WHITE);
  }
  while(display.nextPage());
  display.setTextColor(GxEPD_BLACK);
  display.setPartialWindow(x - padding, y - padding, tbw + 2 * padding, tbh  + 2 * padding);
  display.firstPage();
  do
  {
    // print message
    display.setCursor(x, y + padding / 2);
    display.print(message);
  }
  while(display.nextPage());

}

void loop() {
};
