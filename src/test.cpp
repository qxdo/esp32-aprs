// #include <ESP8266WiFi.h>
// #include "DHTesp.h"


// DHTesp dht;
// WiFiClient client;




// void loop()
// {
//   delay(10000);

//   if (connect_wifi)
//   {
//     while (!client.connected())
//     {
//       if (!client.connect(host, port))
//       {
//         Serial.println("wait connection.to server ......");
//       }
//     }

//     while (client.connected())//??????? ?
//     {
//       if (client.available())//??????????0
//       {
//         String line = client.readStringUntil('\r\n');//?????
//         Serial.println(line);//????????

//         if (line.indexOf("javAPRSSrvr") != -1) { // !=-1?? ==-1???
//           Serial.println("javAPRSSrvr");
//         } else if (line.indexOf("aprsc") != -1) {
//           Serial.println("aprsc");
//           client.print(logininfo);//??????????

//         } else if (line.indexOf("verified") != -1) {
//           //????
//           Serial.println("verified");

//           auth = true;
//         } else {
//           Serial.println("none");
//         }

//         //
//         if (auth == true) {
//           //
//           int humidity = dht.getHumidity();
//           int temperature = dht.getTemperature();
//           int temperaturef = dht.toFahrenheit(temperature);
//           //
//           //            -- c000s000g000t086r000p000h53b10020
//           //            -- ????35???????????????OD,OA?
//           //
//           //            -- ?????
//           //            -- c000???????????
//           //            -- s000??1?????????????
//           //            -- g000??5???????????????
//           //            -- t086???????
//           //            -- r000????????0.01???
//           //            -- p000??24????????0.01???
//           //            -- h53????00?= 100??
//           //            -- b10020????0.1 hpa?

//           snprintf(senddata, sizeof(senddata), "BG8JUN-0>AP51DW,qAS,:=2932.13N/10636.25E_000/000g000t0%dr000p000h%db09691 cyqsd's APRS use ESP32 144.800Mhz~ 3.3V\r\n", temperaturef, humidity);
//           client.print(senddata);//????????

//           //          Serial.print("APRS POST: ");
//           Serial.println(senddata);
//           //          Serial.println("");
//         }
//       }
//     }
//   }
// }
