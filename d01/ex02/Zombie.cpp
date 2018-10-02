// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:28:49 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 18:28:50 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
    std::cout << '<' << this->name << " (" << this->type << ")> Brrraiiiiinnnssss..." << std::endl; 
}

Zombie::Zombie(std::string p_name)
{
    std::cout << "Zombie " << p_name << " is created" << std::endl;
    this->name = p_name;
}

Zombie::~Zombie(void)
{
    std::cout << '<' << this->name << " (" << this->type << ")>" << " Goodbye." << std::endl;
}