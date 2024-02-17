#pragma once
#include <iostream>
#include "shape3d.h"
#include "math_consts.h"

template<class T>
class regular_triangular_pyramid : public shape3d<T>
{
public:
	regular_triangular_pyramid(T a, T b) : shape3d<T>(a, b, T())
	{
		this->_name = "Pyramid";

		if (b > 2 * a)
		{
			std::cerr << "Incorrect triangle" << std::endl;
			exit(1);
		}
	}

	virtual T get_area() const override;
};

template<class T>
inline T regular_triangular_pyramid<T>::get_area() const
{
	auto cos = this->_b / (2 * this->_a);
	auto sin = sqrt(1 - pow(cos, 2));

	return 0.5 * this->_a * this->_b * sin;
}
