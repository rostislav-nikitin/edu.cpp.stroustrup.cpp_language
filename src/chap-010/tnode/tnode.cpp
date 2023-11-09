#include "tnode.h"

#include <iostream>

namespace Tree
{
	TNode::TNode(std::string name, ITNode *parent) : _name(name), _parent(parent){ }
	TNode::~TNode()
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;

		std::vector<ITNode *>::iterator it_begin = _children.begin();
		std::vector<ITNode *>::iterator it_end = _children.end();
		while(it_begin != it_end)
		{
			delete *it_begin++;
		}

		std::cout << "Node \"" << name()  << "\" deleted" << std::endl;
	}

	std::string TNode::name() const
	{
		return _name;
	}

	void TNode::name(std::string new_name)
	{
		_name = new_name;
	}
		
	ITNode *TNode::parent()
	{
		return _parent;
	}

	void TNode::parent(ITNode *node)
	{
		_parent = node;
	}

	std::vector<ITNode *> &TNode::children()
	{
		return _children;
	}

	ITNode *TNode::append(ITNode *node)
	{
		_children.push_back(node);
		node->parent(this);

		return node;
	}

	ITNode *TNode::insert_before(ITNode *node, ITNode const &existing_node)
	{
		node->parent(this);

		return node;
	}

	ITNode *TNode::insert_after(ITNode *node, ITNode const &existing_node)
	{
		node->parent(this);

		return node;
	}

	ITNode *TNode::remove(ITNode *node)
	{
		node->parent(this);

		return node;
	}
}
