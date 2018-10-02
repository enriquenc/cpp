// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/25 19:31:05 by tmaslyan          #+#    #+#             //
//   Updated: 2018/09/25 19:37:23 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	{
		argv++;
		while (*argv)
		{
			while (**argv)
			{
				if (**argv >= 97 && **argv <= 122)
					**argv -= 32;
				std::cout << **argv;
				(*argv)++;
			}
			argv++;
		}
	}
	std::cout << std::endl;
	return (0);
}
