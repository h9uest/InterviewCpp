#ifndef _BinaryTreeNode_HPP_
#define _BinaryTreeNode_HPP_

template<typename T>
struct BinaryTreeNode
{
	BinaryTreeNode<T> *Left;
	BinaryTreeNode<T> *Right;
	T Value;

	BinaryTreeNode();
	BinaryTreeNode(T value);
	BinaryTreeNode(T value, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right);
};

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode()
{
}

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T value)
{
	Value = value;
	Left = nullptr;
	Right = nullptr;
}

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T value, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right)
{
	Value = value;
	Left = left;
	Right = right;
}

#endif
