
#include <iostream>
#include "Computor.hpp"

int		main(int argc, char **argv)
{
	Computor		computor;
	int				i;

	if (argc != 2)
	{
		std::cout << "Usage : ./" << argv[0] << " <equation>" << std::endl;
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		try
			computor.treatEquation(argv[i]);
		catch (std::exception & e)
			std::cout << "Error on equation number " << i << " : " << e.what{} << std::endl;
	}
	return (0);
}
