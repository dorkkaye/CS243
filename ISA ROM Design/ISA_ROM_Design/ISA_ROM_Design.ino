int address;
long instructions[256];
long temp;
long value;
int i;

void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
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

  instructions[0] = 0x9000;
  instructions[1] = 0x9201;
  instructions[2] = 0x9405;
  instructions[3] = 0xE401;
  instructions[4] = 0xEC09;
  instructions[5] = 0xB807;
  instructions[6] = 0xB003;
  instructions[7] = 0;

  address = 0;
  temp = instructions[7];
  value = 0;
  i = 0;
}

void loop() 
{
  // put your main code here, to run repeatedly:

  address = digitalRead(0) * 1 + digitalRead(1) * 2 + digitalRead(2) * 4 + digitalRead(3) * 8 + digitalRead(4) * 16 + digitalRead(5) * 32 + digitalRead(6) * 64  + digitalRead(7) * 128 ;

  temp = instructions[address];

  for(i = 8; i <= 23; i++)
  {
    value = temp % 2;
    digitalWrite(i,value);
    temp = temp / 2;
  } 
}
