// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 04:42:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/07 04:42:57 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAY_HPP
#define PLAY_HPP

#include "GameSpace.hpp"
#include <string>

#define PLAYER_SIZE 3

class GameSpace;


class Player
{
private:

    int _start_x;
    int _start_y;
    int _level;
    int _score;
    int _hit_points;



public:

    Player(void);
    Player(Player const &obj);
    Player(int start_x, int start_y);
    ~Player(void);

    Player & operator=(Player const & obj);

    void attack (GameSpace & game);
    void takeDamage(int damage);
    
    int getStartX(void) const;
    int getStartY(void) const;
    int getLevel(void) const;
    int getScore(void) const;
    int getHp(void) const;
    void setStartX(int x);
    void setStartY(int y);
    void setLevel(int level);
    void setScore(int score);
    void setHp(int hp);
};

#endif