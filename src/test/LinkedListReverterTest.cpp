#include "gtest/gtest.h"
#include "LinkedListReverter.hpp"

TEST(LinkedListReverter, EmptyList)
{
	LinkedListReverter<int> reverter;
	EXPECT_EQ(nullptr, reverter.Revert(nullptr));
}

TEST(LinkedListReverter, SingleElementList)
{
	LinkedListReverter<double> reverter;
	LinkedListNode<double> node(1);
	EXPECT_EQ(&node, reverter.Revert(&node));
}

TEST(LinkedListReverter, MultipleElementList)
{
	LinkedListNode<int> *head = new LinkedListNode<int>(0);
	LinkedListNode<int> *node = head;
	for (int i=1; i<100; i++)
	{
		node->Next = new LinkedListNode<int>(i);
		node = node->Next;
	}

	LinkedListReverter<int> reverter;
	LinkedListNode<int> *res = reverter.Revert(head);
	LinkedListNode<int> *it = res;
	for (int i=99; i>-1; i--)
	{
		LinkedListNode<int> *ptr = it;
		EXPECT_EQ(i, it->Value);
		it = it->Next;
		delete ptr;
	}
	EXPECT_EQ(nullptr, it);
}
