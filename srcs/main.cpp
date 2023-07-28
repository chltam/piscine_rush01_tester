#include "../includes/Grid.hpp"


int main(int argc, char** argv)
{
	if (argc != 2)
		exitMessage("tester: invalid number of argument");

	Grid	grid((std::string(argv[1])));
	
	grid.format_check();
	grid.logic_check();
	exitMessage("OK!");

	return (0);
}