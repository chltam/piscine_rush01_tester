#ifndef _GRID_H_
#define _GRID_H_

#include "../includes/utils.hpp"

class Grid{

public:
	Grid(){};
	Grid(std::string views);
	~Grid(){};

	const std::string& get_outputStr();
	void	format_check();
	bool	has_error();

private:
	std::string	outputStr_;
	std::string	viewsStr_;
	

	std::vector<std::vector<int>> pov_;
	std::vector<std::vector<int>> grid_;

	bool	error_;
	size_t	size_;

private:
	void	readMatrixFromInput();
	int		parseViews();
	int		parseOutput();

};

#endif