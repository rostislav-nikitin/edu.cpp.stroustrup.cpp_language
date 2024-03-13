#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Number" << "\tName of prod" << "\tPrice of prod" << std::endl;
	std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
	std::cout.fill('#');
	std::cout.width(6);
	std::cout << 1 << "\t";
	
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	std::cout.fill('#');
	std::cout.width(12);
	std::cout << "Sobak" << "\t";
	
	std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
	std::cout.fill('#');
	std::cout.width(13);
	std::cout.precision(13);
	std::cout << 1210.56 << std::endl;

	std::cout << std::setprecision(12) << std::right << std::setfill('#') << std::setw(6) << 2 << "\t" << std::left << std::setw(12) << "Pes OK" << "\t" << std::setw(13) << std::right << 9.99 << std::endl;
	
	return EXIT_SUCCESS;
}
