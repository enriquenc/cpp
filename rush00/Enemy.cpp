// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 05:59:15 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/07 05:59:16 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy(void): _start_x(0),
                    _start_y(0)
{}

Enemy::Enemy(int start_x, int start_y):     _start_x(start_x),
                                            _start_y(start_y)
{
}

Enemy::Enemy(Enemy const & obj)
{
    *this = obj;
}

Enemy::~Enemy(void){}

Enemy & Enemy::operator=(Enemy const & obj)
{
    _start_x = obj._start_x;
    _start_y = obj._start_y;
    return *this;
}

void Enemy::attack(GameSpace & obj)
{
    obj.put_enemy_shot(_start_x - 1, _start_y - (ENEMY_SIZE / 2));
}

int Enemy::getStartX(void) const
{
    return _start_x;
}

int Enemy::getStartY(void) const
{
    return _start_y;
}

void Enemy::setStartX(int x)
{
    _start_x = x;
}

void Enemy::setStartY(int y)
{
    _start_y = y;
}