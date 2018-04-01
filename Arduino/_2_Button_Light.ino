const int LED1 = 13;
const int LED2 = 10;
const int BUTTON = 7;

int val = 0;

void setup()
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop()
{
  val = digitalRead(BUTTON);
  
  if(val==HIGH)                //check for button press
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
  }
  else
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  }
}
