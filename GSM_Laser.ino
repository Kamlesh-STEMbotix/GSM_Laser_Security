#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2
int data = 0; 

int sensor = A1; 
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);
 pinMode(sensor, INPUT); 
  pinMode(4, OUTPUT); 
  //Serial.println("Initializing..."); 
 
  //delay(1000);

 //mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  //updateSerial();

  //mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  //updateSerial();
 //mySerial.println("AT+CMGS=\"+918849828574\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
 // updateSerial();
  //mySerial.print("Last Minute Engineers | lastminuteengineers.com"); //text content
  //updateSerial();
 // mySerial.write(26);
}

void loop()
{
  data = analogRead(sensor); 
Serial.println(data); 
if ( data >800) // 
  {
     Serial.println("Initializing..."); 
 digitalWrite(4,HIGH);
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
 mySerial.println("AT+CMGS=\"+918849828574\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("ALERT!!! Unwanted Entry Detected, Thanks From Saraswati Vidhyalay Ramas"); //text content
  updateSerial();
  mySerial.write(26);
  }
  else
  {
    digitalWrite(4,LOW);
  }

}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}