int led = 8;  //Number of LEDs

void setup()
{
   for(int i = 0; i < led; i++) 
    pinMode(i,OUTPUT);
}

void loop()
{
  //i = blue LED, j = green
    for(int i = 0, j = 4; i < 4, j <= led; i++, j++)
    {
        digitalWrite(i,LOW);
        digitalWrite(j,LOW);
        delay(100);
        digitalWrite(i,HIGH);
        digitalWrite(j,HIGH);
     }
} 
