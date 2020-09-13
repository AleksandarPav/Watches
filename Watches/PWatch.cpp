#include "PWatch.h"

// add ptr to accessory to the existing vector of ptrs to accessories, but first convert it to smart ptr
void PWatch::operator+=(PAccessory* pAccessory)
{
	Accessories.push_back(unique_ptr<PAccessory>(pAccessory));
}

// calculate the total price of the watch as the sum of its accessories
double PWatch::Price() const
{
	// initialize total price as the basic price from the Product
	double TotalPrice(Product::Price());

	// because of unique ptrs, iterator has to be a reference (a copy of unique ptrs can't be made)
	for (auto const& pAccessory : Accessories)
		TotalPrice += pAccessory->Price();

	return TotalPrice;
}

// watch is displayed in a way that it shows which accessories it has and then the total price is shown
void PWatch::Display(ostream& os) const
{
	os << "The watch is composed of:" << endl;

	for (auto const& pAccessory : Accessories)
		os << " - " << *pAccessory << endl;

	os << "Total price of the watch: " << Price() << endl;
}