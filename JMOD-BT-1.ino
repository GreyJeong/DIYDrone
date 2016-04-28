#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3);    // RX : Digital Pin2, TX : Digital Pin3

void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeat
  if(bluetooth.available())
    bluetooth.write("hello\n");
}
