#include <cassert>
#include <cstring>
#include <iostream>

#define DEBUG

class String
{
	private:
		struct Rep;
		Rep *_rep;
		class CharRef;

	public:
		class Out_of_range_exception { };

		String();
		String(char const *);
		String(String const &);
		~String();

		char read(int const index) const;
		void write(int const index, char const value);
		int size() const;
		char const *c_str() const;

		String operator=(char const *);
		String operator=(String const &);
		String operator+=(String const &);
		char operator[](int index) const;
		CharRef operator[](int index);
		String operator()(int begin);
		String operator()(int begin, int length);
		//operator char*();

		friend String operator+(String const &str1, String const &str2);
		friend bool operator==(String const &str1, String const &str2);
		friend bool operator==(String const &str1, char const *str2);
		friend bool operator!=(String const &str1, String const &str2);
		friend bool operator!=(String const &str1, char const *str2);

		friend std::ostream& operator<<(std::ostream &stream, String const &str);
};

class String_iterator
{
	private:
		String const &_str;
		int _position;
	public:
		class EOF_exception { };

		String_iterator(String const &str);
		char next();
		bool eof() const;
};

String_iterator::String_iterator(String const &str) : _str(str), _position(0) { }
char String_iterator::next()
{
	if(eof())
		throw EOF_exception();

	return _str.read(_position++);
}
bool String_iterator::eof() const
{
	return _position >= _str.size();
}

struct String::Rep
{
	int size;	
	char *value;
	int refs_count;

	Rep();
	Rep(char const *);
	~Rep();

	private:
		Rep(Rep const &);
		Rep operator=(Rep const &);
};

String::Rep::Rep() : size(0), refs_count(1)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	value = new char[size + 1] {'\0'};
}

String::Rep::Rep(char const *in_value) : refs_count(1)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	size = strlen(in_value);
	value = new char[size + 1];
	strcpy(value, in_value);
}

String::Rep::~Rep()
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	delete[] value;
}

class String::CharRef
{
	String& _str;
	int _index;
	public:
		CharRef(String &str, int index);
		CharRef(CharRef const &);

		CharRef operator=(char value);
		operator char() const;
};

String::CharRef::CharRef(String &str, int index) : _str(str), _index(index) { }
String::CharRef::CharRef(CharRef const &cref) : _str(cref._str), _index(cref._index){ }
String::CharRef String::CharRef::operator=(char value)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	_str.write(_index, value);

	return *this;
}
String::CharRef::operator char() const
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	return _str.read(_index);
}

char String::read(int const index) const
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return _rep->value[index];
}

void String::write(int const index, char const value)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	if(_rep->refs_count > 1)
	{
		Rep *new_rep = new Rep(_rep->value);
		_rep->refs_count--;
		_rep = new_rep;
	}
	_rep->value[index] = value;
	std::cout << "value: " << value << std::endl;
}

int String::size() const
{
	return _rep->size;
}

char const *String::c_str() const
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return _rep->value;
}

String::String()
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	_rep = new Rep();
}
String::String(char const *str)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	_rep = new Rep(str);
}

String::String(String const &str)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	_rep = str._rep;
	_rep->refs_count++;
}

String::~String()
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << "\tsize: " << _rep->size << "\trefs_count: " << _rep->refs_count << std::endl;
#endif
	if(_rep->refs_count < 2)
		delete _rep;
	else
		_rep->refs_count--;
}

String String::operator=(char const *str)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	if(_rep->refs_count < 2)
		delete _rep;
	_rep = new Rep(str);

	return *this;	
}

String String::operator=(String const &str)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	str._rep->refs_count++;
	if(_rep->refs_count == 1)
		delete _rep;

	_rep = str._rep;

	return *this;	
}

String String::operator+=(String const &str)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	int new_size = _rep->size + str._rep->size;
	char *new_value = new char[new_size + 1];
	strcpy(new_value, _rep->value);
	strcpy(new_value + _rep->size, str._rep->value);
	if(_rep->refs_count < 2)
		delete _rep;
	_rep = new Rep(new_value);

	delete[] new_value;

	return *this;
}

