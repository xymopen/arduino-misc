#pragma once

#ifndef _STEPPER_DRIVER_H
#define _STEPPER_DRIVER_H

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class StepperDriver {
private:
	const unsigned char STEP_, DIR_, EN_;
public:
	StepperDriver(
		const unsigned char step,
		const unsigned char dir,
		const unsigned char en
	);
	void begin() const;
	void on() const;
	void off() const;
	void step( const signed int steps, unsigned int stepsPerSec = 500 ) const;
	void speed( const signed int stepsPerSec, unsigned long milliseconds = 0 ) const;
};

inline void StepperDriver::on() const {
	digitalWrite( this->EN_, LOW );
};

inline void StepperDriver::off() const {
	digitalWrite( this->EN_, HIGH );
	digitalWrite( this->DIR_, HIGH );
	noTone( this->STEP_ );
};

#endif	// _STEPPER_DRIVER_H