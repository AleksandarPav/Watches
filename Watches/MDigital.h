#pragma once

#include "PMechanism.h"

// digital mechanisms are mechanisms;
// inheritance is virtual so that when MDouble inherits both from MAnalogue and MDigital,
// it doesn't have double properties
class MDigital : virtual public PMechanism {

private:
	string AlarmClock;

public:
	// constructor calss the superclass's constructor and initializes the alarm clock
	MDigital(double basic_price, string time, string alarm_clock) : PMechanism(basic_price, time), AlarmClock(alarm_clock) {}
	// constructor in case the time parameter isn't provided
	MDigital(double basic_price, string alarm_clock) : PMechanism(basic_price), AlarmClock(alarm_clock) {}


	// overriding a method for polymorphic copy
	virtual unique_ptr<PMechanism> Copy() const override;

protected:
	// display "digital"
	virtual void DisplayType(ostream&) const override;

	// display time from the superclass and AlarmClock
	virtual void DisplayTime(ostream&) const override;
};