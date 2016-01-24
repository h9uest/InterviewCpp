#ifndef _LinkedListCycleDetector_HPP_
#define _LinkedListCycleDetector_HPP_

#include "LinkedListNode.hpp"
#include <unordered_set>

template<typename T>
class LinkedListCycleDetector
{
	public:
		bool HasCycle(LinkedListNode<T> *head);
};

template<typename T>
bool LinkedListCycleDetector<T>::HasCycle(LinkedListNode<T> *head)
{
	std::unordered_set<LinkedListNode<T> *, LinkedListNodeAddrHasher<T> > mem;
	while(head != nullptr)
	{
		if (mem.find(head) != mem.end())
		{
			return true;
		}
		mem.insert(head);
		head = head->Next;
	}
	return false;
}

#endif
