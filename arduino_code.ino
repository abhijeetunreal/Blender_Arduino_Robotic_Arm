/*
  Sending live servo positions via serial commands.
  This requires a USB connection to your PC and a running Blender
  instance with the Blender Servo Animation Add-on. We use four servo which
  is controlled via the standard Arduino servo library.
*/

#include <BlenderServoAnimation.h>
#include <Servo.h>

// Servo object to send positions
Servo myServo;
Servo myServo1;
Servo myServo2;
Servo myServo3;

// Callback function which is called whenever a servo needs to be moved

void move1(byte servoID, int angle) {
  // Ignore the servoID (there is only one servo) and write the current angle
  myServo1.write(0);
  myServo1.write(angle);  
}
void move2(byte servoID, int angle) {
  // Ignore the servoID (there is only one servo) and write the current angle
  myServo2.write(2);
  myServo2.write(angle);  
}
void move3(byte servoID, int angle) {
  // Ignore the servoID (there is only one servo) and write the current angle
  myServo3.write(3);
  myServo3.write(angle);  
}
void move(byte servoID, int angle) {
  // Ignore the servoID (there is only one servo) and write the current angle
  myServo.write(5);
  myServo.write(angle);

}


// Animation object to manage the servos
// We skip providing fps or frames as we just want to use the live mode
BlenderServoAnimation::Animation animation;

// Servo object to manage the positions
BlenderServoAnimation::Servo myBlenderServo(0, move),myBlenderServo1(5, move1),myBlenderServo2(2, move2),myBlenderServo3(3, move3);

void setup() {
  Serial.begin(115200);

  // Attach the servo to pin 9
  
  myServo.attach(10);
  myServo1.attach(8);
  
  myServo2.attach(9);
  myServo3.attach(12);


  // Add the Blender servo object to the animation
  animation.addServo(myBlenderServo);
  animation.addServo(myBlenderServo1);  
  animation.addServo(myBlenderServo2);  
  animation.addServo(myBlenderServo3); 

  // Trigger the animation live mode
  animation.live(Serial);
}

void loop() {
  // Update the animation state on each loop
  animation.run();
}