int led = 8;  //Number of LEDs

void setup()
{
   for(int i = 0; i < led; i++) 
    pinMode(i,OUTPUT);
}

void loop()
{
  //i = blue LED, j = green
  if(digitalRead(8) == 1)
  {
    for(int i = 0, j = 4; i < 4, j <= led; i++, j++)
    {
        digitalWrite(i,LOW);
        digitalWrite(j,LOW);
        delay(500);
        digitalWrite(i,HIGH);
        digitalWrite(j,HIGH);
     }
  } 
  else if(digitalRead(9) == 1)
  {
    for(int i = 0; i <= led; i++)
    {
      digitalWrite(i,LOW);
      delay(500);
      digitalWrite(i,HIGH);
    }
  }
  else if(digitalRead(10) == 1)
  {
    for(int i = led; i >= 0; i--) 
    {
      digitalWrite(i,HIGH);
      delay(500);
      digitalWrite(i,LOW);
    }
  }
} 
