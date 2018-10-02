// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 21:13:50 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 21:13:51 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"
#include <ctime>
#include <iostream>

ZombieHorde::ZombieHorde(int N)
{
    this->number_of_zombies = N;
    this->zombies = new Zombie[N];
    set_name();
    set_type();
}

ZombieHorde::~ZombieHorde()
{
    delete[] this->zombies;
}

void ZombieHorde::set_name()
{
    std::string names[] = {"Taras", "Ned", "John", "Xxxtentacion", "Leo"};
    for(int i = 0; i < this->number_of_zombies; i++)
        zombies[i].name = names[rand()%5];
}

void ZombieHorde::set_type()
{
    std::string types[] = {"Ox", "Oy", "Oz", "Francuz", "Lil flex young"};
    for(int i = 0; i < this->number_of_zombies; i++)
        zombies[i].type = types[rand()%5];
}

void ZombieHorde::announce()
{
    for(int i = 0; i < this->number_of_zombies; i++)
        zombies[i].announce();
}