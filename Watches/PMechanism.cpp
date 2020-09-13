#include "PMechanism.h"

// display type, time and price of the mechanism
void PMechanism::Display(ostream& os) const
{
	os << "Mechanism: ";
	DisplayType(os);
	os << " (";
	DisplayTime(os);
	os << "), price: ";
	Product::Display(os);
}

void PMechanism::DisplayTime(ostream& os) const
{
	os << Time;
}