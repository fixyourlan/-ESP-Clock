#include <NtpClientLib.h>
#include <ESP8266WiFi.h>          
#include <DNSServer.h>            
#include <ESP8266WebServer.h>     
#include <WiFiManager.h>        
#include <TimeLib.h>

// usable NTPServer List "us.pool.ntp.org" "time.nist.gov" "pool.ntp.org"
String NTPServer = "us.pool.ntp.org";
int TimeZone = -6;
bool DST = true;


void DiagShowTime(){
  // show NTP Time and Date on serial monitor
  Serial.print(hourFormat12());
  Serial.print(":");
  Serial.print(minute());
  Serial.print("  ");
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
  Serial.print("/");
  Serial.println(year());
}
void GetNTPTimeSetup()
{
  Serial.begin(115200);
  Serial.println("WiFi setup...");
  WiFiManager wifiManager;               // wifi configuration wizard
  Serial.println("WiFi Connecting...");
  wifiManager.autoConnect();             // Connects to Router/Access Point 
  NTP.begin(NTPServer,TimeZone,DST);     // get time from NTP server pool
  NTP.setInterval(55);                   // update time from NTP every 55 seconds
  DiagShowTime();                        //Display the setup time on serial monitor
//  Serial.println(NTP.getTimeDateString());
//  Serial.println(NTP.getUptimeString());
}
