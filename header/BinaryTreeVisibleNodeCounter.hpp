#ifndef _BinaryTreeVisibleNodeCounter_HPP_
#define _BinaryTreeVisibleNodeCounter_HPP_

#include <unordered_set>
#include <unordered_map>

class BinaryTreeVisibleNodeCounter
{
	public:

		struct Node
		{
			int Value;
			Node *Left;
			Node *Right;

			Node()
			{
				Value = 0;
				Left = nullptr;
				Right = nullptr;
			}

			Node(int value)
			{
				Value = value;
				Left = nullptr;
				Right = nullptr;
			}
		};

		std::unordered_set<Node *> GetVisibleNodes(Node *tree);

	private:
		std::unordered_set<Node *> visibleNodes_;
		std::unordered_map<Node *, int> maxAncesterValue_;
		bool IsVisible(Node *node, Node *parent);
		void GetVisibleNodes(Node *tree, Node *parent);
};

#endif
