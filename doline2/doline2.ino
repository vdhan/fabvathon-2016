#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1); // motor 1
AF_DCMotor motor2(2); // motor 2
AF_DCMotor motor3(3); // motor 3
AF_DCMotor motor4(4); // motor 4
Servo servo;

int pos = 140;
int n = 0;
void queotrai();
void queophai();
void quangtien();

void setup()
{
  Serial.begin(9600);

  pinMode(53, INPUT); // giữa
  pinMode(51, INPUT); // trái 1
  pinMode(49, INPUT); // phải 1
  pinMode(47, INPUT); // trái 2
  pinMode(45, INPUT); // phải 2

  servo.attach(10);
  servo.write(pos);
}

void loop()
{
  int b = 230;
  int c = 150;
  boolean a = 1;

  if (digitalRead(47) == 0 & digitalRead(45) == 0) // cua phải
  {
    a = 0;
  }

  if (a == 0)
  {
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    delay(100);

    a = 1;
    n++;
  }

  if (n == 1 | n == 3 | n == 14 | n == 19 | n == 21 | n == 26)
  {
    queophai();
  }

  if (n == 5 | n == 8 | n == 12 | n == 16)
  {
    queotrai();
  }

  if (n == 10)
  {
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    quangtien();

    n++;
  }

  if (n == 23)
  {
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    quangtien();

    n++;
  }

  if (n == 28)
  {
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(100);

    motor2.run(FORWARD);
    motor3.run(FORWARD);
    delay(100);

    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    delay(500);

    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(100);

    quangtien();
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(10000);
  }

  if (digitalRead(53) == 0 & digitalRead(51) == 0 & digitalRead(49) == 0 &  digitalRead(47) == 1 & digitalRead(45) == 1)
  {
    motor2.setSpeed(b);
    motor3.setSpeed(b);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }

  if (digitalRead(53) == 0 & digitalRead(51) == 1 & digitalRead(49) == 1) // thang
  {
    motor2.setSpeed(b); // trái
    motor3.setSpeed(b); // phải
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }

  if (digitalRead(53) == 0 & digitalRead(51) == 0 & digitalRead(49) == 1) // lệch phải
  {
    motor2.setSpeed(b); // trái
    motor3.setSpeed(b); // phải
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }

  if (digitalRead(53) == 0 & digitalRead(51) == 1 & digitalRead(49) == 0) // lệch trái
  {
    motor2.setSpeed(b); // trái
    motor3.setSpeed(c); // phải
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }

  if (digitalRead(53) == 1 & digitalRead(51) == 1 & digitalRead(49) == 0) // lệch trái
  {
    motor2.setSpeed(b - 30); // trái
    motor3.setSpeed(c - 30); // phải
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }

  if (digitalRead(53) == 1 & digitalRead(51) == 1 & digitalRead(49) == 1) // ngưng
  {
    motor2.setSpeed(c); // trái
    motor3.setSpeed(b); // phải
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  }

  if (digitalRead(53) == 1 & digitalRead(51) == 0 & digitalRead(49) == 1) // lệch phải
  {
    motor2.setSpeed(c); // trái
    motor3.setSpeed(b); // phải
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }

  if (digitalRead(53) == 1 & digitalRead(51) == 1 & digitalRead(49) == 1 & digitalRead(47) == 1 & digitalRead(45) == 0) // lệch trái
  {
    motor3.run(FORWARD);
    motor2.run(BACKWARD);
    delay(50);

    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(100);
  }

  if (digitalRead(53) == 1 & digitalRead(51) == 1 & digitalRead(49) == 1 & digitalRead(47) == 0 & digitalRead(45) == 1) // lệch phải
  {
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    delay(50);

    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(100);
  }
}

void queotrai()
{
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(300);

  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  delay(100);

  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(300);

  while (digitalRead(53) == 1)
  {
    motor3.run(FORWARD);
    motor2.run(BACKWARD);
    delay(50);

    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(80);

    if (digitalRead(53) == 0)
    {
      n++;
    }
  }
}

void queophai()
{
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(300);

  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  delay(100);

  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(300);

  while (digitalRead(53) == 1)
  {
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    delay(50);

    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(80);

    if (digitalRead(53) == 0)
    {
      n++;
    }
  }
}

void quangtien()
{
  servo.write(25);
  delay(200);

  servo.write(pos);
  delay(200);
}

