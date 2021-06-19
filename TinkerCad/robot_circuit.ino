/**
 * Arizona State University
 * FSE 100
 * Team Electrosity
 * Motor Controller Demo
 *
 *
 * This circuit and corresponding program
 * demonstrate using an Arduino to control
 * 4 DC geared motors. The circuit makes 
 * use of 1 74HC595 Shift Register and 
 * 2 L293D Half-H Drivers to enable a 
 * full-range of motion and control of 
 * 4 motors.
 *
 * The Shift Register, Half-H Drivers,
 * and auxilliary power from the 9V
 * battery combined create a motor controller
 * which only requires 4 pins from an Arduino
 * to fully control.
 *
 * The ad-hoc motor controller will be
 * supplanted by a proper motor controller,
 * however, that device is not available in
 * TinkerCad.
 *
 * The circuit also demonstrates using a 
 * servo and distance sensor for obstacle
 * avoidance.
 *
 * Finally, an actuator for our elevating
 * platform is simulated by a servo.
 */

#include <Servo.h>

// Motor Controller
int DATA = 2;
int LATCH = 3;
int CLOCK = 4;
int ENABLE = 5;

// Obstacle Avoidance
int ECHO = 7;
int TRIGG = 6;
int OBSTACLE_SERVO = 9;
Servo obstacle_servo;

// Platform
int PLATFORM_SERVO = 10;
Servo platform_servo;

void setup(){
  // Motor Controller
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  
  // Obstacle Avoidance
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIGG, OUTPUT);
  obstacle_servo.attach(OBSTACLE_SERVO, 500, 2500);
  
  // Platform
  platform_servo.attach(PLATFORM_SERVO, 500, 2500);
}

void loop(){
  drive_demo();
  obstacle_demo();
  platform_demo();
}

//////////////////////////
//// Motor Controller ////
//////////////////////////

/**
 * Demonstrate driving operations
 */
void drive_demo(){
  drive_stop();
  delay(1000);
  drive_forward();
  delay(1000);
  drive_reverse();
  delay(1000);
  drive_left();
  delay(1000);
  drive_right();
  delay(1000);
}

/**
 * Write 8 bits to the shift register.
 * When the shift register is enabled,
 * the bits will be output to the 
 * inputs of the L293D Half-H drivers.
 *
 * @param decimal - A decimal number to be 
 * converted to binary and passed in bit by bit.
 */
void writeToMotorController(int decimal){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, decimal);
  digitalWrite(LATCH, HIGH);
}

/**
 * Write 00000000 to and disable the shift register
 */
void drive_stop(){
  writeToMotorController(0);
  digitalWrite(ENABLE, LOW);
}

/**
 * Write 01011010 to and enable the shift register
 */
void drive_forward(){
  writeToMotorController(90);
  digitalWrite(ENABLE, HIGH);
}

/**
 * Write 10100101 to and enable the shift register
 */
void drive_reverse(){
  writeToMotorController(165);
  digitalWrite(ENABLE, HIGH);
}

/**
 * Write 01010101 to and enable the shift register
 */
void drive_left(){
  writeToMotorController(85);
  digitalWrite(ENABLE, HIGH);
}

/**
 * Write 10101010 to and enable the shift register
 */
void drive_right(){
  writeToMotorController(170);
  digitalWrite(ENABLE, HIGH);
}

////////////////////////////
//// Obstacle Avoidance ////
////////////////////////////

/**
 * Demonstrate obstacle avoidance operation
 */
void obstacle_demo(){
  look_forward();
  delay(1500);
  look_left();
  delay(1500);
  Serial.println(measure_distance());
  delay(1500);
  
  look_forward();
  delay(1500);
  look_right();
  delay(1500);
  Serial.println(measure_distance());
  delay(1500);
}

/**
 * Measure distance
 *
 * @return long Distance to nearest object in centimeters
 */
long measure_distance(){
  digitalWrite(TRIGG, LOW);
  delay(2);
  digitalWrite(TRIGG, HIGH);
  delay(10);
  digitalWrite(TRIGG, LOW);
  
  long duration = pulseIn(ECHO, HIGH);
  return duration / 58.2;
}

/**
 * Turn the obstacle servo to the left
 */
void look_left(){
  obstacle_servo.write(180);
}

/**
 * Turn the obstacle servo to center
 */
void look_forward(){
  obstacle_servo.write(90);
}

/**
 * Turn the obstacle servo to the right
 */
void look_right(){
  obstacle_servo.write(0);
}

//////////////////
//// Platform ////
//////////////////

/**
 * Demonstrate platform operation
 */
void platform_demo(){
  raise_platform();
  delay(1500);
  lower_platform();
  delay(1500);
}

/**
 * Extend the platform actuator
 */
void raise_platform(){
  platform_servo.write(180);
}

/**
 * Retract the platform actuator
 */
void lower_platform(){
  platform_servo.write(0);
}