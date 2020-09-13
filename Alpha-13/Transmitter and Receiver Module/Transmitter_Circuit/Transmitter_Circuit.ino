
#include<RH_ASK.h>
#include<SPI.h>

RH_ASK trans;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  trans.init()
}

void loop() {
  // put your main code here, to run repeatedly:
  char *message = "This is the transmitted Message";
  trans.send((uint8_t *)message, strlen(message));
  trans.waitPacketSent();
  exit(0);
}
