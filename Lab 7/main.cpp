#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace::std;

constexpr auto NUMBERS_COUNT = 23;
constexpr auto START_VALUE = 12;
constexpr auto PARITY = 3;

void iota_test();
void positions();

template<typename T>
void print_vector(const vector<T>& elements, const string label);

int main()
{
	iota_test();
	positions();

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

void positions()
{
	int initial_x;
	int initial_y;
	int initial_z;
	cout << "initial (X Y Z): ";
	cin >> initial_x >> initial_y >> initial_z;

	vector<int> delta_x = { -1, 10, -15, 5 };
	vector<int> delta_y = { 5, -8, 20, -3 };
	vector<int> delta_z = { 3, -4, 12, -9 };

	vector<int> absolute_x(delta_x.size());
	vector<int> absolute_y(delta_x.size());
	vector<int> absolute_z(delta_x.size());

	partial_sum(delta_x.begin(), delta_x.end(), absolute_x.begin(), [&](int a, int b) { return a + b + initial_x; });
	partial_sum(delta_y.begin(), delta_y.end(), absolute_y.begin(), [&](int a, int b) { return a + b + initial_y; });
	partial_sum(delta_z.begin(), delta_z.end(), absolute_z.begin(), [&](int a, int b) { return a + b + initial_z; });

	print_vector(absolute_x, "X");
	print_vector(absolute_y, "Y");
	print_vector(absolute_z, "Z");
}

template<typename T>
void print_vector(const vector<T>& elements, const string label)
{
	cout << "================= " << label << " =================" << endl;

	for (auto& item : elements)
	{
		cout << item << endl;
	}

	cout << "==================================" << endl;
}
