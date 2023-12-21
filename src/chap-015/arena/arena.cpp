#include <iostream>
#include <cstring>

class Arena
{
public:
	virtual void *allocate(size_t size) = 0;
	virtual void deallocate(void *ptr) = 0;

};

class ExprArena : public Arena
{
private:
	char buffer[1024];
	unsigned int index = 0;
public:
	void *allocate(size_t size) override
	{
		unsigned current_index = index;
		index += size;

		return static_cast<void *>(&buffer[current_index]);
	}

	void deallocate(void *ptr) override
	{
	}
};

class Expr
{
private:
	static ExprArena _arena;
	int _x;

public:
//	Expr() : _x(0) { }

	int get_x() const
	{
		return _x;
	}

	void set_x(int value)
	{
		_x = value;
	}

	virtual Expr *clone()
	{
		Expr *result = new(&_arena) Expr(*this);
//		memcpy(result, this, sizeof(*this));

		return result;
	}

	void *operator new(size_t size, ExprArena *arena)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		return arena->allocate(size);
	}

	void operator delete(void *ptr)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
//		arena->deallocate(this);
	}
	virtual ~Expr(){ }
};
ExprArena Expr::_arena = ExprArena();

int main()
{
	Expr x1;
	x1.set_x(101);
	std::cout << x1.get_x() << std::endl;

	Expr x3(x1);
	std::cout << x3.get_x() << std::endl;

	Expr *x2 = x1.clone();
	std::cout << x2->get_x() << std::endl;

	x2->~Expr();
	delete x2;

	return EXIT_SUCCESS;
}
