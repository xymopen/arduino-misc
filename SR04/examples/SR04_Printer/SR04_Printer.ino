#include "SR04.h"

SR04 sr04( 2, 3 );	// Trig, Echo

void setup() {
	sr04.begin();
	Serial.begin( 9600 );
};

void loop() {
	Serial.print( sr04.read() );
	Serial.println( "mm" );
};
