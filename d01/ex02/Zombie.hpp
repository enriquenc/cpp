// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 18:28:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 18:28:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:

    std::string type;
    std::string name;

    void announce(void);
    Zombie(std::string p_name);
    ~Zombie(void);
};

#endif