#include "ESP8266WiFi.h" // WiFi Library

int pin = 16; 

const char* ssid = "Tonic"; // Name of WiFi Network
const char* password = "fetthemligt"; // Password of WiFi Network


WiFiServer server(80); // Define Web Server Port

void setup() {
Serial.begin(115200);
delay(10);
  pinMode(pin, OUTPUT);


// Connect to WiFi network
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);

// Wait until connected to WiFi
while (WiFi.status() != WL_CONNECTED) {
delay(250);
Serial.print(".");
}

// Confirmation that WiFi is connected
Serial.println("");
Serial.println("WiFi connected");

// Start the Web Server
server.begin();
Serial.println("Web Server Started");

// Display IP address
Serial.print("You can connect to the Server here: ");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println();
Serial.println();
digitalWrite(pin, HIGH);
}


void loop() {

// Check if someone is connected
WiFiClient client = server.available();
if (!client) {
return;
}

// Read which button was pressed on the Web Page
String request = client.readStringUntil('\r');

// Light Up leds based on the button pressed 

if (request.indexOf("/ON=1") != -1) {
      digitalWrite(pin, HIGH);
}
if (request.indexOf("/OFF=1") != -1) {
      digitalWrite(pin, LOW);
}

// Create Web Page
client.println("HTTP/1.1 200 OK"); // HTML Header
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");

client.println("<html>"); // Start of HTML

client.println("<style>");
//client.println("body {background-color: #ACAEAD;}"); // Set Background Color
client.println("</style>");

client.println("<br><br>");

client.println("<a href=\"/ON=1\"\">"); 
client.println("<input type=\"image\" src=\"http://i.imgur.com/m2PD9qm.png\">"); 
client.println("</a>"); 

client.println("<br><br>");

client.println("<a href=\"/OFF=1\"\">"); 
client.println("<input type=\"image\" src=\"http://i.imgur.com/N5I6A1j.png\">"); 
client.println("</a>"); 


client.println("</html>"); 
delay(10); 

}
