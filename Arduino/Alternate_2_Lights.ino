//keep light on after pressed

const int LED1 = 13;
const int LED2 = 10;
const int BUTTON = 7;

int val = 0;       //LED Pin
int old_val = 0;   //previous value of val
int state = 0;     //0=off 1=on

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  val = digitalRead(BUTTON);
  
  if((val == HIGH) && (old_val == LOW))
  {
    state = 1 - state;
    delay(10);
  }
  
  old_val = val;
  
  if(state == 1)
  {
    digitalWrite(LED1, HIGH);    //turn on LED if state = 1
    digitalWrite(LED2, LOW);
  }
  if(state == 0)
  {
    digitalWrite(LED1, LOW);     //turn off LED if state = 0
    digitalWrite(LED2, HIGH);
  }
}
