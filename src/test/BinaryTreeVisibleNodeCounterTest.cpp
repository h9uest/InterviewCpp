#include "gtest/gtest.h"
#include "BinaryTreeVisibleNodeCounter.hpp"

typedef BinaryTreeVisibleNodeCounter::Node Node;

TEST(BinaryTreeVisibleNodeCounter, GetVisibleNodes_BaseCase)
{
	Node node;
	node.Value = 1;
	BinaryTreeVisibleNodeCounter counter;
	std::unordered_set<Node *> expectedRes;
	EXPECT_EQ(expectedRes, counter.GetVisibleNodes(&node));
}

TEST(BinaryTreeVisibleNodeCounter, GetVisibleNodes_RegularCase)
{
	Node root(3);
	Node six(6);
	Node four(4);
	Node seven(7);
	Node five(5);
	Node eight(8);

	root.Left = &six;
	root.Right = &four;
	six.Left = &seven;
	six.Right = &five;
	five.Right = &eight;

	BinaryTreeVisibleNodeCounter counter;
	std::unordered_set<Node *> expected_res({&six, &four, &seven, &eight});
	std::unordered_set<Node *> res = counter.GetVisibleNodes(&root);
	EXPECT_EQ(4, res.size());
	for (std::unordered_set<Node *>::iterator it = res.begin(); it != res.end(); ++it)
	{
		EXPECT_NE(expected_res.end(), expected_res.find(*it));
	}
}
