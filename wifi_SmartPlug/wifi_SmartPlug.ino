#include <ESP8266WiFi.h>
#include <Wire.h>
String readString;
const char* ssid = "Tonic";//type your ssid
const char* password = "fetthemligt";//type your password
 
int ledPin = 2; // GPIO2 of ESP8266
int txPin = 13; // GPIO2 of ESP8266
WiFiServer server(80);//Service Port
 
void setup() {
  Serial.begin(115200);
  delay(10);
  Wire.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(txPin, OUTPUT);
  digitalWrite(txPin, LOW);
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();

  
  if(WiFi.status() != WL_CONNECTED) {
        Serial1.println("[loop] no wifi");
        WiFi.begin(ssid, password);

         while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
         }
         Serial.println("");
         Serial.println("WiFi connected");
   
        // Start the server
        server.begin();
        delay(100);
  }

  if (!client) {
    return;
  }


  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
    if (request.indexOf("/Nex=Z") != -1) {
    on0();
  } 
  if (request.indexOf("/Nex=A") != -1){
    off0();
  }
   if (request.indexOf("/Nex=O") != -1) {
    on1();
  } 
  if (request.indexOf("/Nex=B") != -1){
    off1();
  }
   if (request.indexOf("/Nex=T") != -1) {
    on2();
  } 
   if (request.indexOf("/Nex=C") != -1) {
    off2();
  } 
 
  //Set ledPin according to the request
  //digitalWrite(ledPin, value);
   
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> to turn ON Smartplug<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> to turn OFF Smartplug<br>");
  client.println("Click <a href=\"/Nex=Z\">here</a> to turn ON Smartplug0<br>");
  client.println("Click <a href=\"/Nex=A\">here</a> to turn OFF Smartplug0<br>");
  client.println("Click <a href=\"/Nex=O\">here</a> to turn ON Smartplug1<br>");
  client.println("Click <a href=\"/Nex=B\">here</a> to turn OFF Smartplug1<br>");
  client.println("Click <a href=\"/Nex=T\">here</a> to turn ON Smartplug2<br>");
  client.println("Click <a href=\"/Nex=C\">here</a> to turn OFF Smartplug2<br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}

void on0(){
  Wire.beginTransmission(2);
  Wire.write('1');
  Wire.endTransmission();    
}
void off0(){
  Wire.beginTransmission(2);
  Wire.write('4');
  Wire.endTransmission();    
}
void on1(){
  Wire.beginTransmission(2);
  Wire.write('2');
  Wire.endTransmission();    
}
void off1(){
  Wire.beginTransmission(2);
  Wire.write('5');
  Wire.endTransmission();    
}
void on2(){
  Wire.beginTransmission(2);
  Wire.write('3');
  Wire.endTransmission();    
}
void off2(){
  Wire.beginTransmission(2);
  Wire.write('6');
  Wire.endTransmission();    
}

