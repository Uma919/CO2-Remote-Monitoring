#include <MHZ19_uart.h>
#include <Ticker.h>
#include <WiFi.h>
#include <Ambient.h>

const int rx_pin = 16; //Serial rx pin
const int tx_pin = 17; //Serial tx pin

MHZ19_uart mhz19;
Ticker tk;
WiFiClient client;
Ambient am;

/*Ticker*/
const float period = 60 * 1; //1min per sending

/*Wi-Fi*/
const char* ssid = "your ssid";
const char* password = "your password";

/*Ambient*/
unsigned int channelId = your channelId;
const char* writeKey = "your writeKey";

void send2a(){
  int co2ppm = mhz19.getCO2PPM();
  Serial.print("co2: ");
  Serial.println(co2ppm);  
  am.set(1, co2ppm);
  am.send();
}


/*Main Program*/
void setup(){
  /*Wi-Fi設定*/
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  }
  
  /*Ambient設定*/
  am.begin(channelId, writeKey, &client);

  /*割込み処理の設定*/
  tk.attach(period, send2a);
  
  /*CO2センサ設定*/
  mhz19.begin(rx_pin, tx_pin);
  mhz19.setHardwareSerialNo(2);  
  mhz19.setAutoCalibration(true);
  Serial.begin(9600);
  Serial.println("MH-Z19 is warming up now.");
  delay(10 * 1000);
}

void loop(){
}