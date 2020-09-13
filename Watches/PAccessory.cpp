#include "PAccessory.h"

// display name of the accessory and then call Display() of the Product (which will display the price)
void PAccessory::Display(ostream& os) const
{
	os << Name << " costs ";
	Product::Display(os);
}