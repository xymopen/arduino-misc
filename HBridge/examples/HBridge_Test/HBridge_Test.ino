#include <HBridge.h>

HBridge a( 3, 4, 5 );	// IN1, IN2, ENA or IN3, IN4, ENB, ENA or ENB must be PWM output

void setup() {
	a.begin();
};

void loop() {
	a.write( INVERSE );
	delay( 1000 );

	a.write( STOP );
	delay( 1000 );

	a.write( FORWARD );
	delay( 1000 );

	a.pwmWrite( 127 );
	delay( 1000 );
	
	a.pwmWrite( 0 );
	delay( 1000 );
		
	a.pwmWrite( -127 );
	delay( 1000 );
};
