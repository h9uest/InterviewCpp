#include "gtest/gtest.h"
#include "LinkedListCycleDetector.hpp"

TEST(LinkedListCycleDetector, HasCycle_True)
{
	LinkedListNode<int> head(1);
	LinkedListNode<int> two(2);
	LinkedListNode<int> three(3);
	head.Next = &two;
	two.Next = &three;
	three.Next = &two;

	LinkedListCycleDetector<int> detector;
	EXPECT_EQ(true, detector.HasCycle(&head));
}

TEST(LinkedListCycleDetector, HasCycle_False)
{
	LinkedListNode<int> head(1);
	LinkedListNode<int> two(2);
	LinkedListNode<int> three(3);
	head.Next = &two;
	two.Next = &three;

	LinkedListCycleDetector<int> detector;
	EXPECT_EQ(false, detector.HasCycle(&head));
}

TEST(LinkedListCycleDetector, HasCycle_EmptyList)
{
	LinkedListCycleDetector<int> detector;
	EXPECT_EQ(false, detector.HasCycle(nullptr));
}

TEST(LinkedListCycleDetector, HasCycle_OneElementList)
{
	LinkedListNode<int> head(1);
	LinkedListCycleDetector<int> detector;
	EXPECT_EQ(false, detector.HasCycle(&head));
}
