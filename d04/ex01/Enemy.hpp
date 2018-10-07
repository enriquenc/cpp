// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:54:38 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:54:38 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <iostream>

class Enemy
{
private:

    int             _hit_points;
    std::string     _type;

public:

    Enemy(void);
    Enemy(int hp, std::string const & type);
    Enemy(Enemy const & obj);
    virtual ~Enemy();
    Enemy & operator=(Enemy const &obj);


    std::string virtual getType(void) const;
    int getHP(void) const;

    virtual void takeDamage(int damage);
};

#endif