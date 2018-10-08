// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 05:59:19 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/07 05:59:20 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameSpace.hpp"
#include <string>

#define ENEMY_SIZE 3

class GameSpace;

class Enemy
{
private:
    int _start_x;
    int _start_y;

public:

    Enemy(void);
    Enemy(Enemy const &obj);
    Enemy(int start_x, int start_y);
    ~Enemy(void);

    Enemy & operator=(Enemy const & obj);

    void attack (GameSpace & obj);

    int getStartX(void) const;
    int getStartY(void) const;
    void setStartX(int x);
    void setStartY(int y);
};

#endif