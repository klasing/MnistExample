#pragma once

#include <iostream>
#include "WeatherPrediction.hpp"

using namespace std;
class MyWeatherPrediction : public WeatherPrediction {
public:
	virtual void setCurrentTempCelsius(int inTemp) {
		int fahrenheitTemp = convertCelsiusToFahrenheit(inTemp);
		setCurrentTemperatureFahrenheit(fahrenheitTemp);

	}
	virtual int getTomorrowTempCelsius() {
		int fahrenheitTemp = getTomorrowTempFahenheit();
		return convertFahrenheitToCelsius(fahrenheitTemp);
	}
	virtual void showResult() {
		cout << "-> Tomorrow's temperature will be " <<
			getTomorrowTempCelsius() << " degrees Celsius (" <<
			getTomorrowTempFahenheit() << " degrees Faherenheit)" << endl;
		cout << "-> Chance of rain is " << (getChanceOfRain() * 100) << " percent"
			<< endl;
		if (getChanceOfRain() > 0.5)
			cout << "Bring an umbrella!" << endl;

	}
	virtual string getTemperature() const {
		//return WeatherPrediction::getTemperature() + "\u2103F";
		// or Microsoft Visual C++ specific
		return __super::getTemperature() + "\u2103F";
	}
protected:
	static int convertCelsiusToFahrenheit(int inCelcius) {

	}
	static int convertFahrenheitToCelsius(int inFahrenheit) {

	}
};