#include <SevenSegmentExtended.h>
#include <SevenSegmentTM1637.h>
#include "Simple_NTP.h"

int Brightness = 15;
bool Display24HourTime = false;

// ESP8266 Module connection pins
const byte CLK = D2;   // define CLK pin to LED (any digital pin)
const byte DIO = D3;   // define DIO pin to LED (any digital pin)

SevenSegmentExtended clock(CLK, DIO);   // Create clock object

//-----------------------------------------------------------------------------
// SETUP     SETUP     SETUP     SETUP     SETUP     SETUP     SETUP     SETUP
//-----------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  GetNTPTimeSetup();       // NTP setup to get Time from the internet
  clock.begin();           // LED TM1637 Display 
  clock.setBacklight(Brightness);  // LED brightness 1-100%
  Serial.println("Setup completed");
}

//-----------------------------------------------------------------------------
// LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP
//-----------------------------------------------------------------------------
void loop() {

  // DiagShowTime();  // use to show time on serial monitor once a second
  if (Display24HourTime)
   clock.printTime(hour(),minute(),true); //show 24 hour format
  else
   clock.printTime12(hourFormat12(),minute(),true); //show 12 hour format and blank leading zero 

//  { // 12 hour type display
//   if (hourFormat12() < 10 )
//     clock.printTime12(true,hourFormat12(),minute(),true); //show 12 hour format and blank leading zero 
//   else
//     clock.printTime12(false,hourFormat12(),minute(),true); //show 12 hour format and display leading 1
//  }
 delay(1000);   // wait 1 second to do again
}

