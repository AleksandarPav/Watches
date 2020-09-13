#pragma once

#include "PAccessory.h"

class AGlass : public PAccessory {

public:
	// constructor calling PAccessory constructor, which initializes the name and the basic price
	AGlass(string const& name, double price) : PAccessory("glass of " + name, price) {}

	virtual ~AGlass() {}


	// overriding a method for pomyporphic copy
	virtual unique_ptr<PAccessory> Copy() const override;
};