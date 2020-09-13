#include "Product.h"

double Product::Price() const
{
	return BasePrice;
}

// operator<< itself has the same behaviour for all the products, but Display() will differ;
// specific Product's function is called, which will be different for every kind of product
ostream& operator<<(ostream& os, Product const& Product)
{
	Product.Display(os);
	return os;
}

// default display for a Product is displaying return value of Price() function;
// return value of Price() function will differ depending on the type of Product
void Product::Display(ostream& os) const
{
	os << Price();
}

// pure virtual, but it has to have some body
Product::~Product()
{

}