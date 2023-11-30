#include "fs_impl.h"

#include <iostream>

namespace FileSystem
{
		//FileException
		FileException::FileException(std::string message) : _message(message)
		{
		}

		char const *FileException::what() const noexcept
		{
			return _message.c_str();
		}

		//FileOpenException
		FileOpenException::FileOpenException(std::string &filename, short int fd, int error_number, std::string description) 
			: FileException( 
					(std::string("Error while opening file with name=\"") + filename + std::string("\";") + 
					std::string(" file descriptor#=") + std::to_string(fd) + std::string(";") + 
					std::string(" errno=") + std::to_string(error_number) + std::string(";") + 
				  	std::string(" description=") + description + std::string(".")))
		{
		}

		FileReadException::FileReadException(std::string &filename, short int fd, int error_number, std::string description) 
			: FileException( 
					(std::string("Error while reading from file with name=\"") + filename + std::string("\";") + 
					std::string(" file descriptor#=") + std::to_string(fd) + std::string(";") + 
					std::string(" errno=") + std::to_string(error_number) + std::string(".") + 
				  	std::string(" description=") + description + std::string(".")))
		{
		}
		FileWriteException::FileWriteException(std::string &filename, short int fd, int error_number, std::string description) 
			: FileException( 
					(std::string("Error while writing to file with name=\"") + filename + std::string("\";") + 
					std::string(" file descriptor#=") + std::to_string(fd) + std::string(";") + 
					std::string(" errno=") + std::to_string(error_number) + std::string(";") +
				  	std::string(" description=") + description + std::string(".")))
		{
		}

		//File
		File::File(std::string filename, FileMode file_mode) : _filename(filename), _file_mode(file_mode)
		{
			int flags = 0;
			if(_file_mode & FileMode::Read && _file_mode & FileMode::Write)
				flags = O_RDWR;
			else if(_file_mode & FileMode::Read)
				flags = O_RDONLY;
			else if(_file_mode & FileMode::Write)
				flags = O_WRONLY;
			else
				throw FileOpenException(_filename, _fd, errno, "Read, Write or both mode should be specified.");

			if(_file_mode & FileMode::Create)
				flags |= O_CREAT;
			if(_file_mode & FileMode::Append)
				flags |= O_APPEND;

					
			_fd = ::open(_filename.c_str(), flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

			if(_fd < 0)
				throw FileOpenException(_filename, _fd, errno, "OS can not open file.");
		}

		unsigned int File::read(char *buffer, unsigned int position, unsigned int size)
		{
			int count = ::read(_fd, (buffer + position), size);

			if(count < 0)
				throw FileReadException(_filename, _fd, errno, "read bytes: " + std::to_string(count));

			return static_cast<unsigned int>(count);
		}

		unsigned int File::write(char const *buffer, unsigned int position, unsigned int size)
		{
			int count = ::write(_fd, (buffer + position), size);

			if(count < 0)
				throw FileWriteException(_filename, _fd, errno, "written bytes: " + std::to_string(count));

			return static_cast<unsigned int>(count);
		}

		File::~File()
		{
			if(_fd > 0)
				::close(_fd);
		}
}
