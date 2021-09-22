/* 1.0.0 VERSION */

#ifndef dddhtxx_h
#define dddhtxx_h

#include <DHT.h>

struct DDDHTXXVal
{

	float humidity = 0.0;
	float tempC = 0.0;
	float tempF = 0.0;
	float heatIndexC = 0.0;
	float heatIndexF = 0.0;
	bool success;
	const char *errorMsg;
};

class DDDhtxx
{

private:
	DHT _dht = DHT(0, DHT11);
	int _led;

public:
	DDDhtxx(int, int);
	void beginSensor();
	DDDHTXXVal getValue();
};

#endif