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
#include "Array.hpp"

int main( void )
{
    Array<int> d(15);
    for (int i = 0; i < 15; i++)
    {
        d[i] = i;
        std::cout << d[i] << std::endl;
    }
    try {
        d[-1] = 5;
        std::cout << d[-1];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        d[15] = 5;
        std::cout << d[15];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    Array<char> a(10);
    for (int i = 0; i < 10; i++)
    {
        a[i] = 65 + i;
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl;
    Array<char> b = a;
    for (int i = 0; i < 10; i++)
    {
        b[i] = 65 + i + 1;
        std::cout << b[i] << ' ' << a[i] << std::endl;
    }
    return 0;
}
