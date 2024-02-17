#pragma once
#include "shape3d.h"

template<class T>
class parallelepiped : public shape3d<T>
{
public:
	parallelepiped(T a, T b, T c) : shape3d<T>(a, b, c)
	{
		this->_name = "Parallelepiped";
	}

	virtual T get_area() const override;
};

template<class T>
inline T parallelepiped<T>::get_area() const
{
	return 2 * (this->_a * this->_b + this->_b * this->_c + this->_a * this->_c);
}
