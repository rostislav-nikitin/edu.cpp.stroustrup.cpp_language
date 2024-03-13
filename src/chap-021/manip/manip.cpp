#include <ostream>
#include <iostream>


// WFManip
class WFManip
{
	int _width;
	char _fill;

public:
	WFManip(int width = 16, char fill = '#');
	std::ostream &operator()(std::ostream &stream) const;
};

WFManip::WFManip(int width, char fill) : _width(width), _fill(fill)
{
}

std::ostream &WFManip::operator()(std::ostream &stream) const
{
	stream.width(_width);
	stream.fill(_fill);

	return stream;
}

std::ostream &operator<<(std::ostream &stream, WFManip const &wfManip)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	wfManip(stream);

	return stream;
}

// smainp
struct wfmanip_s
{
	int width;
	char fill;
	std::ostream &(*f)(std::ostream &stream, int width, char fill);
};

std::ostream &setwf(std::ostream &stream, int width, char fill)
{
	stream.width(width);
	stream.fill(fill);

	return stream;
}

std::ostream & operator<<(std::ostream &stream, wfmanip_s const &wfManip)
{
	return wfManip.f(stream, wfManip.width, wfManip.fill);
}

wfmanip_s wf(int width, char fill)
{
	return wfmanip_s{width, fill, setwf};
}


// w16
std::ostream &w16(std::ostream &stream)
{
	stream.fill('#');
	stream.width(16);

	return stream;
}

int main()
{
	std::cout << w16 << 100 << std::endl;
	std::cout << WFManip(16, '#') << 100 << std::endl;
	std::cout << wf(16, '#') << 100 << std::endl;
	
	return EXIT_SUCCESS;
}
