// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 19:06:47 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 19:06:47 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:

    SuperMutant(void);
    SuperMutant(int hp, std::string const & type);
    ~SuperMutant(void);

    void takeDamage(int);
};

#endif