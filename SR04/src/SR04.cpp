#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <math.h>
#include "SR04.h"

const unsigned char SR04::MEASURE_INTERVAL = 60;
double SR04::soundspeed_ = 343.2;

SR04::SR04( const unsigned char trig, const unsigned char echo ):
	TRIG_( trig ), ECHO_( echo ) { };

void SR04::begin() const {
	pinMode( this->TRIG_, OUTPUT );
	pinMode( this->ECHO_, INPUT );
};

double SR04::read() const {
	delay( MEASURE_INTERVAL );									// we suggest to use over 60ms measurement cycle
																// in order to prevent trigger signal to the echo signal. 
	return readUnsafe();
};

double SR04::readUnsafe() const {
	digitalWrite( this->TRIG_, LOW );
	delayMicroseconds( 1 );
	digitalWrite( this->TRIG_, HIGH );
	delayMicroseconds( 10 );
	digitalWrite( this->TRIG_, LOW );						//  supply a short 10uS pulse to the trigger input to start the ranging

	double t_us = pulseIn( this->ECHO_, HIGH );
	double d_mm = t_us * 1e-6 * soundspeed_ * 1e3 / 2;		// calculate distance

	return d_mm;
};

void SR04::calibrate( double celsius  ) {
	soundspeed_ = 20.05 * sqrt( celsius + 273.15 );
};
