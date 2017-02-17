#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <math.h>
#include "SR04.h"

double SR04::soundspeed_ = 343.2;

SR04::SR04():
	isAttached_( false ), trig_( -1 ), echo_( -1 ) { };

bool SR04::attach( int trig, int echo ) {
	this->isAttached_ = true;
	this->trig_ = trig;
	this->echo_ = echo;

	pinMode( this->trig_, OUTPUT );
	pinMode( this->echo_, INPUT );

	return true;
};

void SR04::detach() {
	this->isAttached_ = false;
	this->trig_ = -1;
	this->echo_ = -1;
};

double SR04::read() const {
	if ( this->attached() ) {
		digitalWrite( this->trig_, LOW );
		delayMicroseconds( 1 );
		digitalWrite( this->trig_, HIGH );
		delayMicroseconds( 10 );
		digitalWrite( this->trig_, LOW );						// trigger a measure by a 10us pulse

		double t_us = pulseIn( this->echo_, HIGH );
		double d_mm = t_us * 1e-6 * 340 * 1e3 / 2;				// calculate distance

		return d_mm;
	} else {
		return -1;
	}
};

bool SR04::attached() const {
	return this->isAttached_;
};

void SR04::calibrate( double temp ) {
	soundspeed_ = 20.05 * sqrt( temp + 273.15 );
};