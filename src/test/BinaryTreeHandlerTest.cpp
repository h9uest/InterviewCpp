#include "gtest/gtest.h"
#include "BinaryTreeHandler.hpp"

TEST(BinaryTreeHandler, ConstructBSTFromSorted_EvenNumElements)
{
	BinaryTreeHandler<int> handler;
	std::vector<int> vec({1, 2, 3, 4, 5, 6});
	BinaryTreeNode<int> * ptr = handler.ConstructBSTFromSorted(vec, 0, 5);
	std::vector<int> exp = handler.InOrderTraverse(ptr);
	EXPECT_EQ(exp, vec);
}

TEST(BinaryTreeHandler, ConstructBSTFromSorted_OddNumElements)
{
	BinaryTreeHandler<double> handler;
	std::vector<double> vec({1.2, 3.3, 5, 8.9, 9.1});
	BinaryTreeNode<double> *ptr = handler.ConstructBSTFromSorted(vec, 0, 4);
	std::vector<double> exp = handler.InOrderTraverse(ptr);
	EXPECT_EQ(exp, vec);
}
