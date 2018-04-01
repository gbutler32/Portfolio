//keep light on after pressed

const int LED1 = 13;
const int LED2 = 10;
const int LED3 = 5;
const int LED4 = 3;

const int BUTTON = 7;

int val = 0;       //LED Pin
int old_val = 0;   //previous value of val
int state = 0;     //0=off 1=on

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  val = digitalRead(BUTTON);
  
  if((val == HIGH) && (old_val == LOW))
  {
    if(state+1 == 4)
    {
      state = 0;
    }
    else
    {
      state++;
    }
    delay(10);
  }
    
   old_val = val;
    
  if(state == 3)                //light 1 on
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(state == 2)                //light 2 on
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(state == 1)                //light 3 on
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }
  if(state == 0)                //light 4 on
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  }
}
