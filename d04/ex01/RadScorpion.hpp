// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 19:06:47 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 19:06:47 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RadScorpion_HPP
#define RadScorpion_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:

    RadScorpion(void);
    RadScorpion(int hp, std::string const & type);
    ~RadScorpion(void);

    void takeDamage(int);
};

#endif