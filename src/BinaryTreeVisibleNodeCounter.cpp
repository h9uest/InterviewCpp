#include "BinaryTreeVisibleNodeCounter.hpp"

typedef BinaryTreeVisibleNodeCounter::Node Node;

std::unordered_set<Node *> BinaryTreeVisibleNodeCounter::GetVisibleNodes(Node *tree)
{
	maxAncesterValue_.clear();
	visibleNodes_.clear();

	if (tree != nullptr)
	{
		if (IsVisible(tree, nullptr))
		{
			visibleNodes_.insert(tree);
		}
		GetVisibleNodes(tree->Left, tree);
		GetVisibleNodes(tree->Right, tree);
	}

	return visibleNodes_;
}

void BinaryTreeVisibleNodeCounter::GetVisibleNodes(Node *tree, Node *parent)
{
	if (tree != nullptr)
	{
		if (IsVisible(tree, parent))
		{
			visibleNodes_.insert(tree);
		}
		GetVisibleNodes(tree->Left, tree);
		GetVisibleNodes(tree->Right, tree);
	}
}

bool BinaryTreeVisibleNodeCounter::IsVisible(Node *node, Node *parent)
{
	if (parent == nullptr)
	{
		maxAncesterValue_[node] = node->Value;
		return false;
	}

	if (node->Value > maxAncesterValue_[parent])
	{
		maxAncesterValue_[node] = node->Value;
		return true;
	}

	maxAncesterValue_[node] = maxAncesterValue_[parent];
	return false;
}
