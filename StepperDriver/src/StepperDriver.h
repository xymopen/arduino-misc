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
		const unsigned char STEP,
		const unsigned char DIR,
		const unsigned char EN
	);
	void begin() const;
	void on() const;
	void off() const;
	void write( const signed int frequency ) const;
	void write( const signed int frequency, unsigned long duration ) const;
};

inline void StepperDriver::on() const {
	digitalWrite( this->EN_, LOW );
};

inline void StepperDriver::off() const {
	digitalWrite( this->EN_, HIGH );
};

#endif	// _STEPPER_DRIVER_H