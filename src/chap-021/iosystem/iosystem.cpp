#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

namespace iosystem
{
	// Stream buffer
	template<class CharT, class Traits = std::char_traits<CharT>>
	class filebuf_base : public std::basic_streambuf<CharT, Traits>
	{
		using Base = std::basic_streambuf<CharT, Traits>;
		using int_type = typename Base::int_type;
		
		static int const BUFFER_SIZE_DEFAULT = 16;
	private:
		std::vector<CharT> _in_memory_file;
		char _buffer[BUFFER_SIZE_DEFAULT];

	protected:
		virtual int_type sync() override;
		virtual int_type overflow(int_type ch);

	public:
		filebuf_base();
		std::vector<CharT> get_in_memory_file();
	};

	
	template<class CharT, class Traits>
	filebuf_base<CharT, Traits>::filebuf_base() :
		std::basic_streambuf<CharT, Traits>()//, _in_memory_file(in_memory_file)
	{
		std::fill_n(_buffer, BUFFER_SIZE_DEFAULT, 0);
		std::basic_streambuf<CharT, Traits>::setp(&_buffer[0], &_buffer[0] + BUFFER_SIZE_DEFAULT);
	}
	
	template<class CharT, class Traits>
	typename std::basic_streambuf<CharT, Traits>::int_type filebuf_base<CharT, Traits>::sync()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		CharT *buf_begin = std::basic_streambuf<CharT, Traits>::pbase();
		CharT *buf_end = std::basic_streambuf<CharT, Traits>::pptr();

		while(buf_begin != buf_end)
		{
			_in_memory_file.push_back(*buf_begin);
			++buf_begin;
		}

		std::basic_streambuf<CharT, Traits>::setp(&_buffer[0], &_buffer[0] + BUFFER_SIZE_DEFAULT);
		
		return 0;
	}

	template<class CharT, class Traits>
	typename std::basic_streambuf<CharT, Traits>::int_type filebuf_base<CharT, Traits>::overflow(
	    typename std::basic_streambuf<CharT, Traits>::int_type ch)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		
		std::basic_streambuf<CharT, Traits>::overflow(ch);

		CharT *buf_begin = std::basic_streambuf<CharT, Traits>::pbase();
		CharT *buf_end = std::basic_streambuf<CharT, Traits>::pptr();

		while(buf_begin != buf_end)
		{
			_in_memory_file.push_back(*buf_begin);
			++buf_begin;
		}

		std::basic_streambuf<CharT, Traits>::setp(&_buffer[0], &_buffer[0] + BUFFER_SIZE_DEFAULT);
		std::basic_streambuf<CharT, Traits>::sputc(ch);


		return 0;
	}
	
	template<class CharT, class Traits>
	std::vector<CharT> filebuf_base<CharT, Traits>::get_in_memory_file()
	{
		return _in_memory_file;
	}
	
	// Streams
	// Out file stream
	template<class CharT, class Traits = std::char_traits<CharT>>
	class ofstream_base : public std::basic_ios<CharT, Traits>
	{
	private:
		filebuf_base<CharT, Traits> _buffer;
		//		std::vector<CharT> &_in_memory_file;
		
	public:
		ofstream_base();
		
		ofstream_base& operator<<(int value);
		ofstream_base& operator<<(float value);
		
		ofstream_base & put(CharT value);

		void flush();

		filebuf_base<CharT, Traits> *rdbuf();

		ofstream_base & operator<<(filebuf_base<CharT, Traits> &buf);
		
	};

	template<class CharT, class Traits>
	ofstream_base<CharT, Traits>::ofstream_base()
		: std::basic_ios<CharT, Traits>(&_buffer)
		  //n_memory_file(in_memory_file)
	{
	}

	template<class CharT, class Traits>
	ofstream_base<CharT, Traits>& ofstream_base<CharT, Traits>::operator<<(int value)
	{
		int size = sizeof(int) * 8;
		int start = size - 1;
		int end = start - 7;

		while(start > 0)
		{
			int current = value;
			
			current >>= end;
			current &= 0xff;

			put((char)current);
			//			std::cout << current << "::";

			start = end - 1;
			end = start - 7;

			//std::cout << start << "::" << end << std::endl;
		}
		//		std::cout << std::endl;	   
		
		return *this;
	}
	
	template<class CharT, class Traits>
	ofstream_base<CharT, Traits>& ofstream_base<CharT, Traits>::operator<<(float value)
	{
		return *this;
	}
	
	template<class CharT, class Traits>
	ofstream_base<CharT, Traits>& ofstream_base<CharT, Traits>::put(CharT const value)
	{
		//put(value);
		_buffer.sputc(value);
		return *this;
	}

	template<class CharT, class Traits>
	void ofstream_base<CharT, Traits>::flush()
	{
		//put(value);
		//		*this << _buffer;
		//std::cout << _buffer._buffer[0] << std::endl;
		_buffer.pubsync();
		
	}
	
	template<class CharT, class Traits>
	filebuf_base<CharT, Traits>* ofstream_base<CharT, Traits>::rdbuf()
	{
		return &_buffer;
	}
	
	template<class CharT, class Traits>
	ofstream_base<CharT, Traits> & ofstream_base<CharT, Traits>::operator<<(filebuf_base<CharT, Traits> &buf)
	{
		//		std::for_each(value.begin(), value.end(), [&stream](char const &ch){ stream.put(ch); });
		std::cout << buf.pbase() << std::endl;
			//pptr
			//epptr

		return *this;
	}	


	
	// Common types aliases
	typedef ofstream_base<char> ofstream;

	// Opetations
	template<class CharT, class Traits = std::char_traits<CharT>>
	ofstream_base<CharT, Traits> & operator<<(ofstream_base<CharT, Traits> &stream, CharT const value)
	{
		stream.put(value);
		
		return stream;
	}

   	template<class CharT, class Traits = std::char_traits<CharT>>
	ofstream_base<CharT, Traits> & operator<<(ofstream_base<CharT, Traits> &stream, std::string value)
	{
		std::for_each(value.begin(), value.end(), [&stream](char const &ch){ stream.put(ch); });

		return stream;
	}
}


