#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace::std;

constexpr auto NUMBERS_COUNT = 23;
constexpr auto START_VALUE = 12;
constexpr auto PARITY = 3;

void iota_test();

template<typename T>
void print_vector(const vector<T>& elements, const string label);

int main()
{
	iota_test();

	return 0;
}

void iota_test()
{
	vector<int> numbers(NUMBERS_COUNT);
	iota(numbers.begin(), numbers.end(), START_VALUE);
	print_vector(numbers, "iota");
	random_shuffle(numbers.begin(), numbers.end());
	print_vector(numbers, "shuffle");
	sort(numbers.begin(), numbers.end(), [](int lhr, int rhr)
		{
			if (lhr % PARITY == 0 && rhr % 3 != 0)
				return true;

			if (lhr % PARITY != 0 && rhr % 3 == 0)
				return false;

			return lhr < rhr;
		});
	print_vector(numbers, "sort");
}

template<typename T>
void print_vector(const vector<T>& elements, const string label)
{
	cout << "=================" << label << " =================" << endl;

	for (auto& item : elements)
	{
		cout << item << endl;
	}

	cout << "==================================" << endl;
}
