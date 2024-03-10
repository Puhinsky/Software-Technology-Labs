#include <iostream>
#include "queue.h"

void queue_test();

int main()
{
	queue_test();

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

	queue.pop_front();
}
