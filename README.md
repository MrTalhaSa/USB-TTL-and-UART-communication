# USB-TTL-and-UART-communication
Requirements
Arduino (Uno, Nano, etc.)
SoftwareSerial library
LED (and a current-limiting resistor)
TTL adapter (RS232 or similar)
Jumper wires
Hardware Connections
Connect an LED to pin 13 of the Arduino.
Connect the RX pin of the TTL adapter to Arduino pin 10, and the TX pin to pin 11.
Software
This project uses Arduino's SoftwareSerial library to communicate via TTL. You can control the LED's state by sending 'A' or 'B' commands:

'A' command: Turns the LED on.
'B' command: Turns the LED off.
Upload the following code to your Arduino using the Arduino IDE to run the project.

How It Works
The Arduino communicates with a TTL device (or a computer) using the SoftwareSerial library.
The code listens for commands sent to the TTL port. If the command is 'A', the LED turns on, and if the command is 'B', the LED turns off.
The system also sends any received data back to the computer for feedback.

