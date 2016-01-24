#ifndef _LinkedListNode_HPP_
#define _LinkedListNode_HPP_

template<typename T>
struct LinkedListNode
{
	T Value;
	LinkedListNode<T> *Next;

	LinkedListNode(T value)
	{
		Value = value;
		Next = nullptr;
	}
};

template<typename T>
struct LinkedListNodeAddrHasher
{
	size_t operator()(LinkedListNode<T> * const & addr) const
	{
		return reinterpret_cast<size_t>(addr);
	}
};

#endif
