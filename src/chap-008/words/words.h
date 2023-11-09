#include <string>

namespace Words
{
	struct Word
	{
		std::string word;
		Word *left;
		Word *right;
	};

	Word * create_head(std::string word);
	Word * delete_all(Word *any);

	Word * append(Word *head, Word *to_append);
	Word * insert_before(Word *existing, Word *to_insert);
	Word * insert_after(Word *existing, Word *to_insert);

	Word * get_head(Word *any);

	std::string to_string(Word *existing);

	void sort(Word *any);
	void reverse(Word *any);
}
