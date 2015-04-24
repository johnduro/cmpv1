// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/24 19:00:03 by mle-roy           #+#    #+#             //
//   Updated: 2015/04/24 19:01:26 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Computor.hpp"

int		main(int argc, char **argv)
{
	Computor			computor;
	int                 i;
	bool				arg = false;
	bool				debug = false;

	for (i = 1; i < argc; i++)
	{
		if (std::string(argv[i]) == "-D")
			debug = true;
		else if (std::string(argv[i]) == "-F")
			arg = true;
	}
	if (argc < 2 || ((debug || arg) && argc == 2) || (debug && arg && argc == 3))
	{
		std::cout << "Usage : " << argv[0] << " [-D] [-F] <equation>" << std::endl;
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (std::string(argv[i]) != "-F" && std::string(argv[i]) != "-D")
		{
			try
			{
				computor.treatEquation(argv[i], arg, debug);
			}
			catch (std::exception & e)
			{
				std::cout << "Error on equation : '" << argv[i] << "' : " << e.what() << std::endl;
			}
		}
	}
	return (0);
}
