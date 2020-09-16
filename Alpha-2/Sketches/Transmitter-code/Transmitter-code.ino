
// importing the library 
#include "VirtualWire.h" 
#include "DHT.h"

#define DHTPIN 4  // data receive pin

#define DHTTYPE DHT22 // type of sensor used

const int led_pin = 13; 
const int transmit_pin = 12; // pin to transmit data

struct package
{
  float temperature ;
  float humidity ;
}data; // object of struct package

DHT dht(DHTPIN, DHTTYPE); // instance of the DHT class to address the DHT sensor

void setup()
{
    // Initialise the pins and ports 
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000);       // Bits per sec
    pinMode(led_pin, OUTPUT);
}



void loop()
{
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  readSensor_data();
  vw_send((uint8_t *)&data, sizeof(data));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(3000);
}

void readSensor_data()
{
 dht.begin();
 delay(1500);
 data.humidity = dht.readHumidity();
 data.temperature = dht.readTemperature();
}
