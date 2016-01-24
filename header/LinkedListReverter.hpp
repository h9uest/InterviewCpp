#ifndef _LinkedListReverter_HPP_
#define _LinkedListReverter_HPP_

#include "LinkedListNode.hpp"

template<typename T>
class LinkedListReverter
{
	public:
		LinkedListNode<T> * Revert(LinkedListNode<T> *head);
};

template<typename T>
LinkedListNode<T> * LinkedListReverter<T>::Revert(LinkedListNode<T> *head)
{
	if (head == nullptr || head->Next == nullptr)
	{
		return head;
	}

	LinkedListNode<T> *tail = head->Next;
	LinkedListNode<T> *it = tail->Next;
	tail->Next = head;
	head->Next = nullptr;
	while(it != nullptr)
	{
		LinkedListNode<T> *next_it = it->Next;
		it->Next = tail;
		tail = it;
		it = next_it;
	}
	return tail;
}
#endif
