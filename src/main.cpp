#include "../lib/include/led.h"

using namespace LED;

Led* led;

int main()
{
	led = new Led(portA, 1, ON);
  while (1)
    {
    }
}
