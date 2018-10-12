// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/11 14:30:59 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/11 14:31:02 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include "easyfind.hpp"


int main( void )
{
    std::list<int> lst;
    lst.push_back(15);
    lst.push_back(1124);
    lst.push_back(213);
    try
    {
        std::cout << *easyfind(lst, 11) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << *easyfind(lst, 1124) << std::endl;
    std::cout << *std::find(lst.begin(),lst.end(), 1124) << std::endl;
    return 0;
}
