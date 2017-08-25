#include <StepperDriver.h>

StepperDriver stepper( 8, 7, 10 );	// STEP, DIR, EN or CLK, CW, EN

void setup() {
	stepper.begin();
};

void loop() {
	stepper.on();
	delay( 1000 );

	stepper.step( 1000 );
	delay( 1000 );

	stepper.step( -1000, 100 );
	delay( 1000 );

	stepper.speed( 1000, 500 );
	delay( 1000 );

	stepper.speed( -1000 );
	delay( 500 );

	stepper.off();
	delay( 500 );
};
