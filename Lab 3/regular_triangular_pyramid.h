#pragma once
#include "shape3d.h"
#include "math_consts.h"

template<class T>
class regular_triangular_pyramid : public shape3d<T>
{
public:
	regular_triangular_pyramid(T a, T b, T c) : shape3d<T>(a, b, c)
	{
		this->_name = "Pyramid";
	}

	virtual T get_area() const override;
};

template<class T>
inline T regular_triangular_pyramid<T>::get_area() const
{
	return 0.5 * this->a * this->b * sin(this->c * DEG2RAD);
}
