#include<RH_ASK.h>
#include<SPI.h>

RH_ASK recvr;

void setup() {
  // put your setup code here, to run once:
  recvr.init();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t message[100];
  uint8_t messagelgt = sizeof(message);
  if(recvr.recv(message,&messagelgt)) {
  Serial.print("The Received message is: ");
  Serial.println((char*)message);
  }
  exit(0);
}
