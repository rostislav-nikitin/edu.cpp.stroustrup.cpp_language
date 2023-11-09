#include <iostream>

#include "use_tree.h"

int main()
{
	std::cout << "TREE" << std::endl;

	using Tree::Tree;

	Tree tree("Root");

	tree.root()
		->append(tree.create_node("Root sub node #1"))
		->append(tree.create_node("Sub sub node #1"));

	tree.root()
		->append(tree.create_node("Root sub node #2"))
		->append(tree.create_node("Sub sub node #2"));

	print(&tree);

	std::cout << "Tree created" << std::endl << std::endl;

	return 0;
}
