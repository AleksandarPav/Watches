#pragma once

#include <string>

#include "Product.h"

// accessories are products
class PAccessory : public Product {

private:
	// accessory is characterized by its name
	const string Name;

public:
	// call the construcotr of the base class and initialize the name
	PAccessory(const string& name, double base_price) : Product(base_price), Name(name) {}

	// there will be classes inheriting from Accessory, so destructor needs to be virtual
	virtual ~PAccessory() {}


	// Display() is overriden from Product
	virtual void Display(ostream&) const override;

	// make a polymorphic copy;
	// at this level of PAccessory, it still can't be defined
	virtual unique_ptr<PAccessory> Copy() const = 0;

};