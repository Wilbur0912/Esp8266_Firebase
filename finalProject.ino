#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "iotfinal-9af8c-default-rtdb.firebaseio.com"              // the project name address from firebase id
#define FIREBASE_AUTH "jsqJDnOoVU6SXvDXcMfPuO8j0d88Phk03nOOSjQk"       // the secret key generated from firebase
#define WIFI_SSID "Weber"
#define WIFI_PASSWORD "88888888"


void setup()
{
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(2, OUTPUT); // connect to firebase                   //send initial string of led status
}

void loop()
{
  String light1 = Firebase.getString("light/light1_status");
  String light2 = Firebase.getString("light/light2_status");
  if (light1 == "1_on") {
    digitalWrite(2, LOW);
  }
  else if (light1 == "1_off"){
    digitalWrite(2, HIGH);
  }
  else if (light2 == "2_on"){
    digitalWrite(3, LOW);
  }
  else if (light2 == "2_off"){
    digitalWrite(3, HIGH);
  }
  Serial.println("light1 = "+light1);
  Serial.println("light2 = "+light2);
  delay(500);
}
