#include "ABody.h"

unique_ptr<PAccessory> ABody::Copy() const
{
	return unique_ptr<PAccessory>(new ABody(*this));
}