//keep light on after pressed

const int LED3 = 13;
const int LED2 = 10;
const int LED1 = 5;
const int LED0 = 3;

const int BUTTON = 7;

int val = 0;       //LED Pin
int old_val = 0;   //previous value of val
int state = 0;     //0=off 1=on
int test = 10;
boolean out[4]={false};

void setup()
{
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  for(int a=3;a != -1;a--)
  {
    if((test - (pow(2,a))) >= 0)
    {
      test =(test - (pow(2,a)));
      out[a]=true;
    }
  }
  
  if(out[0]==true)                //light 1 on
  {
    digitalWrite(LED0, HIGH);
  }
  if(out[1]==true)                //light 2 on
  {
    digitalWrite(LED1, HIGH);
  }
  if(out[2]==true)                //light 3 on
  {
    digitalWrite(LED2, HIGH);
  }
  if(out[3]==true)                //light 4 on
  {
    digitalWrite(LED3, HIGH);
  }
}
