// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:35:53 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 22:35:55 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string& ref = str;
    std::string* ptr = &str;
    std::cout << ref << std::endl << *ptr << std::endl;
    return 0;
}