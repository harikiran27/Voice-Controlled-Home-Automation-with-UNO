

#include <AFMotor.h>
#include <Servo.h> 
#include <SoftwareSerial.h>
// DC motor on M2
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
int ledPin1=10;
int ledPin2=13;
// DC hobby servo
SoftwareSerial BTserial(2,3); // RX, TX
char BluetoothData;
void setup() {
  BTserial.begin(9600);
  BTserial.println("\n\nHOME AUTOMATION \n by HKG and Gokul\n\n\na(off)/b(on) - LED at 10\nc(off)/d(on) - LED at 11\ne(off)/f(on)- CHANGE DOOR STATE \nk(on)/l(off)- TURN ON/OFF THE FAN IN HALL\nh(off)/i(on) - FAN\n\nj(open for 2s) - TAP\no - FEELING LUCKY!?!\n\n\ns - TURN ON ALL APPLIANCES!\nz - TURN OFF ALL APPLIANCES!");
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  digitalWrite(ledPin2, LOW);
  // turn on motor #2
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  motor1.setSpeed(90);
  motor1.run(RELEASE);
   motor4.setSpeed(255);
  motor4.run(RELEASE);
}





// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  if (BTserial.available()){
BluetoothData=BTserial.read();
   if(BluetoothData=='a'){ 
   digitalWrite(ledPin1, LOW);
   BTserial.println("\nLED TURNED OFF.\n");
   }
   if(BluetoothData=='b'){ 
   digitalWrite(ledPin1, HIGH);
   BTserial.println("\nLED TURNED ON.\n");
   }
   if(BluetoothData=='c'){ 
   digitalWrite(ledPin2, LOW);
   BTserial.println("\nLED TURNED OFF.\n");
   }
   if(BluetoothData=='d'){ 
   digitalWrite(ledPin2, HIGH);
   BTserial.println("\nLED TURNED ON.\n");
   }
   if(BluetoothData=='e')
   {
    motor1.run(BACKWARD);
    delay(350);
    motor1.run(RELEASE);
    BTserial.println("\nDOOR CLOSED.\n");
   }
   if(BluetoothData=='f')
   {
   motor1.run(FORWARD);
   delay(350);
    motor1.run(RELEASE);
   BTserial.println("\nDOOR OPENED.\n");
   }
   if(BluetoothData=='k')
   {
      motor2.run(FORWARD);
      BTserial.println("\nFAN IN HALL HAS BEEN TURNED ON!.\n");
   }
   if(BluetoothData=='l')
   {
      motor2.run(RELEASE);
      BTserial.println("\nFAN IN HALL HAS BEEN TURNED OFF!.\n");
   }
   if(BluetoothData=='h')
   {
   motor3.run(RELEASE);
   BTserial.println("\nFAN TURNED OFF.\n");
   }
   if(BluetoothData=='i')
   {
   motor3.run(FORWARD);
   BTserial.println("\nFAN TURNED ON.\n");
   }
   if(BluetoothData=='j')
   {
   motor4.run(FORWARD);
   delay(1500);
    motor4.run(RELEASE);
    BTserial.println("\nTHANNI DAW!.\n");
   }
   if(BluetoothData=='o'){ 
   BTserial.println("\nYEEEAAAHH!!\nENTER '.' - STOP");
   
   while(BTserial.read()!='.')
   {
    digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, HIGH);
   delay(100);
   digitalWrite(ledPin2, LOW);
   digitalWrite(ledPin1, HIGH);
   delay(100);
   if(BTserial.read()=='z')
   break;
   }
   digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
   }
   if(BluetoothData=='s')
   {
     digitalWrite(ledPin1, HIGH);
     digitalWrite(ledPin2, HIGH);
      motor1.run(FORWARD);
      delay(350);
      motor1.run(RELEASE);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      delay(350);
      motor4.run(RELEASE);

    BTserial.println("\nPARTIIEEEE!!.\n");
   }
  if(BluetoothData=='z')
   {
     digitalWrite(ledPin1, LOW);
     digitalWrite(ledPin2, LOW);
      motor1.run(BACKWARD);
      delay(350);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    BTserial.println("\nFLOP!!.\n");
   }
   delay(100);
  }
}
