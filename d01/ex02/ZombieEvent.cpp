// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:30:08 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 18:30:09 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include <ctime>
//void ZombieEvent::setZombieType();

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie* z = new Zombie(name);
    z->type = this->type;
    return z;
}

void ZombieEvent::setZombieType(std::string p_type)
{
    this->type = p_type;
}

Zombie* ZombieEvent::randomChump(void)
{
    std::string names[] = {"Taras", "Ned", "John", "Xxxtentacion", "Leo"};
    std::string types[] = {"Ox", "Oy", "Oz", "Francuz", "Lil flex young"};

    Zombie* z = new Zombie(names[rand() % 5]);
    z->type = types[rand() % 5];
    return z;
}