char t;
 #include <Servo.h>
Servo ESC;
Servo Rudder;
void setup() {
ESC.attach(9, 1000, 2000);
 Rudder.attach(10); 
Rudder.write(90);
Serial.begin(9600);
 
}
 
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    t = Serial.read(); // Reads the data from the serial port
 }
Serial.print(t);
if (t == 'F'){
  ESC.write(35);
  Rudder.write(90);
 
}else if(t == 'G'){
ESC.write(35);
Rudder.write(65);
}else if(t == 'I'){
  Rudder.write(115);
 ESC.write(35);
}else if(t == 'S') {
  ESC.write(0);
  Rudder.write(90);
}else if(t == 'R') {
  ESC.write(0);
  Rudder.write(115);
}else if(t == 'L') {
  ESC.write(0);
  Rudder.write(65);
}
}
