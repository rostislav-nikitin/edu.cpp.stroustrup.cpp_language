#ifndef FS_H
#define FS_H

#include <string>
#include <exception>

namespace FileSystem
{
	class FileException : public std::exception
	{
	protected:
		std::string _message;
	public:
		FileException(std::string message);
		virtual char const *what() const noexcept override;
	};

	class FileOpenException : public FileException
	{
	public:
		FileOpenException(std::string &filename, short int fd, int error_number, std::string description = "");
	};

	class FileReadException : public FileException
	{
	public:
		FileReadException(std::string &filename, short int fd, int error_number, std::string description = "");
	};

	class FileWriteException : public FileException
	{
	public:
		FileWriteException(std::string &filename, short int fd, int error_number, std::string description = "");
	};

	enum FileMode
	{
		Read = 1,
		Write = 2,
		Create = 4,
		Append = 8
	};

	inline FileMode operator|(FileMode a, FileMode b)
	{
		return static_cast<FileMode>(static_cast<int>(a) | static_cast<int>(b));
	}

	inline FileMode operator&(FileMode a, FileMode b)
	{
		return static_cast<FileMode>(static_cast<int>(a) & static_cast<int>(b));
	}

	class File
	{
		std::string _filename;
		FileMode _file_mode;
		short _fd;
	public:
		File(std::string filename, FileMode file_mode);
		unsigned int read(char *buffer, unsigned int position, unsigned int size);
		unsigned int write(char const *buffer, unsigned int position, unsigned int size);
		~File();
	};
}

#endif
