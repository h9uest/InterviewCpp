#ifndef _Queue_HPP_
#define _Queue_HPP_
#include <exception>

template<typename T>
struct Node
{
	T Value;
	Node<T> *Next;

	Node(T value, Node<T> *next = nullptr)
	{
		Value = value;
		Next = next;
	}
};

template<typename T>
class Queue
{
	protected:
		Node<T> *head_;
		Node<T> *tail_;
		size_t size_;

	public:
		Queue();
		T Pop();
		void Push(const T t);
		size_t Size() const;
};

template<typename T>
Queue<T>::Queue()
{
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}

template<typename T>
T Queue<T>::Pop()
{
	if (size_ == 0)
	{
		throw std::runtime_error("Pop when queue is empty\n");
	}

	T value = head_->Value;
	Node<T> *ptr = head_;
	head_ = head_->Next;
	delete ptr;
	size_ --;
	return value;
}

template<typename T>
void Queue<T>::Push(T t)
{
	if (tail_ != nullptr)
	{
		tail_->Next = new Node<T>(t);
		tail_ = tail_->Next;
	}
	else
	{
		tail_ = new Node<T>(t);
		head_ = tail_;
	}
	size_ ++;
}

template<typename T>
size_t Queue<T>::Size() const
{
	return size_;
}

#endif
