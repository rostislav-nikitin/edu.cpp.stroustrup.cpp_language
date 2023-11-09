#include <iostream>
#include "words.h"

int main()
{
	std::cout << "Creating HEAD ..." << std::endl;
	Words::Word *head = Words::create_head("HEAD");
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Appending to HEAD ..." << std::endl;
	Words::Word *appended = Words::append(head, new Words::Word{"Appended"});
	std::cout << Words::to_string(head) << std::endl;

	//std::cout << appended->word << std::endl;
	std::cout << "Inserting before appended ..." << std::endl;
	Words::Word *inserted_before = Words::insert_before(appended, new Words::Word{"Inserted before Appended"});
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Inserting appended before inserted ..." << std::endl;
	Words::insert_before(inserted_before, appended);
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Inserting inserted before appended..." << std::endl;
	Words::insert_before(appended, inserted_before);
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Inserting after appended..." << std::endl;
	Words::Word *inserted_after = Words::insert_after(appended, new Words::Word{"Inserted after Appended"});
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Sorting..." << std::endl;
	Words::sort(head);
	head = Words::get_head(head);
	std::cout << "HEAD is " << head->word << std::endl;
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Reversing..." << std::endl;
	Words::reverse(head);
	head = Words::get_head(head);
	std::cout << "HEAD is " << head->word << std::endl;
	std::cout << Words::to_string(head) << std::endl;

	std::cout << "Deleting all words linked list..." << std::endl;
	head = Words::delete_all(head);	

	return 0;
}
