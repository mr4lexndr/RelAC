////////////////////////////////////////////////////////////
//                                                        //
//      RelAC: a HomeKit dual channel relay module        //
//       with live switch input based on HomeSpan         //
//    ----------------------------------------------      //
//                Made by mr4lexndr 2023                  //
//                 current hardware v1.0                  //
//                                                        //
////////////////////////////////////////////////////////////

/*
 * HARDWARE:
 * - ESP32-WROOM-32UE
 * - Panasonic ADW1203HLW relays 
 *    latching coil to minimise power consumption and thermal emmissions
 * 
 * PIN CONFIGURATION: 
 *  relay-1
 *    set coil    27
 *    reset coil  26
 *    
 *  relay-2
 *    set coil    33
 *    reset coil  32
 *    
 *  live inputs
 *    switch-1    16  
 *    switch-2    13
 * 
 */
 
#include "HomeSpan.h" 
#include "DEV_RELAY.h"          

void setup() {

 Serial.begin(115200);

 homeSpan.setStatusPin(2);    // onboard status LED pin
 homeSpan.setControlPin(0);   // pushbutton pin

 homeSpan.enableOTA();        // enable arduino OTA

 homeSpan.begin(Category::Switches,"RelAC by mr4lexndr","RelAC"); //CatID, Display Name, Hostname Base

 new SpanAccessory(); 
  
    new Service::AccessoryInformation();    
      new Characteristic::Name("Relay Module");    
      new Characteristic::Manufacturer("mr4lexndr"); 
      //new Characteristic::SerialNumber("SerialHere");  
      new Characteristic::Model("RelAC");   
      new Characteristic::FirmwareRevision("1.0");  
      new Characteristic::Identify();

      new Service::HAPProtocolInformation();          
      new Characteristic::Version("1.1.0");                                                       

      // dual channel version
      new DEV_RELAY(27,26,16);  //device1 PINS(on, off, live input)
      new DEV_RELAY(33,32,13);  //device2 PINS(on, off, live input)
      
      // single channel version
      // new DEV_RELAY(27,26,13);  //PINS on, off, input
      
} // end of setup()

void loop(){
  
  homeSpan.poll();
  
} // end of loop()
