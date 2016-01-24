#ifndef _BinaryTreeHandler_HPP_
#define _BinaryTreeHandler_HPP_

#include "BinaryTreeNode.hpp"
#include <vector>

template<typename T>
class BinaryTreeHandler
{
	protected:
		std::vector<T> inorders_;

	public:
		BinaryTreeNode<T> * ConstructBSTFromSorted(const std::vector<T>& vec, size_t start, size_t end);
		void PrintLevelByLevel(BinaryTreeNode<T> *root);
		std::vector<T> InOrderTraverse(BinaryTreeNode<T> *root);
};

template<typename T>
BinaryTreeNode<T> * BinaryTreeHandler<T>::ConstructBSTFromSorted(const std::vector<T>& vec, size_t start, size_t end)
{
	if (end == start)
	{
		return new BinaryTreeNode<T>(vec[end]);
	}

	if (end < start)
	{
		return nullptr;
	}

	size_t mid = (end + start) / 2;
	BinaryTreeNode<T> *left_tree = nullptr;
	if (mid > start)
	{
		left_tree = ConstructBSTFromSorted(vec, start, mid-1);
	}

	BinaryTreeNode<T> *right_tree = nullptr;
	if (mid < end)
	{
		right_tree = ConstructBSTFromSorted(vec, mid+1, end);
	}
	
	return new BinaryTreeNode<T>(vec[mid], left_tree, right_tree);
}

template<typename T>
std::vector<T> BinaryTreeHandler<T>::InOrderTraverse(BinaryTreeNode<T> *root)
{
	if (root == nullptr)
	{
		return {};
	}

	InOrderTraverse(root->Left);
	inorders_.push_back(root->Value);
	InOrderTraverse(root->Right);
	return inorders_;
}

#endif
