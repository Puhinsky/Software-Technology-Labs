#pragma once
template<class T>
class palindrome_predicate
{
private:
	std::vector<T>& _palindromes;

public:
	//<mark> explicit modificator
	palindrome_predicate(std::vector<T>& palindromes) : _palindromes(palindromes) {}

	void operator()(T number);
};

template<class T>
inline void palindrome_predicate<T>::operator()(T number)
{
	T original = number;
	T reversed = 0;

	while (number > 0)
	{
		reversed = reversed * 10 + number % 10;
		number /= 10;
	}

	if (original == reversed)
		_palindromes.push_back(original);
}
