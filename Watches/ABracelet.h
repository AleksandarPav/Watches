#pragma once

#include "PAccessory.h"

#include <string>

class ABracelet : public PAccessory {

public:
	// constructor calling PAccessory constructor, which initializes the name and the basic price
	ABracelet(const string& name, double price) : PAccessory("bracelet of " + name, price) {}

	virtual ~ABracelet() {}


	// overriding a method for pomyporphic copy
	virtual unique_ptr<PAccessory> Copy() const override;

};