#include "HBridge.h"

HBridge::HBridge(
    const unsigned char forward,
    const unsigned char inverse,
    const unsigned char enable
): FORWARD_( forward ), INVERSE_( inverse ), ENABLE_( enable ) { }

void HBridge::begin() const {
    pinMode( this->FORWARD_, OUTPUT );
    pinMode( this->INVERSE_, OUTPUT );
    pinMode( this->ENABLE_, OUTPUT );
};

void HBridge::write( enum direction_t direction ) const {
    if ( direction < 0 ) {
		digitalWrite( this->FORWARD_, LOW );
		digitalWrite( this->INVERSE_, HIGH );
    } else {
		digitalWrite( this->FORWARD_, HIGH );
		digitalWrite( this->INVERSE_, LOW );
    }

    digitalWrite( this->ENABLE_, 0 != direction );
};

void HBridge::pwmWrite( signed int dutyCycles ) const {
    if ( dutyCycles < 0 ) {
		dutyCycles = -dutyCycles;

		digitalWrite( this->FORWARD_, LOW );
		digitalWrite( this->INVERSE_, HIGH );
    } else {
		digitalWrite( this->FORWARD_, HIGH );
		digitalWrite( this->INVERSE_, LOW );
    }

    analogWrite( this->ENABLE_, dutyCycles );
};

HBridge_Legacy::HBridge_Legacy(
    const unsigned char forward,
    const unsigned char inverse
): FORWARD_( forward ), INVERSE_( inverse ) { }

void HBridge_Legacy::begin() const {
    pinMode( this->FORWARD_, OUTPUT );
    pinMode( this->INVERSE_, OUTPUT );
};

void HBridge_Legacy::write( enum direction_t direction ) const {
    if ( direction < 0 ) {
		digitalWrite( this->FORWARD_, LOW );
		digitalWrite( this->INVERSE_, 0 != direction );
    } else {
		digitalWrite( this->FORWARD_, 0 != direction );
		digitalWrite( this->INVERSE_, LOW );
    }
};

void HBridge_Legacy::pwmWrite( signed int dutyCycles ) const {
    if ( dutyCycles < 0 ) {
		digitalWrite( this->FORWARD_, LOW );
		analogWrite( this->INVERSE_, -dutyCycles );
    } else {
		digitalWrite( this->FORWARD_, dutyCycles );
		analogWrite( this->INVERSE_, LOW) ;
    }
};
