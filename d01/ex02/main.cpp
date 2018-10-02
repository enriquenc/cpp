// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:30:41 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 18:30:42 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
 
#include "ZombieEvent.hpp"
#include <iostream>

int main()
{
    ZombieEvent z_event;
    srand(time(0));

    Zombie* z = z_event.randomChump();
    z->announce();

    Zombie* b = z_event.randomChump();
    b->announce();
    
    z_event.setZombieType("ololo");
    Zombie* a = z_event.newZombie("Kek");
    a->announce();

    delete a;
    delete b;
    delete z;
    return 0;
}