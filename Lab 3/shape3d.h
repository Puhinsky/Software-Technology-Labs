#pragma once
#include <string>

template <class T>
class shape3d
{
protected:
	T _a, _b, _c;
	std::string _name;
public:
	shape3d(T a, T b, T c);
	virtual T get_area() const = 0;
	std::string get_name() const;
};

template<class T>
inline shape3d<T>::shape3d(T a, T b, T c)
{
	_a = a;
	_b = b;
	_c = c;
}

template<class T>
inline std::string shape3d<T>::get_name() const
{
	return _name;
}
