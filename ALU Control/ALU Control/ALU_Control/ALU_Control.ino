int a,b,s,op; 


void setup() {
  // put your setup code here, to run once:
  
  //setup for input A
  pinMode(0,INPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  //setup for input B
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

  //op
  pinMode(8,INPUT); //x
  pinMode(9,INPUT); //y 
  pinMode(10,INPUT);//z

  // clock
  pinMode(11, INPUT); 

  //s
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);//carry out
  
  a=0;
  b=0;
  s=0;
  op=0;
}

void getA()
{
  if(digitalRead(0)==1)
       a=a+1;
  if(digitalRead(1)==1)
       a=a+2;
  if(digitalRead(2)==1)
       a=a+4;
  if(digitalRead(3)==1)
       a=a+8;
}


void getB()
{
  if(digitalRead(4)==1)
       b=b+1;
  if(digitalRead(5)==1)
       b=b+2;
  if(digitalRead(6)==1)
       b=b+4;
  if(digitalRead(7)==1)
       b=b+8;
}

void getOP()
{
  if(digitalRead(8)==1)
        op=op+1;
  if(digitalRead(9)==1)
        op=op+2;
  if(digitalRead(10)==1)
        op=op+4;
}

void displayS()
{
  if((s&1)==1)
     digitalWrite(A0,1);
  else 
     digitalWrite(A0,0);
  
 if((s&2)==2)
     digitalWrite(A1,1);
  else 
     digitalWrite(A1,0);

 if((s&4)==4)
     digitalWrite(A2,1);
  else 
     digitalWrite(A2,0);
   
 if((s&8)==8)
     digitalWrite(A3,1);
  else 
     digitalWrite(A3,0);
  

  if((s&16)==16)
     digitalWrite(A4,1);
  else 
     digitalWrite(A4,0);

}
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(11))
  {
    getA();
    getB();
    getOP();
    
    if(op == 0)
      s = a + b;
    if(op == 1)
      s = a - b;
    if(op == 2)
      s = a + 1;
    if(op == 3)
      s = a;
    if(op == 4)  
      s = a & b;
    if(op == 5)
      s = a | b;
    if(op == 6)
      s = a ^ b;
    if(op == 7)
      s = ~a;
      
    displayS();
  }
  
  a = 0;
  b = 0;
  s = 0;
  op = 0;
}
