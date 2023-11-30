#include "use_fs.h"

int main()
{
	unsigned int Read_Buffer_Size = 512;

	// Create file(if not exists) and write
	{
		FileSystem::File file("dummy.txt", FileSystem::FileMode::Write | FileSystem::FileMode::Create | FileSystem::FileMode::Append);

		char write_buffer[] = "Hello, World!\n";
		unsigned int written_bytes = file.write(write_buffer, 0, strlen(write_buffer));
		std::cout << "Written bytes: " << written_bytes << std::endl;
	}

	// Read from file
	{
		FileSystem::File file("dummy.txt", FileSystem::FileMode::Read);
		char read_buffer[Read_Buffer_Size + 1];
		unsigned int read_bytes;

		while((read_bytes = file.read(read_buffer, 0, Read_Buffer_Size)) != 0)
		{
			read_buffer[read_bytes] = '\0';
			std::cout << read_buffer << std::endl;
		}
	}

	return 0;
}
