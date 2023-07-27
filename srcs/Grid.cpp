#include "../includes/Grid.hpp"

Grid::Grid(std::string views)
{
	readMatrixFromInput();

	viewsStr_ = views;
	error_ = false;
}

void	Grid::readMatrixFromInput()
{
	std::string buffer;

	while (std::getline(std::cin, buffer, '\0')){
		outputStr_ += buffer;
	}
}

void	Grid::format_check()
{
	// KO on empty output
	if (outputStr_.empty())
		exitMessage("KO!");
	
	// parse view into vector vector
	// basic error checking
	// KO if no "Error\n" when input is invalid
	if (parseViews() == -1)
		exitMessage((outputStr_ == "Error\n") ? "OK!" : "KO!");
	
	// parse output into vector vector
	// simular to view parsing
	// check for duplicated value
	if (parseOutput() == -1)
		exitMessage("KO!");
	//printing test
	for (int n = 0; n < pov_.size(); n++){
		for (int i = 0; i < pov_[n].size(); i++){
			std::cout << pov_[n][i] << std::endl;
		}
		std::cout << "------" << n << "-------\n";
	}
}

int	Grid::parseViews()
{
	std::istringstream	iss(viewsStr_);
	std::vector<int>	viewVec;
	int	number;

	while(iss >> number){
		viewVec.push_back(number);
	}
	//check for non numeric
	if (iss.fail() && !iss.eof())
		return (-1);
	
	//total number of view should be multiplier of 4 
	if (viewVec.size() % 4 != 0)
		return (-1);
	size_ = viewVec.size() / 4;

	for (int n = 0; n < 4; n++){
		std::vector<int>	temp_vec;
		pov_.push_back(temp_vec);
		
		for (int start = n * size_, end = start + size_; start < end; start++){
			pov_[n].push_back(viewVec[start]);
		}
	}
	return (0);
}

int	Grid::parseOutput()
{
	
}

const std::string&	Grid::get_outputStr(){
	return (outputStr_);
}

bool	Grid::has_error(){
	return (error_);
}

