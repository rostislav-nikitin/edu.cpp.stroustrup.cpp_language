#include <iostream>

#include "tree_helpers.h"

void print_node(Tree::ITNode *node, int level = 0);

void Tree::print(Tree::ITree *tree)
{
	//std::cout << __PRETTY_FUNCTION__ << " NOT IMPLEMENTED " << std::endl;
	print_node(tree->root()); 
}

void print_node(Tree::ITNode *node, int level)
{
	for(int i = 0; i < level; i++)
		std::cout << "\t";
	std::cout << node->name() << std::endl;

	for(size_t i = 0; i < node->children().size(); i++)
		print_node(node->children()[i], level + 1);		
}
