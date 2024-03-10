#include <iostream>
#include "queue.h"
#include "store.h"

void queue_test();
void store_test();

int main()
{
	queue_test();
	store_test();

	return 0;
}

void queue_test()
{
	queue<int> queue;

	queue.push_back(10);
	queue.push_back(20);
	queue.push_back(30);

	while (!queue.is_empty())
	{
		std::cout << "Front element: " << queue.pop_front() << std::endl;
	}

	//queue.pop_front();
}

void store_test()
{
	store store;

	auto apple = store.add("Apple", 1.0, 60);
	auto banana = store.add("Banana", 0.5, 40);
	auto orange = store.add("Orange", 0.8, 100);

	make_promotion(apple, banana, 20);

	store.print(std::cout);
}
