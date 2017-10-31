#include "board.h"
#include "us_timer.h"
#include "tone.h"

/**
 * @brief	Main routine for DAC function/tone generator example
 * @return	Nothing
 */
int main (void)
{

	SystemCoreClockUpdate ();
	Board_Init ();


	tone_init();
	us_timer_init();

	set_tone(10,SINE);

	/* Do nothing, yet, but wait for interrupt */
	while (1)
	{
	}

	/* wont go here */
	return (0);
}
