int address=0, data = 0;
int c = 0, m = 0;
int program []={0b1001000000000000,
         0b1001001000000001,
         0b1001010000000101,
         0b1110000000000001,
         0b1110110000001001,
         0b1011100000000111,
         0b1011000000000011,
         0b1011000000000111};

void setup() 
{
  // put your setup code here, to run once:
    pinMode (0, INPUT);
    pinMode (1, INPUT);
    pinMode (2, INPUT);
    pinMode (3, INPUT);
    pinMode (4, INPUT);
    pinMode (5, INPUT);
    pinMode (6, INPUT);
    pinMode (7, INPUT);
    
//set data bus
    pinMode (8, OUTPUT);
    pinMode (9, OUTPUT);
    pinMode (10, OUTPUT);
    pinMode (11, OUTPUT);
    pinMode (12, OUTPUT);
    pinMode (13, OUTPUT);
    pinMode (14, OUTPUT);
    pinMode (15, OUTPUT);
    pinMode (16, OUTPUT);
    pinMode (17, OUTPUT);
    pinMode (18, OUTPUT);
    pinMode (19, OUTPUT);
    pinMode (20, OUTPUT);
    pinMode (21, OUTPUT);
    pinMode (22, OUTPUT);
    pinMode (23, OUTPUT);
}

void getAddress()
{
  m=1;
  
  for (c=0;c<8;c++)
  {
    if (digitalRead(c) == 1)
    address= (address|m);
    m=m*2;
  }
}

void sendData()
{
  data=program[address];
  m=1;

  for (c=8; c<24; c++)
  {
    if ((data&m) == 0)
      digitalWrite (c,0);
    else
      digitalWrite (c,1);

     m=m*2;
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
  getAddress();
  sendData();

}
