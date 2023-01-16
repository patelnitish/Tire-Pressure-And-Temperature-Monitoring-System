#include <IRremote.h>

int RECV_PIN = 10;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(13,OUTPUT);
}


void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    if (results.value == 16580863){
     digitalWrite(13,HIGH); 
    }
    irrecv.resume(); // Receive thxt value
  }
  delay(100);
}