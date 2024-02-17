#include <iostream>
#include "shape3d.h"
#include <vector>
#include "parallelepiped.h"
#include "regular_triangular_pyramid.h"
#include "hollow_cylinder.h"

void regular_implementation();
void advanced_implementation();
shape3d<double>* generate_random();

int main()
{
	regular_implementation();
	advanced_implementation();

	return 0;
}

void regular_implementation()
{
	for (size_t i = 0; i < 5; i++)
	{
		auto shape = generate_random();
		std::cout << "Type: "<< typeid(shape).name() << std::endl;
		std::cout << "Name: " << shape->get_name() << std::endl;
		std::cout << "Name: " << shape->get_area() << std::endl;
		std::cout << std::endl;
	}
}

void advanced_implementation()
{
	std::vector<std::unique_ptr<shape3d<double>>> shapes;

	shapes.push_back(std::make_unique<parallelepiped<double>>(2, 3, 4));
	shapes.push_back(std::make_unique<regular_triangular_pyramid<double>>(6, 6));
	shapes.push_back(std::make_unique<hollow_cylinder<double>>(10, 5, 7));

	for (const auto& shape : shapes)
	{
		std::cout << "Name: " << shape->get_name() << "\t" << "Area: " << shape->get_area() << std::endl;
	}

	auto random_shape = shapes[rand() % shapes.size()].get();
	std::cout << "Type of " << random_shape->get_name() << " is " << typeid(random_shape).name() << std::endl;
}

shape3d<double>* generate_random()
{
	switch (rand() % 3)
	{
		case 0:
			return new parallelepiped<double>(2, 3, 4);
		case 1:
			return new regular_triangular_pyramid<double>(6, 6);
		case 2:
			return new hollow_cylinder<double>(10, 5, 7);
	}

	std::cerr << "Error of random generator implementation";
	exit(1);
}
