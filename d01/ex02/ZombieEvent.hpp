// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:30:33 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 18:30:34 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEEVENT_H
#define ZOMBIEEVENT_H
#include "Zombie.hpp"

class ZombieEvent
{
public:
    std::string type;

    void setZombieType(std::string p_type);
    Zombie* newZombie(std::string name);
    Zombie* randomChump(void);
};

#endif