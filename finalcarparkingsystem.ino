#include <Servo.h>

Servo ser;

const int ir1 = 7;
const int ir2 = 8;

void setup() {
  ser.attach(6);
  pinMode(ir1, INPUT);
  Serial.begin(9600);
  ser.write(0); // It's main  position
  servostart();
}


void servostart(){       //In the line 19 to 33 it rotate the servo in some different position.
  ser.write(0);
  delay(790);
  ser.write(90);
  delay(800);
  ser.write(160);
  delay(400);
  ser.write(30);
  delay(500);
  ser.write(40);
  delay(650);
  ser.write(11);
  delay(340);
  ser.write(0);
}




void loop() {
  int ir1read = digitalRead(ir1);
  int ir2read = digitalRead(ir2);


  if (ir1read == LOW || ir2read == LOW) {
  ser.write(145);    //In the line 40 to 41 ,it ditectin weathe the object is hear.
  Serial.println("Gate is open.");
  delay(2500); // keep gate open for 2 seconds and then close.
  ser.write(0);
  }
 else{
  Serial.println("Gate is closed");
 }
}

