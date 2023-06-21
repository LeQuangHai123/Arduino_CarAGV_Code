#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "BFhNAUiwqQ1P5Ky0pl0vtsX4Uyslzudf";
char ssid[] = "haile";
char pass[] = "111444111";
BlynkTimer timer;
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); 
  if ( pinValue == 0) {
    digitalWrite(D0,LOW); }
 else { digitalWrite(D0,HIGH);
    Serial.print("aa"); }
}
BLYNK_WRITE(V2)
{ int pinValue1 = param.asInt(); 
  if ( pinValue1 == 2) {
    digitalWrite(D1,HIGH); } 
else {
    digitalWrite(D1,LOW);
    Serial.print("aa"); }
}
BLYNK_WRITE(V3) {
  int pinValue2 = param.asInt(); 
  if ( pinValue2 == 0) {
    digitalWrite(D2,LOW);}  
  else { digitalWrite(D2, HIGH);
    Serial.print("aa"); }
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
  digitalWrite(D0, LOW);
  pinMode(D1, OUTPUT);
  digitalWrite(D1, LOW);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, LOW);
}
void loop() {
  Blynk.run();
}
