#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct TNode
{
	std::string word;
	int count;
	TNode *left;
	TNode *right;
};

TNode *insert_before(TNode *node, TNode *node_to_insert)
{
	TNode *temp = node->left;
	node->left = node_to_insert;
	node_to_insert->right = node;
	node_to_insert->left = temp;
	if(temp != nullptr)
		temp->right = node_to_insert;

	return node_to_insert;
}

TNode *insert_after(TNode *node, TNode *node_to_insert)
{
	TNode *temp = node->right;
	node->right = node_to_insert;
	node_to_insert->left = node;
	node_to_insert->right = temp;
	if(temp != nullptr)
		temp->left = node_to_insert;

	return node_to_insert;
}

TNode *append(TNode *node, TNode *node_to_append)
{
	while(node->right != nullptr)
		node = node->right;

	node->right = node_to_append;
	node_to_append->left = node;
	node_to_append->right = nullptr;

	return  node_to_append;
}

void print_tree(TNode const *root)
{
	while(root != nullptr)
	{
		std::cout << root->word << std::endl;
		root = root->right;
	}
}

void print_tree_ordered(TNode const *root)
{
	std::vector<std::string> words;
	while(root != nullptr)
	{
		words.push_back(root->word);
		root = root->right;
	}

	std::sort(words.begin(), words.end());
	std::vector<std::string>::iterator it = words.begin();
	while(it != words.end())
	{
		std::cout << *it++ << std::endl;
	}
}

int main()
{
	TNode root
	{
		"Root word",
		0
	};

	TNode last_word{"Last word", 0};
	append(&root, &last_word);

	TNode middle_word{"Middle word", 0};
	insert_before(&last_word, &middle_word);

	TNode after_root_word{"After root word", 0};
	insert_after(&root, &after_root_word);

	print_tree(&root);
	print_tree_ordered(&root);

	return 0;
}
