#pragma once

#include <iostream>
using namespace std;

class Product {

private:
	// basic price of the product
	const double BasePrice;

public:
	// constructor setting the BasePrice (0 by default)
	Product(double Value = 0.) : BasePrice(Value) {}

	// since there will be inheritance, destructor should be virtual;
	// it is pure virtual, because Product should be abstract class
	virtual ~Product() = 0;


	// price will vary depending on if it's a bracelet, clasp, glass or body
	virtual double Price() const;

	// display will be polymorphic
	virtual void Display(ostream& os) const;
};

// overloading operator "<<" for display
ostream& operator<<(ostream&, Product const&);