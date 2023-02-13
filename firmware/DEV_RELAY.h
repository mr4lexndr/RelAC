////////////////////////////////////
//    DEVICE-SPECIFIC SERVICES    //
////////////////////////////////////

// LATCHING RELAY WITH LIVE SWITCH INPUT
//////////////////////////////////////////

struct DEV_RELAY : Service::LightBulb {       // ON/OFF Bulb, could be changed to "Switch" for a different tile in Home app 

  int onPin;                                  // on coil pin
  int offPin;                                 // off coil pin
  int inPin;                                  // switch input pin
  boolean lastState;                          // last state of input
  SpanCharacteristic *power;                  // reference to the On Characteristic
  
  DEV_RELAY(int onPin, int offPin, int inPin) : Service::LightBulb(){    // constructor() method

    power=new Characteristic::On();           
    this->onPin=onPin;
    this->offPin=offPin; 
    this->inPin=inPin;
    this->lastState=lastState;
                                 
    pinMode(onPin,OUTPUT);  
    pinMode(offPin,OUTPUT); 
    pinMode(inPin,INPUT);                      
    
  } // end constructor

  boolean update(){                           // update() method
    if(power->getNewVal())
    turnON();
    else
    turnOFF();      
   
    return(true);                             // return true
    
  } // update

  void turnON(){
    // generate short pulse to set the latching coil
    digitalWrite(onPin, HIGH);
    delay(100);
    digitalWrite(onPin, LOW);
  } // turnON

  void turnOFF(){
    // generate short pulse to set the reset coil
    digitalWrite(offPin, HIGH);
    delay(100);
    digitalWrite(offPin, LOW);
  } // turnOFF

  void loop(){
    // check if the state of the live input changed since last iteration
    if(digitalRead(inPin)!=lastState){
      if(power->getVal()){
        turnOFF();
        power->setVal(0);
      }
      else{
        turnON(); 
        power->setVal(1);
      }
    }
    
    lastState = digitalRead(inPin);
  } // loop

};   
//////////////////////////////////
