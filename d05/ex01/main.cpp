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
#include "Form.hpp"
#include <iostream>
#include <ctime>

int main()
{
    Form *d;
    try
    {
        d = new Form("check", 1, 151);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete d;
    try
    {
        d = new Form("check", 0, 150);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete d;
    try
    {
        d = new Form("check", 50, 120);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << *d << std::endl;
    Bureaucrat *b = new Bureaucrat("John", 50);
    b->signForm(*d);
    std::cout << *d << std::endl;
    delete d;
    return 0;
}