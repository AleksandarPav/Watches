#pragma once

#include "PMechanism.h"

// analogue mechanisms are mechanisms;
// inheritance is virtual so that when MDouble inherits both from MAnalogue and MDigital,
// it doesn't have double properties
class MAnalogue : virtual public PMechanism {

private:
	int Date;

public:
	// constructor calls the superclass constructor and initializes the date
	MAnalogue(double basic_price, string time, int date) : PMechanism(basic_price, time), Date(date) {}
	// constructor in case the time parameter isn't provided
	MAnalogue(double basic_price, int date) : PMechanism(basic_price), Date(date) {}


	// overriding a method for polymorphic copy
	virtual unique_ptr<PMechanism> Copy() const override;

protected:
	// display "analogue"
	virtual void DisplayType(ostream&) const override;

	// display time from the superclass and Date
	virtual void DisplayTime(ostream&) const override;
};