#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <SimpleTimer.h>
#include <dht11.h>
dht11 DHT11;  // initialize the object 
SimpleTimer timer;

char auth[] = "xxxxxxxxxxxxxxx";   // your auth token here

void setup()
{
  DHT11.attach(2);                   // attach sensor to digital pin 2 of arduino
  Serial.begin(9600);               // start serial communication
  Blynk.begin(auth);                // connecting to blynk
  timer.setInterval(1000, sendUptime);
}

void sendUptime()
{
  Blynk.virtualWrite(1, DHT11.temperature);     // Virtual pin 1 stores the temp value
  Blynk.virtualWrite(2, DHT11.humidity);        // virtual pin 2 stores the humidity value
  
}

void loop()
{
  Blynk.run();                                 
  timer.run();
  int chk = DHT11.read();
}
