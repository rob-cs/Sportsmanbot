#include Ultrasonic.h

Ultrasonic ultrasonic( /* location of sensor? */ );
const int IN1 = /*pin number*/;
const int IN2 = /*pin number*/;
const int IN3 = /*pin number*/;
const int IN4 = /*pin number*/;
#define IR_sensor_front A0 // front sensor
#define IR_sensor_back A1 // rear senson
int distance ;

void setup() {
  Serial.begin(9600);
  // delay?
}

void loop() {

  int IR_front = analogRead(IR_sensor_front);
  int IR_back = analogRead(IR_sensor_back);
  distance = ultrasonic.read();
  
  // add turning? until spot other robot

  if (IR_front /* compare to boundary line color */) {
    // delays ?
    Stop();
    BACKWARD(255);
  } 
   
  if (IR_back /* compare to boundary line color */ ) {
    Stop();
    FORWARD(255);
  } 
}

void FORWARD (int Speed) {
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,Speed);
}

void BACKWARD (int Speed) {
  analogWrite(IN1,0);
  analogWrite(IN2,Speed);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}

void ROTATE (int Speed) {
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}

void Stop() {
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}