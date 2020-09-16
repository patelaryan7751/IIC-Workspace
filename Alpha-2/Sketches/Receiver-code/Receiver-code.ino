
// import the virtualwire library
#include "VirtualWire.h" 

const int receive_pin=12;

// create a structure to hold data from the transmitter
// we are using a structure because the data is transmitted from the transmittor in the struct format

struct data
{
float temperature=0.0;
float humidity=0.0;
}d1; // object of the structure data i.e 'd1'


void setup()
{
  Serial.begin(9600); // start the serial monitor
  vw_set_rx_pin(receive_pin);
  vw_setup(2000); // bits per sec
  vw_rx_start();
}


void loop()
{
  // create a array to get the incoming data 
  uint8_t info[sizeof(d1)]; 
  uint8_t infolen=sizeof(d1);
  if(vw_have_message())
  {
    vw_get_message(info,&infolen);
    memcpy(&d1, &info, infolen); // copy the data to the struct object
    Serial.print("The Temperature is: ");
    Serial.println(d1.temperature);
    delay(100); 
    Serial.print("The Humidity is: ");
    Serial.println(d1.humidity);
    delay(200);
  }
  else{
    Serial.println("Error: Did't receive any data");
  }
  delay(50);
}
