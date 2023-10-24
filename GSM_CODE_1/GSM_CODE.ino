#include <SoftwareSerial.h> 
SoftwareSerial Sim(9, 10);

void setup(){

Sim.begin(9600); // Setting the baud rate of Sim Module
Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
delay(100);

}

void loop(){

if (Serial.available()>0)

switch(Serial.read())
// Read data given in Serial Monitor
{
case 's':
// If data is 's', goto SendMessage() function
SendMessage();
break;

case 'r':
// If data is 'r', goto ReceiveMessage() function
ReceiveMessage();
break;

}

if (Sim.available()>0){

Serial.write(Sim.read());
// If SIM module sends messages, print it to Serial monitor
}

}

void SendMessage(){

Sim.println("AT+CMGF=1"); // Sets the Sim Module in send SMS mode 
delay(1000); // Delay of 1 second

Sim.println("AT+CMGS=\"+91xxxxxxxxxx\"\t"); // Replace x with mobile number 
delay(1000);  // Delay of 1 second

Sim.println("I am SMS from Sim Module");  // Type in the SMS text you want to send ( Message you want to send)
delay(100); // Delay of 0.1 second

Sim.println((char)26); // ASCII code of CTRL+Z (to exit out) 
delay(1000);// Delay of 1 second
}


void ReceiveMessage()
{
Sim.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a Live SMS 
delay(1000); //Delay of 1 second
}
