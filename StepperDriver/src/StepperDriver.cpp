#include <math.h>
#include "StepperDriver.h"

StepperDriver::StepperDriver(
	const unsigned char STEP,
	const unsigned char DIR,
	const unsigned char EN
): STEP_( STEP ), DIR_( DIR ), EN_( EN ) { };

void StepperDriver::begin() const {
	pinMode( this->STEP_, OUTPUT );
	pinMode( this->DIR_, OUTPUT );
	pinMode( this->EN_, OUTPUT );

	digitalWrite( this->EN_, LOW );
	digitalWrite( this->DIR_, HIGH );
	noTone( this->STEP_ );
};

void StepperDriver::write( const signed int frequency ) const {
	digitalWrite( this->EN_, LOW );
	digitalWrite( this->DIR_, frequency >= 0 );
	
	if ( 0 == frequency ) {
		noTone( this->STEP_ );
	} else {
		tone( this->STEP_, abs( frequency ) );
	}
};

void StepperDriver::write( const signed int frequency, unsigned long duration ) const {
	digitalWrite( this->EN_, LOW );
	digitalWrite( this->DIR_, frequency >= 0 );
	
	if ( 0 == frequency ) {
		noTone( this->STEP_ );
	} else {
		tone( this->STEP_, abs( frequency ), duration );
	}
};
