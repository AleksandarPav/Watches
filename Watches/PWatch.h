#pragma once

#include "Product.h"
#include "PMechanism.h"
#include "PAccessory.h"

#include <vector>
#include <memory>
#include <utility>

using namespace std;

// watches are products
class PWatch : public Product {

private:
	// Watch has mechanism (analogue, digital or mixed) and accessories (bracelet, clasp, body, glass);
	// because of polymorphism, (smart) pointers are used
	unique_ptr<PMechanism> Mechanism;
	vector<unique_ptr<PAccessory>> Accessories;

public:
	// constructor initializes ptr to PMechanism
	PWatch(PMechanism* pMech) : Mechanism(unique_ptr<PMechanism>(pMech)) {}

	virtual ~PWatch() {}

	// shallow copy (beside from the fact it shouldn't be made because of the ptrs) wouldn't even be possible to make,
	// because unique_ptrs are used (can't have more than one ptr pointing to the same location);
	// copy constructor must begin with the calls to copy constructors of all the superclasses
	// (otherwise, default default constructor of the superclass is called, which in undesirable behaviour)
	PWatch(PWatch const& OtherWatch) : Product(OtherWatch), Mechanism(OtherWatch.Mechanism->Copy())
	{
		for (auto const& pAccessory : OtherWatch.Accessories)
			Accessories.push_back(pAccessory->Copy());
	}

	// when there's copy constructor defining, there should be operator= overloading also;
	// swap Mechanism and Accessories from OtherWatch and this watch
	PWatch& operator=(PWatch OtherWatch)
	{
		swap(Mechanism, OtherWatch.Mechanism);
		swap(Accessories, OtherWatch.Accessories);

		return *this;
	}

	// adding accessories to the vector, via pointer
	void operator+=(PAccessory*);

	// overriding Product's function Price(), which will calculate the price of the watch
	virtual double Price() const override;
	
	// overriding Product's function Display(), which will determine the format for displaying the watch
	virtual void Display(ostream&) const override;
};