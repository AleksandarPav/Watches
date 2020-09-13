#pragma once

#include "PAccessory.h"

class ABody : public PAccessory {

public:
	// constructor calling PAccessory constructor, which initializes the name and the basic price
	ABody(string const& name, double price) : PAccessory("body of " + name, price) {}

	virtual ~ABody() {}


	// overriding a method for polymorphic copy
	virtual unique_ptr<PAccessory> Copy() const override;
};