int main()
{

	iosystem::ofstream test;

	test << "aaaaaaaaaaaaaaaa";

	std::cout << "In memory file [BEFORE FLUSH]->" << std::endl;
	std::vector<char> in_memory_file = test.rdbuf()->get_in_memory_file();
	std::copy(in_memory_file.begin(), in_memory_file.end(), std::ostream_iterator<char>(std::cout, ", "));
	std::cout << std::endl;

	test.flush();

	std::cout << "In memory file [AFTER FLUSH]->" << std::endl;
	in_memory_file = test.rdbuf()->get_in_memory_file();
	std::copy(in_memory_file.begin(), in_memory_file.end(), std::ostream_iterator<char>(std::cout, ", "));
	std::cout << std::endl;

	test << "bbbbbbbbbbbbbbbb";
	test.flush();
	
	std::cout << "In memory file [AFTER FLUSH]->" << std::endl;
	in_memory_file = test.rdbuf()->get_in_memory_file();
	std::copy(in_memory_file.begin(), in_memory_file.end(), std::ostream_iterator<char>(std::cout, ", "));
	std::cout << std::endl;

	test << "ccccccccccccccccc";
	std::cout << "In memory file [AFTER FLUSH]->" << std::endl;
	in_memory_file = test.rdbuf()->get_in_memory_file();
	std::copy(in_memory_file.begin(), in_memory_file.end(), std::ostream_iterator<char>(std::cout, ", "));
	std::cout << std::endl;

	test << "d";
	test.flush();
	std::cout << "In memory file [AFTER FLUSH]->" << std::endl;
	in_memory_file = test.rdbuf()->get_in_memory_file();
	std::copy(in_memory_file.begin(), in_memory_file.end(), std::ostream_iterator<char>(std::cout, ", "));
	std::cout << std::endl;

	
	return EXIT_SUCCESS;
}
