const int LED = 13;      //pin number

void setup()
{
  pinMode(LED,OUTPUT);    //sets pin as output
}

void loop()
{
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
