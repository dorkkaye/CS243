int address=0,data=0;
int c=0,i=0,m=0;

unsigned int program[256]={0b1001000000000000,
            0b1001001000000001,
            0b1001010000000101,
            0b1110000000000001,
            0b1110110000001001,
            0b1011100000000111,
            0b1011000000000011,
            0b1011000000000111};

//variables for auto generated program instructions;
int programInstrCount = 8;
int instructionRegister; // 5 bit
unsigned int newProgram; //11 bit
int exist = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(0,INPUT);
pinMode(1,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
// set data  bus
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(14,OUTPUT);
pinMode(15,OUTPUT);
pinMode(16,OUTPUT);
pinMode(17,OUTPUT);
pinMode(18,OUTPUT);
pinMode(19,OUTPUT);
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
  
  for(c=8;c<256;c++){
    instructionRegister = c % 16; // 1001
    instructionRegister = instructionRegister & 0x1F; // 11111 && 1001 = 11001
    instructionRegister = instructionRegister << 12;
    exist = 0;
    newProgram = c & 0x7FF; //00000001000
    newProgram = newProgram & 0x200; //00X00001000
    newProgram = instructionRegister | newProgram; //11001 00001000000

    //avoid duplication from existing program code
    for(i = 0; i < 8; i++){
      if(newProgram == program[i])
        exist = 1;
    }
    if(exist !=1)
      program[c] = newProgram;
    else
      program[c] = 0b1000000000000000;
  }
}

void getAddress()
{
  m=1;
   for(c=0;c<8;c++)
   {
      if(digitalRead(c)==1)
        address=(address|m); //0-255
      m=m*2;
   }
  
}
void sendData(){
    data=program[address];
     m=1;
 for(c=8;c<24;c++){
  if((data&m)==0)
     digitalWrite(c,0);
  else 
     digitalWrite(c,1);

  m=m*2;
 }
 }


void loop() {
  // put your main code here, to run repeatedly:
    getAddress();
    sendData();
}
