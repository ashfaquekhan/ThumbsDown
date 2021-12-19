#include "ESP_MICRO.h" //Include the micro library 
bool state=1;
void setup(){
  Serial.begin(9600); // Starting serial port for seeing details
  start("K.G.F - 2","assafkhan92786");  // EnAIt will connect to your wifi with given details
  pinMode(BUILTIN_LED, OUTPUT);
  delay(300);
  digitalWrite(BUILTIN_LED,state);
}
void loop(){
  waitUntilNewReq();
  if(getPath() == "//OPEN_LED")
  {
    state=0;
  }
  if(getPath() == "//CLOSE_LED")
  {
    state=1;
  }
  Serial.println(getPath());
  returnThisInt(state);
  digitalWrite(BUILTIN_LED,state);
}
