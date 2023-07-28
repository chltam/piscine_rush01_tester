#ifndef _GRID_H_
#define _GRID_H_

#include "../includes/utils.hpp"
#include <set>
#include <unordered_set>

class Grid{

public:
	Grid(){};
	Grid(std::string views);
	~Grid(){};

	
	void	format_check();
	void	logic_check();


private:
	std::string	outputStr_;
	std::string	viewsStr_;
	

	std::vector<std::vector<int>>	pov_;
	std::vector<std::vector<int>>	row_;
	std::vector<std::vector<int>>	column_;


	size_t	size_;

private:
	void	readMatrixFromInput();
	int		parseViews();
	int		parseOutput();
	int		duplicateCheck();
	int		rowCheck();
	int		columnCheck();

};

#endif