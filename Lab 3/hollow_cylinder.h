#pragma once
#include <iostream>
#include "shape3d.h"
#include "math_consts.h"

template<class T>
class hollow_cylinder : public shape3d<T>
{
public:
	hollow_cylinder(T a, T b, T c) : shape3d<T>(a, b, c)
	{
		this->_name = "Cylinder";

		if (a < b)
		{
			std::cerr << "In cylinder outer radius less then inner radius" << std::endl;
			exit(1);
		}
	}

	virtual T get_area() const override;
};

template<class T>
inline T hollow_cylinder<T>::get_area() const
{
	auto r_out = this->_a;
	auto r_in = this->_b;
	auto h = this->_c;

	auto outer = h * 2 * PI * r_out;
	auto inner = h * 2 * PI * r_in;
	auto rings = 2 * (PI * pow(r_out, 2) - PI * pow(r_in, 2));

	return outer + inner + rings;
}
