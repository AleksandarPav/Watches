#include "AGlass.h"

unique_ptr<PAccessory> AGlass::Copy() const
{
	return unique_ptr<PAccessory>(new AGlass(*this));
}