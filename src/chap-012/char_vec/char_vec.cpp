#include <iostream>

class Char_vec
{
	int size;
	char element[1];

	public: 
		static Char_vec* new_char_vec(int size);
		char &operator[](int index);
};

Char_vec *Char_vec::new_char_vec(int size)
{
	Char_vec *res = reinterpret_cast<Char_vec*>(malloc(sizeof(int) + sizeof(char) * size));
	return res;
}

char &Char_vec::operator[](int index)
{
	return element[index];
}

int main()
{
	Char_vec *cvec = Char_vec::new_char_vec(16);

	(*cvec)[0] = 'a';

	std::cout << "cvec[0]=" << (*cvec)[0] << std::endl;

	free(cvec);

	return 0;
}
