#ifndef TREE_H
#define TREE_H

#include <string>

#include "tree_abstractions.h"
#include "tnode.h"

namespace Tree
{
	class Tree : public ITree
	{
		private:
			ITNode *_root;

		public:
			Tree(std::string root_name);
			~Tree();

			ITNode *root() override;
			ITNode *create_node(std::string name, ITNode *parent = nullptr) override;
	};
}

#endif
