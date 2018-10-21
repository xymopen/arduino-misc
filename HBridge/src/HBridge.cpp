#include "HBridge.h"

HBridge::HBridge(
	const unsigned char in1,
	const unsigned char in2,
	const unsigned char ena
) : forward( in1 ), inverse( in2 ), ENABLE( ena ) {}

void HBridge::begin() const {
	pinMode( this->forward, OUTPUT );
	pinMode( this->inverse, OUTPUT );
	pinMode( this->ENABLE, OUTPUT );
};

void HBridge::write( enum direction_t direction ) const {
	if ( direction < 0 ) {
		digitalWrite( this->forward, LOW );
		digitalWrite( this->inverse, HIGH );
	} else {
		digitalWrite( this->forward, HIGH );
		digitalWrite( this->inverse, LOW );
	}

	digitalWrite( this->ENABLE, 0 != direction );
};

void HBridge::pwmWrite( signed int dutyCycles ) const {
	if ( dutyCycles < 0 ) {
		dutyCycles = -dutyCycles;

		digitalWrite( this->forward, LOW );
		digitalWrite( this->inverse, HIGH );
	} else {
		digitalWrite( this->forward, HIGH );
		digitalWrite( this->inverse, LOW );
	}

	analogWrite( this->ENABLE, dutyCycles );
};

HBridge_Legacy::HBridge_Legacy(
	const unsigned char in1,
	const unsigned char in2
) : forward( in1 ), inverse( in2 ) {}

void HBridge_Legacy::begin() const {
	pinMode( this->forward, OUTPUT );
	pinMode( this->inverse, OUTPUT );
};

void HBridge_Legacy::write( enum direction_t direction ) const {
	if ( direction < 0 ) {
		digitalWrite( this->forward, LOW );
		digitalWrite( this->inverse, 0 != direction );
	} else {
		digitalWrite( this->forward, 0 != direction );
		digitalWrite( this->inverse, LOW );
	}
};

void HBridge_Legacy::pwmWrite( signed int dutyCycles ) const {
	if ( dutyCycles < 0 ) {
		digitalWrite( this->forward, LOW );
		analogWrite( this->inverse, -dutyCycles );
	} else {
		digitalWrite( this->forward, dutyCycles );
		analogWrite( this->inverse, LOW );
	}
};
