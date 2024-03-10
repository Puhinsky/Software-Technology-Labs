#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class product
{
private:
	std::string _name;
	double _price;
	size_t _quantity;
	std::weak_ptr<product> _promotion_pair;

public:
	product(const std::string& name, double price, size_t quantity);
	void print(std::ostream& os) const;

	friend bool make_promotion(std::shared_ptr<product>& p1, std::shared_ptr<product>& p2, double percent);
};

class store
{
private:
	std::vector<std::shared_ptr<product>> _products;
public:
	std::shared_ptr<product> add(std::string name, double price, size_t quantity);
	void print(std::ostream& os);
};

