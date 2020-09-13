#pragma once

#include "MAnalogue.h"
#include "MDigital.h"

// double mechanisms are both analogue and digital
class MDouble : public MAnalogue, public MDigital {

public:
	// since PMechanism is a virtual class, all of its subclasses must explicitly call its constructor
	MDouble(double basic_price, string time, int date, string alarm_clock) :
		PMechanism(basic_price, time), MAnalogue(basic_price, time, date), MDigital(basic_price, time, alarm_clock) {}
	// constructor in case the time parameter isn't provided
	MDouble(double basic_price, int date, string alarm_clock) :
		PMechanism(basic_price), MAnalogue(basic_price, date), MDigital(basic_price, alarm_clock) {}


	// overriding a method for polymorphic copy
	virtual unique_ptr<PMechanism> Copy() const override;

protected:
	// display "double"
	virtual void DisplayType(ostream&) const override;

	// call MAnalogue's DisplayTime and MDigital's DisplayTime
	virtual void DisplayTime(ostream&) const override;

};