#include <StepperDriver.h>

StepperDriver stepper( 8, 7, 10 );	// STEP, DIR, EN or CLK, CW, EN

void setup() {
	stepper.begin();
};

void loop() {
	stepper.write( 1000, 500 );
	delay( 1000 );
	stepper.write( -1000 );
	delay( 500 );
	stepper.off();
	delay( 500 );
};
