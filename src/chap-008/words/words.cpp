#include <string>
#include <iostream>
#include "words.h"

Words::Word * get_last(Words::Word *existing);
Words::Word * remove(Words::Word *to_remove);
void swap(Words::Word *first, Words::Word *second);

Words::Word * Words::create_head(std::string word)
{
	return new Words::Word{word};
}

Words::Word * Words::delete_all(Words::Word *any)
{
	Words::Word *current = get_last(any);

	while(current != nullptr)
	{
		Words::Word * temp = current->left;
		delete current;
		current = temp;				
	}

	return nullptr;
}

Words::Word * Words::append(Words::Word *head, Words::Word *to_append)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	if(head == nullptr || to_append == nullptr)
		return to_append;

	Words::Word *last = get_last(head);

	if(last == nullptr)
		return to_append;

	last->right = to_append;
	to_append->left = last;
	to_append->right = nullptr;

	return to_append;
}

Words::Word * Words::insert_before(Words::Word *existing, Words::Word *to_insert)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	if(existing == nullptr || to_insert == nullptr)
		return to_insert;

	to_insert = remove(to_insert);

	Words::Word *temp = existing->left;
	existing->left = to_insert;
	to_insert->right = existing;
	to_insert->left = temp;
	if(temp != nullptr)
	{
		temp->right = to_insert;
	}

	return to_insert;
}

Words::Word * Words::insert_after(Words::Word *existing, Words::Word *to_insert)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	if(existing == nullptr || to_insert == nullptr)
		return to_insert;

	to_insert = remove(to_insert);

	Words::Word *temp = existing->right;
	existing->right = to_insert;
	to_insert->left = existing;
	to_insert->right = temp;

	if(temp != nullptr)
	{
		temp->left = to_insert;		
	}

	return to_insert;
}

Words::Word * Words::get_head(Words::Word *any)
{
	if(any == nullptr)
		return any;

	while(any->left != nullptr)
		any = any->left;

	return any;
}

std::string Words::to_string(Words::Word *existing)
{
	std::string result;

	while(existing != nullptr)
	{
		result.append(" -> ");
		result.append(existing->word);
		existing = existing->right;
	}

	return result;
}

void Words::sort(Words::Word *any)
{
	Words::Word *head = get_head(any);
	bool is_moved;
	do
	{
		is_moved = false;
		Words::Word *current = head;
		while(current != nullptr && current->right != nullptr)
		{
			if(current->word > current->right->word)
			{
				insert_after(current->right, current);
				is_moved = true;
			}
			else
			{
				current = current->right;
			}
		}
	}
	while(is_moved);
}

void Words::reverse(Words::Word *any)
{
	Words::Word *head = get_last(any);
	Words::Word *current = head->left;
	remove(head);
	while(current != nullptr)
	{
		Words::Word *temp = current->left;
		append(head, current);
		current = temp;
	}
}

// Private
Words::Word * get_last(Words::Word *existing)
{
	if(existing == nullptr)
		return existing;

	while(existing->right != nullptr)
		existing = existing->right;

	return existing;
}

Words::Word * remove(Words::Word *to_remove)
{
	if(to_remove->left != nullptr)
		to_remove->left->right = to_remove->right;

	if(to_remove->right != nullptr)
		to_remove->right->left = to_remove->left;

	to_remove->left = nullptr;
	to_remove->right = nullptr;

	return to_remove;
}

void swap(Words::Word *first, Words::Word *second)
{
/*
	if(first == nullptr || second == nullptr)
		return;

	Words::Word *temp = first->left;
	if(temp != nullptr)
	{
		temp->right = second;
	}

	first->left = second->left;
	second->left = temp;
*/
}
