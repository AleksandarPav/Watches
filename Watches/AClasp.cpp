#include "AClasp.h"

unique_ptr<PAccessory> AClasp::Copy() const
{
	return unique_ptr<PAccessory>(new AClasp(*this));
}