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
	const unsigned char STEP_, DIR_;
public:
	StepperDriver(
		const unsigned char step,
		const unsigned char dir
	);
	void begin() const;
	void step( const signed int steps, unsigned int stepsPerSec = 500 ) const;
	void speed( const signed int stepsPerSec, unsigned long milliseconds = 0 ) const;
};

#endif	// _STEPPER_DRIVER_H
