// HBridge.h

#ifndef _HBRIDGE_h
#define _HBRIDGE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

enum direction_t {
	FORWARD = 1,
	STOP = 0,
	INVERSE = -1,
};

class HBridge {
	 private:
		const unsigned char FORWARD_;
		const unsigned char INVERSE_;
		const unsigned char ENABLE_;

	 public:
		HBridge(
			const unsigned char forward,
			const unsigned char inverse,
			const unsigned char enable
		);
		void begin() const;
		void write( enum direction_t direction ) const;
		void pwmWrite( signed int dutyCycles ) const;
};

class HBridge_Legacy {
	 private:
		const unsigned char FORWARD_;
		const unsigned char INVERSE_;

	 public:
		HBridge_Legacy(
			const unsigned char forward,
			const unsigned char inverse
		);
		void begin() const;
		void write( enum direction_t direction ) const;
		void pwmWrite( signed int dutyCycles ) const;
};

#endif  // _HBRIDGE_h