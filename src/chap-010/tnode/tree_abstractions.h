#ifndef TREE_ABSTRACTIONS_H
#define TREE_ABSTRACTIONS_H

#include <string>
#include <vector>

namespace Tree
{
	class ITNode
	{
		public:
			virtual ~ITNode() {}
			virtual std::string name() const = 0;
			virtual void name(std::string new_name) = 0;

			virtual ITNode *parent() = 0;
			virtual void parent(ITNode *node) = 0;
			virtual std::vector<ITNode *> &children() = 0;

			virtual ITNode *append(ITNode *node) = 0;
			virtual ITNode *insert_before(ITNode *node, ITNode const &existing_node) = 0;
			virtual ITNode *insert_after(ITNode *node, ITNode const &existing_node) = 0;
			virtual ITNode *remove(ITNode *node) = 0;
	};

	class ITree
	{
		public:
			virtual ITNode *root() = 0;

			virtual ITNode *create_node(std::string name, ITNode *parent = nullptr) = 0;
	};
}

#endif
