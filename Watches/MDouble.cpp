#include "MDouble.h"

void MDouble::DisplayType(ostream& os) const
{
	os << "double";
}

void MDouble::DisplayTime(ostream& os) const
{
	os << "analogue display: ";
	MAnalogue::DisplayTime(os);
	os << "; digital display: ";
	MDigital::DisplayTime(os);
}

unique_ptr<PMechanism> MDouble::Copy() const
{
	return unique_ptr<PMechanism>(new MDouble(*this));
}