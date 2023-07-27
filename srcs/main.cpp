#include "../includes/rush01_tester.hpp"
#include "../includes/Grid.hpp"

std::string	readMatrixFromInput()
{
	std::string buffer;
	std::string	matrixStr;

	while (std::getline(std::cin, buffer, '\0')){
		matrixStr += buffer;
	}
	return (matrixStr);
}

int main(int argc, char** argv)
{
	if (argc != 2){
		std::cout << "tester: wrong number of argument" << std::endl;
		return (0);
	}

	Grid	grid((std::string(argv[1])));

	return (0);
}