#pragma once

#ifndef _SR04_H
#define _SR04_H

class SR04 {
public:
	SR04();
	bool attach( int trig, int echo );
	void detach();
	double read() const;
	bool attached() const;
	static void calibrate( double temp );
private:
	bool isAttached_;
	int trig_, echo_;
	static double soundspeed_;
};

#endif	// _SR04_H
