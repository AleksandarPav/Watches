#include "MAnalogue.h"

void MAnalogue::DisplayType(ostream& os) const
{
	os << "analogue";
}

void MAnalogue::DisplayTime(ostream& os) const
{
	PMechanism::DisplayTime(os);
	os << ", " << Date;
}

unique_ptr<PMechanism> MAnalogue::Copy() const
{
	return unique_ptr<PMechanism>(new MAnalogue(*this));
}