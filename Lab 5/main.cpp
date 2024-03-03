#include <vector>
#include <algorithm>
#include <iostream>
#include "palindrome_predicate.h"

using namespace::std;

vector<int> task_with_lambda(const vector<int>& numbers);
vector<int> task_with_functor(const vector<int>& numbers);
void print_vector(const vector<int>& number);

int main()
{
	vector<int> numbers = { 5665, 12321, 123, 456, 78987 };
	print_vector(task_with_lambda(numbers));
	print_vector(task_with_functor(numbers));

	return 0;
}

vector<int> task_with_lambda(const vector<int>& numbers)
{
	vector<int> palindromes;

	for_each(numbers.begin(), numbers.end(), [&palindromes](int number)
		{
			int original = number;
			int reversed = 0;

			while (number > 0)
			{
				reversed = reversed * 10 + number % 10;
				number /= 10;
			}

			if (original == reversed)
				palindromes.push_back(original);
		});

	return palindromes;
}

vector<int> task_with_functor(const vector<int>& numbers)
{
	vector<int> palindromes;

	for_each(numbers.begin(), numbers.end(), palindrome_predicate<int>(palindromes));

	return palindromes;
}

void print_vector(const vector<int>& number)
{
	for (const auto& number : number)
	{
		cout << number << endl;
	}

	cout << endl;
}
