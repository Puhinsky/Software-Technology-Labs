#include <vector>
#include "entry_predicate.h"
#include <iostream>

using namespace::std;

template<class T>
void find_entry(const T& element, const vector<T>& vector);

int main()
{
	vector<char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	vector<char> dublicates = { 'a', 'b', 'c', 'a', 'b', 'c' };
	find_entry('a', dublicates);

	return 0;
}

template<class T>
void find_entry(const T& element, const vector<T>& vector)
{
	auto iterator = find_if(vector.begin(), vector.end(), entry_predicate<char>(element));

	if (iterator != vector.end())
	{
		auto entry = iterator - vector.begin();
		cout << "Entry of " << element << " is " << entry << endl;
	}
	else
	{
		cout << element << " Not founded" << endl;
	}
}
