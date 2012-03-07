#include <SoftwareSerial.h>

const int baudRate = 9600;     // baud rate for mp3trigger
const int ledPin =  13;        // the number of the LED pin

SoftwareSerial mp3trigger(2, 3);  // define the mp3trigger serial object

int incomingPort = 0;

void setup()  // let's get this party started
{
  // define the arduino's hardware port
  Serial.begin(baudRate);

  // set the data rate for mp3trigger's SoftwareSerial port
  mp3trigger.begin(baudRate);
  setQuiet( true ); 
  
  // define the LED pin light
  pinMode(ledPin, OUTPUT); 
}

void setQuiet( bool quiet ) //set mp3trigger to quiet mode 
{
   byte cmd[2] = { 'Q', quiet ? '0' : '1' };
   Serial.write( cmd, sizeof(cmd) );

}


void loop() // run over and over
{
  // check if info is being sent over the port
  if (mp3trigger.available()) {
      digitalWrite(ledPin, HIGH);
      
      //read the incoming data
      incomingPort = mp3trigger.read();
      
      Serial.print('received ');
      Serial.println(incomingPort, DEC);
      
      delay(2000);
      
      digitalWrite(ledPin, LOW);
  }
}
