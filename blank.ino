// This code uses the WiFiNINA library to connect to a WiFi network,
// the ThingSpeak library to send data to ThingSpeak, and the DHT library
// to read temperature and humidity data from a DHT sensor.

#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include "DHT.h"

//To define the WiFi network and ThingSpeak credentials.
char SSID[] = "Poco Phone";         // WiFi network name
char PASW[] = "1234567888";     // WiFi password
unsigned long channelId = 2250433;   // ThingSpeak channel ID
const char *APIkey = "CT08EOYZSSYSNSN7"; // ThingSpeak API key

//To create a WiFiClient object.
WiFiClient clients;

//To create a DHT object.
DHT dht(2, DHT22);

void setup() {
  //To initialize the serial port.
  Serial.begin(9600);

  //To initialize the DHT sensor.
  dht.begin();

  //Connect to the WiFi network.
  while (WiFi.status() != WL_CONNECTED) {
    //To print a message to the serial port indicating that the WiFi is not connected.
    Serial.print("Connecting to WiFi: ");
    Serial.println(SSID);

    //to connect to the WiFi network.
    WiFi.begin(SSID, PASW);

    //Wait for 1 second before retrying.
    delay(1000);
  }

  //To Print a message to the serial port indicating that the WiFi is connected.
  Serial.println("WiFi Connected Succesfully");

  //To initialize the ThingSpeak library.
  ThingSpeak.begin(clients);
}