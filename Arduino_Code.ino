#include <Servo.h>
Servo servo;
int const trigPin1 = 6;
int const echoPin1 = 5;
int const trigPin2 = 9;
int const echoPin2 = 8;
int const led1 = A1;
int const led2 = A2;
int const led3 = A3;

void setup ()
{
pinMode (trigPin1, OUTPUT);
pinMode (echoPin1, INPUT);
pinMode (trigPin2, OUTPUT);
pinMode (echoPin2, INPUT);
pinMode(led1, OUTPUT);
pinMode (led2, OUTPUT);
pinMode (led3, OUTPUT);
servo.attach (3);
Serial.begin (9600);
}

void loop ()
{
int duration1, distance1, duration2, distance2;
digitalWrite (trigPin1, HIGH);
delay (1);
digitalWrite (trigPin1, LOW);
duration1 = pulseIn (echoPin1, HIGH);
distance1 = (duration1/2)/29.1;
if (distance1 <=50 && distance1 >=5)
{
servo.write(50);
delay (3000);
}
else
{
servo.write (160);
}
digitalWrite (trigPin2, HIGH);
delay (1);
digitalWrite (trigPin2, LOW);
duration2 = pulseIn (echoPin2, HIGH);
distance2 = (duration2/2)/29.1;
if (distance2 >=16)
{
digitalWrite (led1, HIGH);
digitalWrite (led2, LOW);
digitalWrite (led3, LOW);
}
if (distance2 >=8 && distance2<16)
{
digitalWrite (led1, LOW);
digitalWrite (led2, HIGH);
digitalWrite (led3, LOW);
}
if (distance2 >=0 && distance2<8)
{
digitalWrite (led1, LOW);
digitalWrite (led2, LOW);
digitalWrite (led3, HIGH);
}
}
