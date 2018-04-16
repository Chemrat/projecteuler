#include "bst_nostack.h"

#include <iostream>

class TreeNode
{
public:
	TreeNode()
	{

	}

	TreeNode(int initvalue)
		: value(initvalue)
	{

	}

	TreeNode * left = nullptr;
	TreeNode * right = nullptr;
	int value = 0;

	void Push(int newValue)
	{
		auto &direction = newValue > value ? left : right;

		if (direction)
			direction->Push(newValue);
		else
			direction = new TreeNode(newValue);
	}

	void Print()
	{
		if (right)
			right->Print();
		std::cout << value << " ";
		if (left)
			left->Print();
	}
};

void BstNoStack::Run()
{
	auto root = TreeNode(10);
	root.Push(5);
	root.Push(12);
	root.Push(4);
	root.Push(10);
	root.Push(13);
	root.Push(9);

	root.Print();
	std::cout << std::endl;
}
