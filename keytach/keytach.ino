#include <Keyboard.h>

const int dataIN = 10;
const int N = 3; 

unsigned long prevmicros; 
unsigned long duration; 

int setrpm;
int rpm; 

boolean currentstate; 
boolean prevstate; 

void setup()
{
  pinMode(dataIN,INPUT);
  prevmicros = 0;
  prevstate = LOW; 
}

void loop()
{
  currentstate = digitalRead(dataIN); 
  if( prevstate != currentstate) 
  {
    if( currentstate == HIGH ) 
    {
      duration = (micros() - prevmicros) * N; 
      prevmicros = micros(); 
      rpm = (60000000/duration); 
      Keyboard.println(rpm);
      Keyboard.println('\n');
    }
  }
  prevstate = currentstate; 
}
