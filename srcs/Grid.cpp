#include "../includes/Grid.hpp"

Grid::Grid(std::string views)
{
	readMatrixFromInput();

	error_ = false;
}

void	Grid::readMatrixFromInput()
{
	std::string buffer;

	while (std::getline(std::cin, buffer, '\0')){
		rawOutput_ += buffer;
	}
}

const std::string&	Grid::get_rawOutput(){
	return (rawOutput_);
}

bool	Grid::has_error(){
	return (error_);
}

