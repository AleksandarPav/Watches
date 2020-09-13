#include "ABracelet.h"

unique_ptr<PAccessory> ABracelet::Copy() const
{
	return unique_ptr<PAccessory>(new ABracelet(*this));
}