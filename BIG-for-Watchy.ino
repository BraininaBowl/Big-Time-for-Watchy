#include <Watchy.h> //include the Watchy library
#include "Vollkorn_Black48pt7b.h"
        

class WatchFace : public Watchy { //inherit and extend Watchy class
  public:
    void drawWatchFace() { //override this method to customize how the watch face looks
      
      int16_t  x1, y1;
      uint16_t w, h;
      String textstring;
      
      //drawbg
      display.fillScreen(GxEPD_BLACK);
      
      display.setTextColor(GxEPD_WHITE);
      display.setTextWrap(false);

      //draw time
      display.setFont(&Vollkorn_Black48pt7b);

      textstring = currentTime.Hour;
      textstring += ":";
      if (currentTime.Minute < 10){
        textstring += "0";
      }
      textstring += currentTime.Minute;
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(100-w/2, 90+h/2);
      display.print(textstring);

      // draw battery
      float batt = (getBatteryVoltage()-3.3)/0.9;
      if (batt > 0) {
       display.fillRect(0,198,200*batt,2,GxEPD_WHITE);
      }                 
    }
};

WatchFace m; //instantiate your watchface

void setup() {
  m.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
