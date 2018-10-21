// HBridge.h

#ifndef _HBRIDGE_h
#define _HBRIDGE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

enum direction_t {
	CW = 1,
	STOP = 0,
	CCW = -1,
};

class HBridge {
	 private:
		const unsigned char forward;
		const unsigned char inverse;
		const unsigned char ENABLE;

	 public:
		HBridge(
			const unsigned char in1,
			const unsigned char in2,
			const unsigned char ena
		);
		void begin() const;
		void write( enum direction_t direction ) const;
		void pwmWrite( signed int dutyCycles ) const;
};

class HBridge_Legacy {
	 private:
		const unsigned char forward;
		const unsigned char inverse;

	 public:
		HBridge_Legacy(
			const unsigned char in1,
			const unsigned char in2
		);
		void begin() const;
		void write( enum direction_t direction ) const;
		void pwmWrite( signed int dutyCycles ) const;
};

#endif  // _HBRIDGE_h
