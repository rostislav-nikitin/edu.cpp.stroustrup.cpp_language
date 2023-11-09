#include "tree.h"
//#include "tnode.h"
#include <iostream>

namespace Tree
{

	Tree::Tree(std::string root_name)
	{
		_root = new TNode(root_name);
	}

	Tree::~Tree()
	{
		//_root->~ITNode();
		//std::cout << __PRETTY_FUNCTION__ << std::endl;		
		delete _root;
		std::cout << "Tree deleted" << std::endl;
	}

	ITNode *Tree::root()
	{
		return _root;
	}

	ITNode *Tree::create_node(std::string name, ITNode *parent)
	{
		return new TNode(name, parent);
	}
}
