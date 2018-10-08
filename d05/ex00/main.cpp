// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/08 13:39:09 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/08 13:39:10 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include <iostream>
#include <ctime>

int main()
{
    Bureaucrat *d, *r, *c, *a;

    srand(time(NULL));
    try
    {
        d = new Bureaucrat("John", 0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        r = new Bureaucrat("John", 151);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        c = new Bureaucrat("Jake", 1);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        a = new Bureaucrat("Bill", 150);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
    std::cout << *c << std::endl << *a << std::endl;
    return 0;
}