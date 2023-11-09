#include <cstring>
#include <iostream>

class String
{
	private:
		char *_value;
		int _size;

		void copy(char const *str);
		void copy(String const &str);
	public:
		String();
		String(char const *);
		String(String const &);
		~String();

		String operator=(char const *);
		String operator=(String const &);
		String operator+=(String const &);
		char operator[](int index);

		friend String operator+(String const &str1, String const &str2);
		friend std::ostream& operator<<(std::ostream &stream, String const &str);
		friend bool operator==(String const &str1, String const &str2);
		friend bool operator==(String const &str1, char const *str2);
		friend bool operator!=(String const &str1, String const &str2);
		friend bool operator!=(String const &str1, char const *str2);
};

void String::copy(char const *str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	_size = strlen(str);
	_value = new char[_size + 1];
	strcpy(_value, str);
}

void String::copy(String const &str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	_size = str._size;
	_value = new char[_size + 1];
	strcpy(_value, str._value);
}
String::String() : _size(0)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	_value = new char[1];
	_value[0] = '\0';
}
String::String(char const *str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	copy(str);
}

String::String(String const &str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	copy(str);
}

String::~String()
{
	std::cout << __PRETTY_FUNCTION__ << "\tsize: " << _size << std::endl;

	if(_value != nullptr)
		delete[] _value;
}

String String::operator=(char const *str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if(_value != nullptr)
		delete[] _value;
	copy(str);

	return *this;	
}

String String::operator=(String const &str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if(&str != this)
	{
		if(_value != nullptr)
			delete[] _value;
		copy(str);
	}

	return *this;	
}

String String::operator+=(String const &str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	int new_size = _size + str._size;
	char *new_value = new char[new_size + 1];
	strcpy(new_value, _value);
	strcpy(new_value + _size, str._value);
	delete[] _value;
	_size = new_size;
	_value =  new_value;

	return *this;
}

char String::operator[](int index)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return _value[index];
}

String operator+(String const &str1, String const &str2)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	String result;

	result._size = str1._size + str2._size;
	result._value = new char[result._size + 1];
	strcpy(result._value, str1._value);
	strcpy(result._value + str1._size, str2._value);

	return result;
}

std::ostream& operator<<(std::ostream &stream, String const &str)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	stream << str._value;

	return stream;
}
bool operator==(String const &str1, String const &str2)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return str1._size == str2._size && strcmp(str1._value, str2._value) == 0;
}
bool operator==(String const &str1, char const *str2)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return strcmp(str1._value, str2) == 0;
}
bool operator!=(String const &str1, String const &str2)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return str1._size != str2._size && strcmp(str1._value, str2._value) != 0;
}
bool operator!=(String const &str1, char const *str2)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return strcmp(str1._value, str2) != 0;
}

int main()
{
	String empty;

	String s1 = "Hello, string!";
	std::cout << s1 << std::endl;
	
	s1 = "New string";
	std::cout << s1 << std::endl;

	String s2 = "\t + one more String";
	String s3 = s1 + s2;

	std::cout << s3 << std::endl;
	std::cout << "s3 first letter: '" << s3[0] << "'" << std::endl;

	std::cout << "s1 == s1: " << (s1 == s1) << std::endl;
	std::cout << "s1 != s1: " << (s1 != s1) << std::endl;
	std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
	std::cout << "s1 != s2: " << (s1 != s2) << std::endl;

	s3 += "\t second one mode String";
	std::cout << s3 << std::endl;

	return 0;
}
