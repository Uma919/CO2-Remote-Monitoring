#include <M5Stack.h>
#include <Ticker.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>

Ticker tk;
WiFiClient client;

/*Ticker*/
const float period = 60 * 0.5; //0.5min per sending

/*Wi-Fi*/
const char* ssid = "your ssid";
const char* password = "your password";

/*Ambient*/
unsigned int channelId = your channelId;
const char* writeKey = "your writeKey";

void readAmbient(){ 
  String url = "http://ambidata.io/api/v2/channels/" + String(channelId) + "/data?&readKey=" + String(readKey) + "&n=1";
  
  HTTPClient httpClient;
  httpClient.begin(url);
  int httpCode = httpClient.GET();
  String httpResult = httpClient.getString();
  httpClient.end();

  const size_t capacity = 500;
  DynamicJsonDocument result(capacity);
  deserializeJson(result, httpResult);
  String co2ppm = result[0]["d1"];
  String sendtime = result[0]["created"];

  String fpt32 = "/font/genshin-regular-32pt";  
  M5.Lcd.loadFont(fpt32, SD);  
  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(0,0);
  M5.Lcd.println("二酸化炭素濃度");
  M5.Lcd.setCursor(0,32);
  M5.Lcd.print(co2ppm);
  M5.Lcd.println("[ppm]");
  M5.Lcd.unloadFont();  
}

/*Main program*/
void setup() {
  /*M5Stack設定*/
  M5.begin();
  
  /*Wi-Fi設定*/
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  }

  /*割込み処理の設定*/
  tk.attach(period, readAmbient);
}

void loop() {
}