/*
  Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin P1.4 (connect to TX of other device)
 * TX is digital pin P1.3 (connect to RX of other device)
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 modified again 8 Feb 2013
 by Brian Baker for MSP430
 
 This example code is in the public domain.
 
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(P1_4, P1_3); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  delay(100);
  Serial.println("AT");
  Serial.println("Hello world");
  //Serial.write("AT");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  mySerial.write("AT+ADVI?");
  mySerial.write("AT");
}

void loop() // run over and over
{
  Serial.println("AT");
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}

