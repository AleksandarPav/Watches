#pragma once

#include "PAccessory.h"

class AClasp : public PAccessory {

public:
	// constructor calling PAccessory constructor, which initializes the name and the basic price
	AClasp(string const& name, double price) : PAccessory("clasp of " + name, price) {}

	virtual ~AClasp() {}


	// overriding a method for pomyporphic copy
	virtual unique_ptr<PAccessory> Copy() const override;

};