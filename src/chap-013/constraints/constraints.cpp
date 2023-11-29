#include <iostream>

template<class TDerived, class TBase>
struct DerivedFrom
{
	void constraint(TDerived *d){ TBase* b = d;  }
	DerivedFrom() {void (DerivedFrom::*FnPtr) (TDerived *) = &DerivedFrom::constraint;}
};

template<class T1, class T2>
struct Copyable
{
	void constraint(T1 &a){ T2 b = a; }
	Copyable() { void (Copyable::*ptr)(T1 &a) = &Copyable::constraint; }
};

class IShape
{
	int x, y;
public:
	IShape() : x(0), y(0) { }
	virtual void draw()
	{
		std::cout << "Drawing circle..." << std::endl;
	}
	
};

class Circle : public IShape
{
};

class Dog
{
	int _[10];
public:
	Dog() {}
	virtual void bark()
	{
		std::cout << "Bark... Bark... Bark..." << std::endl;
	}
};

template<class ElementType>
class ShapeCollection
{
private:
	IShape *_values[10];
public:
	ShapeCollection()
	{
//		DerivedFrom<ElementType, IShape>();
		Copyable<ElementType, IShape>();
	}

	void set(unsigned int index, ElementType *value)
	{
		_values[index] = (IShape *)value;
	}
	IShape* get(unsigned int index)
	{
		return static_cast<IShape *>(_values[index]);
	}
};

int main()
{
	ShapeCollection<Circle> circles;
	circles.set(0, new Circle());

	ShapeCollection<Dog> dogs;
	dogs.set(0, new Dog());
	IShape *shape = dogs.get(0);
	shape->draw();

	return 0;
}
