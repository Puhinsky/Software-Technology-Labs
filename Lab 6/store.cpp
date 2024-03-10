#include "store.h"

using namespace::std;

product::product(const std::string& name, double price, size_t quantity)
{
	_name = name;
	_price = price;
	_quantity = quantity;
}

void product::print(std::ostream& os) const
{
	os << "Product: " << _name << ", Price: $" << _price << ", Quantity: " << _quantity << " units" << endl;
}

bool make_promotion(std::shared_ptr<product>& p1, std::shared_ptr<product>& p2, double percent)
{
	if (!p1 || !p2)
		return false;

	p1->_promotion_pair = p2;
	p2->_promotion_pair = p1;

	cout << "Promotion " << percent << "% created: " << p1->_name << " and " << p2->_name << endl;

	return true;
}

shared_ptr<product> store::add(std::string name, double price, size_t quantity)
{
	auto new_product = std::make_shared<product>(name, price, quantity);
	_products.push_back(new_product);

	return new_product;
}

void store::print(std::ostream& os)
{
	for (const auto& product_p : _products)
	{
		product_p->print(os);
	}
}

