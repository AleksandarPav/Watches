#pragma once

#include <string>

#include "Product.h"

// mechanisms are products
class PMechanism : public Product {

private:
	// every mechanism will have time
	string Time;

public:
	// constructor calls Product's constructor to set a basic price and initializes Time (12h by default)
	PMechanism(double base_price, string time = "12:00") : Product(base_price), Time(time) {}
	// since PMechanism is a virtual class, all of its subclasses must explicitly call its constructor


	// overriding Display from Product;
	// disabled further overriding (final), only the methods it uses will be overriden (DisplayTime and DisplayType)
	virtual void Display(ostream&) const override final;

	// make a polymorphic copy;
	// at this level of PMechanism, it still can't be defined
	virtual unique_ptr<PMechanism> Copy() const = 0;

protected:
	// display time;
	// only the sublclasses will need this method (in their Display methods), that's why it's protected
	virtual void DisplayTime(ostream&) const;

private:
	// displaying the type of the mechanism, which will be defined in inherited classes
	virtual void DisplayType(ostream&) const = 0;


};