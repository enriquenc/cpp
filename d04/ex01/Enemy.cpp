// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:54:41 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:54:42 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy(){}

Enemy::Enemy(int hp, std::string const & type): _hit_points(hp),
                                                _type(type)
{}

Enemy::Enemy(Enemy const & obj)
{
    *this = obj;
}

Enemy::~Enemy(void){}

Enemy & Enemy::operator=(Enemy const & obj)
{
    _hit_points = obj._hit_points;
    _type = obj._type;
    return *this;
}

std::string Enemy::getType(void) const
{
    return _type;
}

int Enemy::getHP(void) const
{
    return _hit_points;
}

void Enemy::takeDamage(int damage)
{
    _hit_points = _hit_points - damage;
}