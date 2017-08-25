#include <math.h>
#include "StepperDriver.h"

StepperDriver::StepperDriver(
	const unsigned char step,
	const unsigned char dir,
	const unsigned char en
): STEP_( step ), DIR_( dir ), EN_( en ) { };

void StepperDriver::begin() const {
	pinMode( this->STEP_, OUTPUT );
	pinMode( this->DIR_, OUTPUT );
	pinMode( this->EN_, OUTPUT );

	digitalWrite( this->EN_, LOW );
	digitalWrite( this->DIR_, HIGH );
	noTone( this->STEP_ );
};

void StepperDriver::step( const signed int steps, unsigned int stepsPerSec ) const {
	unsigned long period = 1e6 / 2 / stepsPerSec;

	digitalWrite( this->EN_, LOW );
	digitalWrite( this->DIR_, steps >= 0 );
	noTone( this->STEP_ );

	for ( unsigned int i = 0; i < abs( steps ); i += 1 ) {
		digitalWrite( this->STEP_, HIGH );
		delayMicroseconds( period );
		digitalWrite( this->STEP_, LOW );
		delayMicroseconds( period );
	}
};

void StepperDriver::speed( const signed int stepsPerSec, unsigned long milliseconds ) const {
	digitalWrite( this->EN_, LOW );
	digitalWrite( this->DIR_, stepsPerSec >= 0 );

	if ( 0 == stepsPerSec ) {
		noTone( this->STEP_ );
	} else {
		tone( this->STEP_, abs( stepsPerSec ), milliseconds );
	}
};
