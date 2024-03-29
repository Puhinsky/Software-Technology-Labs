#pragma once
#include <functional>

template<class T>
class entry_predicate
{
private:
	T _target;
public:
	entry_predicate(T target);
	bool operator()(const T& element) const;
};

template<class T>
inline entry_predicate<T>::entry_predicate(T target)
{
	_target = target;
}

template<class T>
inline bool entry_predicate<T>::operator()(const T& element) const
{
	return _target == element;
}
