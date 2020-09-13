#include "MDigital.h"

void MDigital::DisplayType(ostream& os) const
{
	os << "digital";
}

void MDigital::DisplayTime(ostream& os) const
{
	PMechanism::DisplayTime(os);
	os << ", " << AlarmClock;
}

unique_ptr<PMechanism> MDigital::Copy() const
{
	return unique_ptr<PMechanism>(new MDigital(*this));
}