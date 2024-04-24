// This is the first attempt to write the wheelie program 3/1/24
// 

#define MODE_SELECTOR I0_12
#define IS_FRONT_LEG_DOWN I0_11
#define IS_REAR_LEG_DOWN I0_10
#define DRIVE_FRONT_LEG_DOWN Q0_0
#define DRIVE_FRONT_LEG_UP Q0_1
#define DRIVE_REAR_LEG_DOWN Q0_2
#define DRIVE_REAR_LEG_UP Q0_3
#define MODE_RELAY A0_5

bool scooter;
bool chair;
bool rearLegDown;
bool frontLegDown;

// Setup function
void setup()
{
  // Set the speed of the serial port
  Serial.begin(9600UL);

 // pinMode(MODE_SELECTOR, INPUT);
 // pinMode(MODE_RELAY, OUTPUT);
  

}

// Loop function
void loop() {
  //check the chair/scooter switch
  chair = digitalRead(MODE_SELECTOR);
  if (chair) {
    Serial.println("Im a chair");
  
    //check the position of the legs
    frontLegDown = digitalRead(IS_FRONT_LEG_DOWN);
    rearLegDown  = digitalRead(IS_REAR_LEG_DOWN);
      if (frontLegDown and rearLegDown) {
      //ensure all leg drives are off...
      digitalWrite(DRIVE_FRONT_LEG_DOWN, 0);
      digitalWrite(DRIVE_FRONT_LEG_UP, 0);
      digitalWrite(DRIVE_REAR_LEG_DOWN, 0);
      digitalWrite(DRIVE_REAR_LEG_UP, 0);
      // ...and switch off balance mode -- 
      // note: sending 5V (=128) to the relay de-activates it
      // and so the normally closed contacts close
      analogWrite(MODE_RELAY, 128);
      }
      else{
      // we're here because one or both of the legs are up
      //so let's check the front one first...
      frontLegDown = digitalRead(IS_FRONT_LEG_DOWN);
      //... and switch it off if it is down
        if (frontLegDown) {
        digitalWrite(DRIVE_FRONT_LEG_DOWN, 0);
        digitalWrite(DRIVE_FRONT_LEG_UP, 0);  
        }
        // and if it is not yet down turn on the down drive
        else {  
        digitalWrite(DRIVE_FRONT_LEG_UP, 0); 
        digitalWrite(DRIVE_FRONT_LEG_DOWN, 1);
        }
        // Now check the rear one...
        rearLegDown = digitalRead(IS_REAR_LEG_DOWN);
        //...and switch it off if it is down
          if (rearLegDown) {
          digitalWrite(DRIVE_REAR_LEG_DOWN, 0);
          digitalWrite(DRIVE_REAR_LEG_UP, 0);   
          }
          //and if it is not yet down turn on the down drive
          else{
          digitalWrite(DRIVE_REAR_LEG_UP, 0); 
          digitalWrite(DRIVE_REAR_LEG_DOWN, 1);
          }
       
      }
    
  }
  // arrived here because the mode switch is set to scooter 
  else 
  {
    Serial.println("Im a scooter");
    // raise both legs... 
    digitalWrite(DRIVE_FRONT_LEG_DOWN, 0); 
    digitalWrite(DRIVE_FRONT_LEG_UP, 1);
    digitalWrite(DRIVE_REAR_LEG_DOWN, 0); 
    digitalWrite(DRIVE_REAR_LEG_UP, 1);
    //...and switch on balance mode(scooter mode)
    // note: sending 0V to the relay activates it
    // and so the normally closed contacts open
    analogWrite(MODE_RELAY, 0);
  }
}
