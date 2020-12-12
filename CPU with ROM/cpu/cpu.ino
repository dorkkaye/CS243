int PC, IR, AR, DR, ZF;
int c = 0, m=1, D, I, RL, RR;
int GEN[] = {0,0,0};

void setup() 
{
  // put your setup code here, to run once:
  PC = IR = AR= DR= ZF = 0;
    pinMode (0, OUTPUT);
    pinMode (1, OUTPUT);
    pinMode (2, OUTPUT);
    pinMode (3, OUTPUT);
    pinMode (4, OUTPUT);
    pinMode (5, OUTPUT);
    pinMode (6, OUTPUT);
    pinMode (7, OUTPUT);
    
// set data bus
    pinMode (8, INPUT);
    pinMode (9, INPUT);
    pinMode (10, INPUT);
    pinMode (11, INPUT);
    pinMode (12, INPUT);
    pinMode (13, INPUT);
    pinMode (14, INPUT);
    pinMode (15, INPUT);
    pinMode (16, INPUT);
    pinMode (17, INPUT);
    pinMode (18, INPUT);
    pinMode (19, INPUT);
    pinMode (20, INPUT);
    pinMode (21, INPUT);
    pinMode (22, INPUT);
    pinMode (23, INPUT);

    pinMode (24, OUTPUT);
    pinMode (25, OUTPUT);
    pinMode (26, OUTPUT);
    pinMode (27, OUTPUT);
    pinMode (28, OUTPUT);
    pinMode (29, OUTPUT);
    pinMode (30, OUTPUT);
    pinMode (31, OUTPUT);
    pinMode (32, OUTPUT);
    pinMode (33, OUTPUT);
    pinMode (34, OUTPUT);
    pinMode (35, OUTPUT);
}

void fetch1()
{
   AR=PC;
//send data of AR to address bus
    m=1;
    
  for (c=0; c<8;c++)
  {
    if ((AR&m)==0)
      digitalWrite(c,0);
    else 
      digitalWrite (c,1);
      m=m*2;
   }
}

void fetch2()
{
   PC=PC+1;
   DR=0;
   m=1;
   
   for (c=8; c<24; c++)
   {
    if (digitalRead(c)==1)
      DR = (DR|m);
      m=m*2;
   }
}

void fetch3()
{
   IR = (DR>>11);
   IR = IR&0x000F;
   m=1;
   
    for(c=24; c<35;c++){
      if ((IR&m)==0)
        digitalWrite(c,0);
      else 
        digitalWrite(c,1);
        m=m*2;
     }
}

      void MOVR(){}

      void MOVI()
      {
        I= (DR&0x00FF);
        D=(DR>>9);
        D=(D&0xFFF3);
        GEN[D] = I;
      }
  
      void LODR(){}
      
      void GOTO()
      {
        I = (DR&0x00FF);
        PC=I;
      }
      
      void JMPZ(){}
      void JMPNZ(){}
      void NOP(){}
      void AND(){}
      void OR(){}
      void XOR(){}
      
      void ADD()
      {
        D = (DR>>9);
        D = (D&0x0003);
        RL =RL&0x0003;
        RR=DR;
        RR = RR&0x0003;

      GEN[D]=GEN[RL]+GEN[RR];
          if (GEN[D]==0)
             ZF=1;
          else
             ZF=0;
          }
          
     void SUB()
     {
      D = (DR>>9);
      D = (D&0x0003);
      RL =DR>>2;
      RL=RL&0x0003;
      RR=DR;
      RR = RR&0x0003;

      GEN[D]=GEN[RL]-GEN[RR];
        if(GEN[D]==0)
          ZF=1;  
        else 
          ZF=0;
     }



void loop() 
{
  // put your main code here, to run repeatedly:
  PC=0;
  fetch1();
  fetch2();
  fetch3();
//assume IR has the opcode
    if (IR=1)
      MOVR;
    if (IR=2)
      MOVI;
    if (IR=3)
      LODR;
    if (IR=6)
      GOTO;
    if (IR=7)
      JMPZ;
    if (IR=8)
      JMPNZ;
    if (IR=0)
      NOP();
    if (IR=9)
      AND();
    if (IR=10)
      OR();
    if (IR=11)
      XOR();
    if (IR=12)
      ADD();
    if (IR=13)
      SUB();

    delay (1000);

}
