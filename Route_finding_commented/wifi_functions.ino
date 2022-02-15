#include <WiFi.h>

// wifi details
char ssid[] = "DCU-Guest-WiFi";
WiFiClient client;

void connectToWiFi() {
  Serial.print("Connecting to network: ");
  Serial.print(ssid);
  Serial.flush();
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    Serial.flush();
    delay(300);
  }

  Serial.println("Connected");
  Serial.print("Obtaining IP address");
  Serial.flush();
  
  while (WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    Serial.flush();
    delay(300);
  }
  
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// server details
char server[] = "54.78.246.30";
int port = 8081;

bool connect() {
  if (!client.connect(server, port)) {
    Serial.println("error connecting to server");
    return false;
  }
  Serial.println("Connected to server");
  return true;
}

// post body
void sendData(){
  String postBody("position=");
  postBody += position;
  
  // send post request and headers
  client.println("POST /api/arrived/8290b277 HTTP/1.1");
  client.println("Content-Type: application/x-www-form-urlencoded");
  client.print("Content-Length: ");
  client.println(postBody.length());
  client.println("Connection: close");
  client.println();
  
  // send post body
  Serial.println("Postbody:");
  Serial.println(postBody);
  client.println(postBody);
  
}

// Recieve data
// read buffer size for HTTP response
#define BUFSIZE 512
  
String readResponse() {
  char buffer[BUFSIZE];
  memset(buffer, 0, BUFSIZE);
  client.readBytes(buffer, BUFSIZE);
  String response(buffer);
  return response;
}
  
int getStatusCode(String& response) {
  String code = response.substring(9, 12);
  return code.toInt();
}
  
String getResponseBody(String& response) {
  int split = response.indexOf("\r\n\r\n");
  String body = response.substring(split+4, response.length());
  body.trim();
  return body;
}

void recvResponse(){
  
  // read response
  String response = readResponse();
  
  // get status code
  int statusCode = getStatusCode(response);
  
  Serial.print("Response: \n");
  Serial.println(response);
  
  if (statusCode == 200) {
    // success, read body
    String body = getResponseBody(response);
    Serial.println("Response body: ");
    Serial.print(body);
    
    // check if at final destination
    if (!body.equals("undefined")) {
      
      destination = body.toInt();
    }
  }
}
