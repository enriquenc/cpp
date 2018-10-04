// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 20:20:49 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 20:20:50 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << std::cin.rdbuf();
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if ((std::string)argv[i] == "-")
			{
				std::cout << std::cin.rdbuf();
				std::cin.clear();
				std::cout.clear();
				freopen(0, "r", stdin);
			}
			else
			{
				std::stringstream file_buf;
				std::ifstream file(argv[i]);
				file_buf << file.rdbuf();
				std::cout << file_buf.str();
			}
			if(errno)
				std::cerr << argv[0] << ": " << argv[i] << ' ' << std::strerror(errno) << std::endl;
		}
	}
	return 0;
}