#include "Fixed.hpp"
#include "EvalExpr.hpp"

#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream
#include <string>


int main (int argc, char **argv) 
{
	if (argc == 2)
	{
		EvalExpr b;
		std::cout << b.calculate(argv[1]) << std::endl;
	}
	//system("leaks eval_expr");
	return 0;
}