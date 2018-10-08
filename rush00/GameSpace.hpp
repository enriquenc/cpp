// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameSpace.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 01:22:29 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/07 01:22:30 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMESPACE_HPP
#define GAMESPACE_HPP

#define HEIGHT 25
#define WIDTH 100

#include "Enemy.hpp"
#include "Player.hpp"
#include <string>
#include <iostream>
#include <ncurses.h>

class Enemy;
class Player;

typedef struct  s_shot
{
    int current_x;
    int current_y;
    char symbol;
    struct s_shot *next;
    //struct s_shot *prev;
}               t_shot;

typedef struct  s_enemy
{
    Enemy *enemy;
    struct s_enemy *next;
    //struct s_enemy *prev;
}               t_enemy;



class GameSpace
{
private:

    t_shot *_player_shots;
    t_shot *_enemy_shots;
    t_enemy *_enemies;
    
    int _count_player_shots;
    int _count_enemy_shots;
    int _count_enemies;

    Player *_player;

    t_shot *_player_shots_start;
    t_shot *_enemy_shots_start;
    t_enemy *_enemies_start;

    WINDOW * _win;
public:
    GameSpace(void);
    GameSpace(GameSpace const & obj);
    ~GameSpace(void);

    GameSpace & operator=(GameSpace const &obj);

    void put_player_shot(int x, int y);
    void put_enemy_shot(int x, int y);
    void put_enemy(Enemy *enemy);
    void put_player(Player *player);

    void test(void);

    void delete_enemy(int n);
    void delete_players_shot(int n);
    void PlayerShotsCollision(void);
    void delete_enemy_shot(int n);
//    void removeFromList(t_enemy *elem);
//    void removeFromList(t_shot *elem);

    bool checkCollision(void);
    void checkShotsCollision(void);

    void init();
    void Render(void);
    void Draw(void);
    void r_obj(void);
    //void Run(void);
};

#endif