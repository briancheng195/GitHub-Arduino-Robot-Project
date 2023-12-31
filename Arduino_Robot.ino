#include <Servo.h>
Servo servo;
int servoPin = 7;
int TRIG_PIN = 13;
int ECHO_PIN = 12;
int MOTOR_PIN1 = 6;
int MOTOR_PIN2 = 5;
float SPEED_OF_SOUND = 0.0345;

void setup() {
  servo.attach(ServoPin);
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(TRIG_PIN_OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int microsecs = pulseIn(ECHO_PIN, HIGH);
  float cms = microsecs*SPEED_OF_SOUND/2;    #Calculating the distance from the ultrasonic sensor to the wall
  servo.write(0);
  Serial.println(cms);
  if (cms < 9) {                             #Robot is close to the wall, program the servo motors to stop the robot from moving
    digitalWrite(MOTOR_PIN1, LOW);    
    digtialWrite(MOTOR_PIN2, LOW);
    delay(6000);
    servo.write(130);                        #Robot's catapult is activated to throw ping pong ball over the wall
    delay(350);
    servo.write(0);                          #Robot's catapult goes back to its original position
    delay(10);  
  }
  else {                                     #Robot continues moving unless it is close to the wall
  digitalWrite (MOTOR_PIN1, HIGH);
  digitalWrite (MOTOR_PIN2, HIGH);
  }
  delay(10);
}
