/* 1.0.0 VERSION */

#include "dddhtxx.h"

DDDhtxx::DDDhtxx(int led, int pin)
{
	this->_led = led;
	this->_dht = DHT(pin, DHT11);
}

void DDDhtxx::beginSensor()
{
	this->_dht.begin();
}

DDDHTXXVal DDDhtxx::getValue()
{

	DDDHTXXVal ret;

	float h = this->_dht.readHumidity();
	float t = this->_dht.readTemperature();
	float f = this->_dht.readTemperature(true);

	if (!isnan(h) && !isnan(t) && !isnan(f))
	{
		float hif = this->_dht.computeHeatIndex(f, h);
		float hic = this->_dht.computeHeatIndex(t, h, false);

		ret.humidity = h;
		ret.tempC = t;
		ret.tempF = f;
		ret.heatIndexC = hic;
		ret.heatIndexF = hif;

		ret.success = true;
	}
	else
	{

		ret.success = false;
		ret.errorMsg = "Failed to read from DHT sensor!";
	}

	return ret;
}