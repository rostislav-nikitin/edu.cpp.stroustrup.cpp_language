#include <functional>
#include <string>
#include <iostream>
#include <cstring>
#include <exception>

template<class TValue>
struct Node
{
	Node *parent;

	Node *left;
	Node *right;

	TValue value;

	Node(TValue value);
	Node &create_left(TValue);
	Node &create_right(TValue);
	~Node();
};

template<class TValue>
Node<TValue>::Node(TValue value) : parent(nullptr), left(nullptr), right(nullptr), value(value)
{
}

template<class TValue>
Node<TValue> &Node<TValue>::create_left(TValue value)
{
	
	Node<TValue> *temp = new Node<TValue>(value);
	temp->parent = this;

	if(left != nullptr)
		delete left;

	left = temp;

	return *left;
}

template<class TValue>
Node<TValue> &Node<TValue>::create_right(TValue value)
{

	Node<TValue> *temp = new Node<TValue>(value);
	temp->parent = this;

	if(right != nullptr)
		delete right;

	right = temp;

	return *right;
}

template<class TValue>
Node<TValue>::~Node()
{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
	delete left;
	delete right;
}

using CharNode = Node<char const *>;

class Tree
{
	CharNode *_root;
	public:
		class NotFoundException : public std::exception
		{
			std::string _message;
		public:
			NotFoundException(std::string message) : std::exception(), _message(message) {}
			virtual char const * what() const throw() override
			{
				return _message.c_str();
			}
		};

		Tree(char const* root);

		CharNode *traversal(std::function<bool (CharNode const&)> predicate) const;

		CharNode &get_root() const;
		CharNode &find(char const *str);

		~Tree();
};

Tree::Tree(char const* root)
{
	_root = new CharNode(root);
};

CharNode &Tree::get_root() const
{
	return *_root;
}

CharNode *Tree::traversal(std::function<bool (CharNode const&)> predicate) const
{
	bool down = true;
	bool up_from_left = false;

	CharNode *current = _root;

	while(current != nullptr)
	{
		if(!predicate(*current))
			return current;

		//std::cout << "down=" << down << std::endl;
		if(down)
		{
			if(current->left != nullptr)
			{
				current = current->left;
			}
			else if(current->right != nullptr)
			{
				current = current->right;
			}
			else
			{
				if(current->parent != nullptr)
				{
					up_from_left = current->parent->left == current;
				}
				current = current->parent;
				down = false;
			}
		}
		else
		{
			if(up_from_left)
			{
				if(current->right != nullptr)
				{
					current = current->right;
					down = true;
					continue;
				}
			}

			if(current->parent != nullptr)
			{
				up_from_left = current->parent->left == current;
			}
			current = current->parent;
			
		}
	}

	return nullptr;
}
CharNode &Tree::find(char const *str)
{
	CharNode *result = traversal([str](CharNode const &node){ return strcmp(node.value, str) != 0; });
	if(result == nullptr)
		throw NotFoundException("\"" + std::string(str) + "\" node not found.");

	return *result;
}

Tree::~Tree()
{
	delete _root;
}

int main()
{
	try
	{
		Tree tree("Root node");	
		CharNode &left_node = tree.get_root().create_left("Left from root");
		CharNode &right_node = tree.get_root().create_right("right from root");
	
		left_node.create_left("Left left node");
		left_node.create_right("Right left node");

		right_node.create_left("Left right node");
		right_node.create_right("Right right node");

	//std::cout << tree.get_root().value << std::endl;

		std::cout << "Found: " << tree.find("Left right node").value << std::endl;
		std::cout << tree.find("Not existsing Left right node").value << std::endl;
	}
	catch(Tree::NotFoundException &ex)
	{
		std::cout << "Can not find specified tree node." << std::endl;
		std::cout << "\t" << ex.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "Critical exception. Exit" << std::endl;
	}

	return 0;
}
