#pragma once

#ifndef _SR04_H
#define _SR04_H

class SR04 {
public:
	static const unsigned char MEASURE_INTERVAL;
	SR04( const unsigned char trig, const unsigned char echo );
	void begin() const;
	double read() const;
	double readUnsafe() const;
	static void calibrate( double temp );
private:
	const unsigned char TRIG_, ECHO_;
	static double soundspeed_;
};

#endif	// _SR04_H
