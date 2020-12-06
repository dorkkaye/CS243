int PC,IR,AR,DR,ZF,W,FR1,FR2;
int c=0,m=1,D,I;

void setup() 
{
  
  // put your setup code here, to run once:
  PC=IR=AR=DR=ZF=W=FR1=FR2=0;
  
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  // set data  bus
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  pinMode(20,INPUT);
  pinMode(21,INPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
}

void fetch1()
{
  AR=PC; 
  // send data of AR to address bus
  
  m=1;
 for(c=0;c<8;c++)
 {
  if((AR&m)==0)
     digitalWrite(c,0);
  else 
     digitalWrite(c,1);
     
  m=m*2;
 }  
}

void fetch2()
{
  PC=PC+1;
  DR=0;
  m=1;
  
  for(c=8;c<24;c++)
  {
      if(digitalRead(c)==1)
          DR=(DR|m);
          
      m=m*2;
  }
}

void fetch3()
{
  IR=(DR>>10);
  IR=IR&0xFFEF; //IR=IR&0b1111111111101111
  
}


void MOVR()
{
  AR=DR&0x00ff;
}

void MOVI()
{
  I=(DR&0x00FF);
  D=(DR>>9);
  D=(D&0xFFF3);
  
  //D 0,1,2
  if(D==0)
    W=I;
  if(D==1)
    FR1=I;
  if(D==2)
    FR2=1;
}

void LODR()
{
  AR=DR&0x00ff;
}
    
void GOTO()
{
  I=(DR&0x00FF);
  PC=I;
}

void JMPZ()
{
  if(ZF=1)
  {
    I=(DR&0x00FF);
    P=I
  }
}

void JMPNZ()
{
  if(ZF=0)
  {
    I=(DR&0x00FF);
    P=I
  }
}

void NOP()
{

}

void AND()
{
  I=(DR&0x00FF);
  D=(DR>>9);
  D=(D&0xFFF3);
  
  //D 0,1,2
  if(D==0)
    W=I;
  if(D==1)
    FR1=I;
  if(D==2)
    FR2=1;
}

void OR(){}

void XOR(){}

void ADD(){}

void SUB(){}

void loop() 
{
  
  // put your main code here, to run repeatedly:
   fetch1();
   fetch2();
   fetch3();
   
   // assume IR has the opcode
   if(IR==1)
      MOVR();
   if(IR==2)
      MOVI();
   if(IR==3)
      LODR();
   if(IR==6)
      GOTO();
   if(IR==7)
      JMPZ();
   if(IR==8)
      JMPNZ();
   if(IR==0)
      NOP();
   if(IR==9)
      AND();
   if(IR==10)
      OR();
   if(IR==11)
      XOR();
   if(IR==12)
      ADD();
   if(IR==13)
      SUB();

 delay(1000);
}
