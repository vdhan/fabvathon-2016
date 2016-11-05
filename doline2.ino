#include <AFMotor.h>
AF_DCMotor motor1(1); // motor 1
AF_DCMotor motor2(2); // motor 2
AF_DCMotor motor3(3); // motor 3
AF_DCMotor motor4(4); // motor 4

int n = 0;
int z;
void queotrai();
void queophai();

void setup()
{
  Serial.begin(9600);
  
  pinMode(53,INPUT); // giữa
  pinMode(51,INPUT); // trái 1
  pinMode(49,INPUT); // phải 1
  pinMode(47,INPUT);// trái 2
  pinMode(45,INPUT); // phải 2
}

void loop()
{
  int b = 230;
  int c= 150;
  boolean a=1;
  if(digitalRead(47)==0&digitalRead(45)==0) // cua quẹo phải
  {
    a=0;
  }
  if (a == 0)
  {
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    a = 1;
    delay(100);
    n++;
  }
        
  if ((n == 1)|(n==5)|(n==8) | (n == 11) | (n == 16) | (n == 18) | (n == 22))
  {
    queophai();
  }
     
     if(n == 14) {
       queotrai();
     }
     if( n==24)
     {motor2.run(RELEASE);
       motor3.run(RELEASE);
    
      delay(500);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      delay(600);
       motor2.run(FORWARD);
       motor3.run(BACKWARD);
       delay(350);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(500);
       while(digitalRead(53) == 1)
        {motor2.run(FORWARD);
       motor3.run(BACKWARD);
       delay(50);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(100);
        if(digitalRead(53)==0)
       {
         n++;
     }}}
     if(n==26)
     {
       motor3.run(RELEASE);
       motor2.run(RELEASE);
       delay(10000);}
     
/*     if (digitalRead(53)==1 & digitalRead(51)==1&digitalRead(49)==81&digitalRead(47)==1&digitalRead(45)==1)
     {
       motor2.run(FORWARD);
       motor3.run(BACKWARD);
       delay(50);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(100);
     }*/
    if(digitalRead(53)==0&digitalRead(51)==0&digitalRead(49)==0&digitalRead(47)==1&digitalRead(45)==1)
    {
      motor2.setSpeed(b);
      motor3.setSpeed(b);
      motor2.run(FORWARD);
      motor3.run(FORWARD);}
         
  if (digitalRead(53) == 0&digitalRead(51)==1&digitalRead(49)==1)//thẳng
  {motor2.setSpeed(b); //trái
  motor3.setSpeed(b); //phải
    motor2.run(FORWARD);
   motor3.run(FORWARD);
  }
 if (digitalRead(53) == 0&digitalRead(51)==0&digitalRead(49)==1)//lệch phải
  {motor2.setSpeed(b); //trái
  motor3.setSpeed(b); //phải
    motor2.run(FORWARD);
   motor3.run(FORWARD);
  z=3;}
  if (digitalRead(53) == 0&digitalRead(51)==1&digitalRead(49)==0)//lệch trái
  {motor2.setSpeed(b); //trái
  motor3.setSpeed(c); //phải
    motor2.run(FORWARD);
   motor3.run(FORWARD);
   z= 3;
  }if (digitalRead(53) == 1&digitalRead(51)==1&digitalRead(49)==0)//lệch trái
  {motor2.setSpeed(b-30); //trái
  motor3.setSpeed(c-30); //phải
    motor2.run(FORWARD);
   motor3.run(FORWARD);
   z=0;
  }if (digitalRead(53) == 1&digitalRead(51)==1&digitalRead(49)==1)//NGỪNG
  {motor2.setSpeed(c); //trái
  motor3.setSpeed(b); //phải
    motor2.run(RELEASE);
   motor3.run(RELEASE);
  }if (digitalRead(53) == 1&digitalRead(51)==0&digitalRead(49)==1)//lệch phải
  {motor2.setSpeed(c); //trái
   motor3.setSpeed(b); //phải
    motor2.run(FORWARD);
   motor3.run(FORWARD);
 z=1;}
   if (digitalRead(53) == 1&digitalRead(51)==1&digitalRead(49)==1&digitalRead(47)==1&digitalRead(45)==0)//lệch trái
  {
    motor3.run(FORWARD);
       motor2.run(BACKWARD);
       delay(50);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(100);
 }
   if (digitalRead(53) == 1&digitalRead(51)==1&digitalRead(49)==1&digitalRead(47)==0&digitalRead(45)==1)//lệch phải
  {
       motor2.run(FORWARD);
       motor3.run(BACKWARD);
       delay(50);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(100);}}
void queotrai()
 {
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(500);
       
       motor3.run(FORWARD);
       motor2.run(BACKWARD);
       delay(100);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(500);
       while(digitalRead(53) == 1)
        {motor3.run(FORWARD);
       motor2.run(BACKWARD);
       delay(50);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(100);
        if(digitalRead(53)==0)
       {
         n++;
     }
       
       
     }}
  void queophai(){
     motor2.run(RELEASE);
       motor3.run(RELEASE);
    
      delay(500);
       motor2.run(FORWARD);
       motor3.run(BACKWARD);
       delay(100);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(500);
       while(digitalRead(53) == 1)
        {motor2.run(FORWARD);
       motor3.run(BACKWARD);
       delay(50);
       motor2.run(RELEASE);
       motor3.run(RELEASE);
       delay(100);
        if(digitalRead(53)==0)
       {
         n++;
     }}}
       
//  if(digitalRead(53) == 0&digitalRead(51)==0&digitalRead(49)==0) //cbi qẹo
//  {motor2.run(RELEASE);
  //  motor3.run(RELEASE);}
   // if(digitalRead(45)!=1&digitalRead(47)!=1)
   // { delay(100);
   //  n = n+1;
     
   //   Serial.println(n);
    
//  }
  
   //if (n ==1)
  // {int t;
  // for(t= millis();t=t+1;t<200){
//     motor2.setSpeed(200);
  //   motor3.setSpeed(200);
  //   motor2.run(FORWARD);
  //  motor3.run(BACKWARD);
//  Serial.println("asdsadasd");}

   
   
 
   
  
  
  
  

