#pragma once
#include <memory>
#include <stdexcept>

template<typename T>
class queue
{
private:
	struct node
	{
		T data;
		std::unique_ptr<node> next;

		node(const T& value) : data(value), next(nullptr) {}
	};

	std::unique_ptr<node> _head;
	node* _tail;

public:
	queue() : _head(nullptr), _tail(nullptr) {}

	void push_back(const T& value);
	T pop_front();
	bool is_empty() const;
};

template<typename T>
inline void queue<T>::push_back(const T& value)
{
	auto new_node = std::make_unique<node>(value);

	if (!_head)
	{
		_head = std::move(new_node);
		_tail = _head.get();
	}
	else
	{
		_tail->next = std::move(new_node);
		_tail = _tail->next.get();
	}
}

template<typename T>
inline T queue<T>::pop_front()
{
	if (!_head)
		throw std::out_of_range("Queue is empty");

	T value = std::move(_head->data);
	auto old_head = std::move(_head);
	_head = std::move(old_head->next);

	if (!_head)
		_tail = nullptr;

	return value;
}

template<typename T>
inline bool queue<T>::is_empty() const
{
	return _head == nullptr;
}
