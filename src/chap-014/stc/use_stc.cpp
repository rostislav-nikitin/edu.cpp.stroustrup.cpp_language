#include <iostream>

typedef void (*Handler)();
Handler _some_handler;

typedef Handler (*HandlerSetter)(Handler handler);

template<class T>
class HandlerSetterFunctor
{
public:
	T operator()(T value);
};

template<>
Handler HandlerSetterFunctor<Handler>::operator()(Handler value)
{
	Handler temp = _some_handler;
	_some_handler = value;

	return temp;
}


template <class TFn, template<class> class TFnSetter>
class SSTC
{
	TFn _old_func;
	TFnSetter<TFn> _setter;
public:
	SSTC(TFn func)
	{
		_old_func = _setter(func);
	}
	~SSTC()
	{
		_setter(_old_func);
	}
};

template<class FNT, HandlerSetter handlerSetter>
class STC
{
	FNT _old_func;
public:
	STC(FNT func);
	~STC();
};


template<class FNT, HandlerSetter handlerSetter>
STC<FNT, handlerSetter>::STC(FNT func)
{
//	FNTSetter setter;
//	_old_func = setter.set(func);
	_old_func = handlerSetter(func);
}


template<class FNT, HandlerSetter handlerSetter>
STC<FNT, handlerSetter>::~STC()
{
//	FNTSetter setter;
//	setter.set(_old_func);
	handlerSetter(_old_func);
}



/*
struct HandlerSetter
{
	Handler set(Handler);
};
*/

Handler SomeHandlerSetter(Handler handler)
{
	Handler temp = _some_handler;
	_some_handler = handler;

	return temp;
}
/*
Handler HandlerSetter::set(Handler handler)
{
	Handler temp = _some_handler;
	_some_handler = handler;

	return temp;
}
*/

void initial_handler()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void overriding_handler()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
/*
	HandlerSetter init;
	init.set(&initial_handler);
*/
	SomeHandlerSetter(&initial_handler);
	_some_handler();

	// STC scope
	{
		/*
		STC<Handler, HandlerSetter> stc(&overriding_handler);
		_some_handler();
		*/
		STC<Handler, SomeHandlerSetter> stc(&overriding_handler);
		_some_handler();
	}
	_some_handler();

	//SSTC
	{
		SSTC<Handler, HandlerSetterFunctor> sstc(&overriding_handler);
		_some_handler();
	}
	_some_handler();

	return 0;
}
