#ifndef _GRID_H_
#define _GRID_H_

#include "../includes/rush01_tester.hpp"

class Grid{

public:
	Grid(){};
	Grid(std::string views);
	~Grid(){};

	const std::string& get_rawOutput();
	bool	has_error();

private:
	std::string	rawOutput_;
	std::vector<std::vector<int>> pov_;
	std::vector<std::vector<int>> grid_;

	bool	error_;

private:
	void	readMatrixFromInput();


};

#endif