#include "../includes/Grid.hpp"

Grid::Grid(std::string views)
{
	readMatrixFromInput();

	viewsStr_ = views;
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
	if (outputStr_.empty() || outputStr_ == "\n")
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
	for (int n = 0; n < row_.size(); n++){
		for (int i = 0; i < row_[n].size(); i++){
			
			std::cout << row_[n][i];
			if (i != row_[n].size() - 1)
				std::cout << " ";
		}
		std::endl(std::cout);
		// std::cout << "------" << n << "-------\n";
	}
	for (int n = 0; n < column_.size(); n++){
		for (int i = 0; i < column_[n].size(); i++){
			
			std::cout << column_[n][i];
			if (i != column_[n].size() - 1)
				std::cout << " ";
		}
		std::endl(std::cout);
		// std::cout << "------" << n << "-------\n";
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
	std::string	line;
	std::istringstream	line_iss(outputStr_);
	
	// setup row vector
	while (std::getline(line_iss, line))
	{
		std::istringstream	iss(line);
		std::vector<int>	temp;
		int	number;

		while (iss >> number)
			temp.push_back(number);
		if (iss.fail() && !iss.eof())
			return (-1);
		row_.push_back(temp);
	}

	// check output size
	if (row_.size() != size_)
		return (-1);
	for (int n = 0; n < row_.size(); n++){
		if (row_[n].size() != size_)
			return (-1);
	}
	
	// setup column vector
	for (int n = 0; n < size_; n++){
		std::vector<int>	temp;
		
		for (int i = 0; i < row_.size(); i++){
			temp.push_back(row_[i][n]);
		}
		column_.push_back(temp);
	}
	return (0);
}

void	Grid::logic_check()
{
	if (duplicateCheck() == -1)
		exitMessage("KO!");
}

int	Grid::duplicateCheck()
{
	
	return (0);
}