#include <math.h>
#include "tone.h"
#include "board.h"

#define NUM_STEPS (64)

//It is a 10 bit DAC.
#define MAX_DAC_CODE (0x400)
#define PI (3.1415927)

wavetype toneType = SINE;
int sample;
int step;
int period;
int period_count=0;
int sine_table[NUM_STEPS];

/**
 * @brief initialize sinewave lookuptable, to avoid computing sin()
 * on every function call, when generating samples
 * */
void sinewave_init (void)
{
	int n;

	for (n = 0; n < NUM_STEPS; n++)
	{
		sine_table[n] =(int) ((MAX_DAC_CODE) * (1 + sin(n * 2 * PI / NUM_STEPS))/2);
	}
}

void tone_init (void)
{
	/* Setup DAC pins for pin 0.26 -AOUT, P18 on the LPC4088 QSB
	 * see section 7.3 in UM10562 for details, table 85 & 86  */
	Chip_IOCON_PinMuxSet(LPC_IOCON, DAC18PORT, DAC18PIN, (IOCON_FUNC2 | IOCON_DAC_EN ));

	Chip_DAC_Init (LPC_DAC);

	sinewave_init ();
}


void set_tone (int period_us, wavetype wave)
{
	period=period_us;
	period_count = 0;
	step = 0;
	toneType = wave;
}

void playNextSample (void)
{
	//Delay routine so we can change the speed
	period_count++;
	if(period_count <= period){
		return;
	}

	step++;
	if (step >= NUM_STEPS)
	{
		step = 0;
	}
	/* what to play */
	switch (toneType)
	{
		case SINE:
			sample = sine_table[step];
			break;
		case SQUARE:
			sample = step < NUM_STEPS / 2 ? 0 : MAX_DAC_CODE;
			break;
		case RAMP:
			sample = (step * MAX_DAC_CODE) / NUM_STEPS;
			break;
		case SAW:
			sample = step < NUM_STEPS / 2 ? (step * MAX_DAC_CODE) / (NUM_STEPS/2) : MAX_DAC_CODE -((step * MAX_DAC_CODE) / (NUM_STEPS/2));
			break;
	}

	Chip_DAC_UpdateValue (LPC_DAC, sample);

}