char String::operator[](int index) const
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return _rep->value[index];
}

String::CharRef String::operator[](int index)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return String::CharRef(*this, index);
}

String String::operator()(int begin = 0)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	if(begin >= _rep->size)
		throw Out_of_range_exception();

	return String(_rep->value + begin);
}
String String::operator()(int begin, int length)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
//	if(length == 0)
//		return String();

	if(begin >= _rep->size || begin + length > _rep->size)
		throw Out_of_range_exception();
	char *new_value = new char[length + 1];
	for(int src_idx = begin, dest_idx = 0; src_idx < length; ++src_idx, ++dest_idx)
	{
		new_value[dest_idx] = _rep->value[src_idx];
	}
	new_value[length] = '\0';

	return String(new_value + begin);
}

/*		
String::operator char*()
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
	char *result = new char[_rep->size + 1];
	strcpy(result, _rep->value);
	return result;
}*/

String operator+(String const &str1, String const &str2)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif


	int size = str1._rep->size + str2._rep->size;
	char *value = new char[size + 1];
	strcpy(value, str1._rep->value);
	strcpy(value + str1._rep->size, str2._rep->value);

	String result(value);

	delete[] value;
	
	return result;
}

bool operator==(String const &str1, String const &str2)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return str1._rep->size == str2._rep->size && strcmp(str1._rep->value, str2._rep->value) == 0;
}
bool operator==(String const &str1, char const *str2)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return strcmp(str1._rep->value, str2) == 0;
}
bool operator!=(String const &str1, String const &str2)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return str1._rep->size != str2._rep->size || strcmp(str1._rep->value, str2._rep->value) != 0;
}
bool operator!=(String const &str1, char const *str2)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	return strcmp(str1._rep->value, str2) != 0;
}

std::ostream& operator<<(std::ostream &stream, String const &str)
{
#ifdef DEBUG
	std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

	stream << str._rep->value;

	return stream;
}

int main()
{
	String empty;

	String s1 = "Hello, string!";
	std::cout << "s1: " << s1 << std::endl;

	std::cout << "s1 first letter: '" << s1.read(0) << "'" << std::endl;

	String s2(s1);
	std::cout << "s2: " << s2 << std::endl;

	String s3(s1);
	s3.write(0, 'A');
	std::cout << "s3: " << s3 << std::endl;

	String s4 = "Temp";
	std::cout << "s4: " << s4 << std::endl;

	s4 = "New String";
	std::cout << "s4: " << s4 << std::endl;
	//assert((0));

	s4 = s3;
	std::cout << "s4: " << s4 << std::endl;

	String s5 = s1 + s2;
	std::cout << "s5: " << s5 << std::endl;

	std::cout << "s1 == s1: " << (s1 == s1) << std::endl;
	std::cout << "s1 != s1: " << (s1 != s1) << std::endl;
	std::cout << "s1 == s3: " << (s1 == s3) << std::endl;
	std::cout << "s1 != s3: " << (s1 != s3) << std::endl;

	s5 += "\t second one mode String";
	std::cout << s5 << std::endl;

	std::cout << "s5[0] = '" << s5[0] << "'" << std::endl;

	s5[0] = 'X';
	std::cout << "s5 = '" << s5 << "'" << std::endl;

	const char c = s5[0];
	std::cout << "c = s5[0] = '" << c << "'" << std::endl;

	const String s6 = "Test str";
	std::cout << "s6[0] = '" << s6[0] << "'" << std::endl;


	String s7 = "String iterator over: 0123456789abc...";
	String_iterator si7 (s7);
	while(!si7.eof())
	{
		std::cout << si7.next();
	}
	std::cout << std::endl;

	try
	{
		si7.next();
	}
	catch(String_iterator::EOF_exception ex)
	{
		std::cout << "si7.next() throws EOF exception" << std::endl;
	}

	String s8 = "New string";
	std::cout << "substr(4): " << s8(4) << std::endl;
	std::cout << "substr(0, 3): " << s8(0, 3) << std::endl;

	std::cout << "s8 as char *: " << s8.c_str() << std::endl;

	char const *c_str = s8.c_str();

	return 0;
}
