#include "gtest/gtest.h"
#include "Queue.hpp"

TEST(Queue, Pop_Exception)
{
	try
	{
		Queue<int> q;
		q.Pop();
	}
	catch(std::exception& ex)
	{
		EXPECT_STREQ("Pop when queue is empty\n", ex.what());
	}
}
