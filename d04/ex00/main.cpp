// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:47 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:48 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"
#include "Virgin.hpp"
#include "Sorcerer.hpp"
#include "Frog.hpp"
#include <iostream>


int main()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    Virgin julia("Julia");
    Frog frog("Frog");


    std::cout << robert << jim << joe << julia << frog;
    robert.polymorph(jim);
    robert.polymorph(joe);
    robert.polymorph(julia);
    robert.polymorph(frog);
    return 0;
}