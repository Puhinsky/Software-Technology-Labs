#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace::std;

constexpr auto NUMBERS_COUNT = 23;
constexpr auto START_VALUE = 12;
constexpr auto PARITY = 3;

constexpr auto INITIAL_X = 1;
constexpr auto INITIAL_Y = 6;
constexpr auto INITIAL_Z = 4;

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
	vector<int> initial(3);
	cout << "initial (X Y Z): ";
	cin >> initial[0] >> initial[1] >> initial[2];

	vector<int> delta_x = { -1, 10, -15, 5 };
	vector<int> delta_y = { 5, -8, 20, -3 };
	vector<int> delta_z = { 3, -4, 12, -9 };

	std::vector<std::vector<int>> absolute;

	int x = initial[0];
	int y = initial[1];
	int z = initial[2];

	std::transform(delta_x.begin(), delta_x.end(), delta_y.begin(), delta_z.begin(), std::back_inserter(absolute),
		[&](int dx, int dy, int dz) -> std::vector<int>
		{
			x += dx;
			y += dy;
			z += dz;
			return std::vector<int>{x, y, z};
		});//mb partial_sum
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
