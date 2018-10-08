// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 04:43:01 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/07 04:43:01 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"


Player::Player(void):   _start_x(0),
                        _start_y(0),
                        _level(0),
                        _score(0),
                        _hit_points(10)
{

}

Player::Player(int start_x, int start_y):   _start_x(start_x),
                                            _start_y(start_y),
                                            _level(0),
                                            _score(0),
                                            _hit_points(10)
{
    
}

Player::Player(Player const &obj)
{
    *this = obj;
}

Player::~Player(void)
{

}

Player & Player::operator=(Player const & obj)
{
    _start_x = obj._start_x;
    _start_y = obj._start_y;
    _level = obj._level;
    _score = obj._score;
    return *this;
}

void Player::attack(GameSpace & game)
{
    game.put_player_shot(_start_x + (PLAYER_SIZE - 1), _start_y + PLAYER_SIZE / 2);
}

void Player::takeDamage(int damage)
{
    if (_hit_points - damage > 0)
        _hit_points -= damage;
    else
        _hit_points = 0;
}

int Player::getStartX(void) const
{
    return _start_x;
}

int Player::getStartY(void) const
{
    return _start_y;
}

int Player::getLevel(void) const
{
    return _level;
}

int Player::getScore(void) const
{
    return _score;
}

int Player::getHp(void) const
{
    return _hit_points;
}

void Player::setStartX(int x)
{
    _start_x = x;
}

void Player::setStartY(int y)
{
    _start_y = y;
}

void Player::setLevel(int level)
{
    _level = level;

}

void Player::setScore(int score)
{
    _score = score;
}

void Player::setHp(int hp)
{
    _hit_points = hp;
}