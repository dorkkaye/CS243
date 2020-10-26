int i;
void setup()
{
   pinMode(0,OUTPUT); //0 means output
   pinMode(1,1); //1 means input
   pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
   pinMode(4,INPUT);
   pinMode(5,INPUT);

   digitalWrite(0,0);
   digitalWrite(1,0);
   digitalWrite(2,0);
   digitalWrite(3,0);
}

void kipatkipat() //Blink
{
   digitalWrite(0, 0);
   digitalWrite(1, 0);
   digitalWrite(2, 0);
   digitalWrite(3, 0);
   delay(500);
   digitalWrite(0, 1);
   digitalWrite(1, 2);
   digitalWrite(2, 3);
   digitalWrite(3, 4);
}

void seq1()
{
  for(i = 0; i < 4; i++)
  {
    digitalWrite(i,1);
   delay(500);
   digitalWrite(i,0);
  }
}

void loop() //Like void main but looping
{
 if(digitalRead(4)==1)
  kipatkipat();

 if(digitalRead(5)==1)
  seq1();
} 
