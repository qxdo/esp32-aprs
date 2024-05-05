#include <driver/ledc.h> // LEDC support
#include <Arduino.h>
#include <WiFi.h>
const char* ssid = "PDCN"; // 密码
const char* password = "13037679105"; // 密码

const char *host = "asia.aprs2.net";
const int port = 14580;
bool auth = false;
const char *logininfo = "user BH4FWA pass 21165 vers ESP32Weather 0.0.1 filter m/500\r\n";
char senddata[150] = {0};


WiFiClient client;

void startConnect(){

  while(!client.connected()){
      if(!client.connect(host, port)){
          Serial.println("wait connection.to server ......");
      }
  }
  while (client.connected()){
      if (client.available()) {
        String line = client.readStringUntil('\r\n');
        Serial.println(line);
        if(line.indexOf("javAPRSSrvr") != -1) {
          Serial.println("javAPRSSrvr");
        } else if (line.indexOf("aprsc") != -1) {
          Serial.println("aprsc");
          client.print(logininfo);
        } else if (line.indexOf("verified") != -1) {
          Serial.println("verified");
          auth = true;
        } else {
          Serial.println("verify none");
        }

        // auth == true
        if(auth == true){

          // shidu
          int humidity = 80; //dht.getHumidity();
          // wendu
          // int temperature = 86; // dht.getTemperature();
        
          int temperaturef =  86;// dht.toFahrenheit(temperature);
          //
          //            -- c000s000g000t086r000p000h53b10020
          //            -- 每秒输出35个字节，包括数据末尾的换行符（OD,OA）
          //
          //            -- 数据解析：
          //            -- c000：风向角度，单位：度。
          //            -- s000：前1分钟风速，单位：英里每小时
          //            -- g000：前5分钟最高风速，单位：英里每小时
          //            -- t086：温度（华氏）
          //            -- r000：前一小时雨量（0.01英寸）
          //            -- p000：前24小时内的降雨量（0.01英寸）
          //            -- h53：湿度（00％= 100％）
          //            -- b10020：气压（0.1 hpa）
          // 
          snprintf(senddata, sizeof(senddata), "BH4FWA-0>AP32RS,qAS,:=3113.69N/12131.31E_000/000g000t0%dr000p000h%db09691 qxdo's APRS use ESP32 144.8Mhz. 3.3V\r\n", temperaturef, humidity);
          client.print(senddata);// send to server:port
          Serial.print("APRS POST:");
          Serial.println(senddata);
        }
      }
  }
}

void LED_Light() {
  
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT); 

    Serial.begin(9600);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000); // ??1?
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("WiFi connected");
    Serial.println("IP address:");
    Serial.println(WiFi.localIP());  
}

void loop() {
   // ??WiFi??
    if(WiFi.status() == WL_CONNECTED){
      LED_Light();
      startConnect();
    } 
}


