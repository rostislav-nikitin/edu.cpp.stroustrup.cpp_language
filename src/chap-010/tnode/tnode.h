#ifndef TNODE_H
#define TNODE_H

#include <string>
#include <vector>

#include "tree_abstractions.h"

namespace Tree
{
	class TNode : public ITNode
	{
		private:
			ITNode *_parent;
			std::string _name;
			std::vector<ITNode *> _children;

		public:
			TNode(std::string name, ITNode *parent = nullptr);
			~TNode();

			std::string name() const override;
			void name(std::string new_name) override;
		
			ITNode *parent() override;
			void parent(ITNode *node) override;

			std::vector<ITNode *> &children() override;

			ITNode *append(ITNode *node) override;
			ITNode *insert_before(ITNode *node, ITNode const &existing_node) override;
			ITNode *insert_after(ITNode *node, ITNode const &existing_node) override;
			ITNode *remove(ITNode *node) override;
	};
}

#endif
