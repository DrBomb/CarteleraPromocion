#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>

ESP8266WebServer server (80);

const char *ssid = "Promo35";
bool response;

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid);
  MDNS.begin("promo35");
  MDNS.addService("http", "tcp", 80);
  SPIFFS.begin();
  server.on("/",HTTP_GET,handleRoot);
  server.on("/",HTTP_POST,handleJson);
  server.serveStatic("/bundle.js",SPIFFS,"/bundle.js","max-age=3600");
  server.begin();
  tBusy = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  while(Serial.available()){
    Serial.read();
    tBusy = false;
  }
}

void handleRoot(){
  File file = SPIFFS.open("/index.html","r");
  server.streamFile(file,"text/html");
  file.close();
}

void handleJson(){
  if(tBusy){
    const char response[] = "{\"status\":false}";
  } else {
    const char response[] = "{\"status\":true}";
    int index;
    String argument, argname = "index";
    argument = server.arg(argname);
    index = argument.toInt();
    tBusy = true;
    Serial.println(index);
    server.send(200,"text/json",response);
}

