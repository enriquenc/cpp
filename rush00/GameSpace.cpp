// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameSpace.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 01:22:25 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/07 01:22:26 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>
#include "GameSpace.hpp"

GameSpace::GameSpace(void) :    _player_shots(NULL),
                                _enemy_shots(NULL),
                                _enemies(NULL),
                                _count_player_shots(0),
                                _count_enemy_shots(0),
                                _count_enemies(0),
                                _player(NULL),
                                _player_shots_start(NULL),
                                _enemy_shots_start(NULL),
                                _enemies_start(NULL),
                                _win(NULL)
{
    //std::cout << "Game start!" << std::endl;
}

GameSpace::GameSpace(GameSpace const & obj)
{
    *this = obj;
}

GameSpace::~GameSpace(void)
{
    if (_player_shots)
        _player_shots = _player_shots_start;
    while(_player_shots)
    {
        delete _player_shots;
        _player_shots = _player_shots->next;
    }
    if (_enemy_shots)
        _enemy_shots = _enemy_shots_start;
    while(_enemy_shots)
    {
        delete _enemy_shots;
        _enemy_shots = _enemy_shots->next;
    }
    if (_enemies)
        _enemies = _enemies_start;
    while(_enemies)
    {
        delete _enemies->enemy;
        delete _enemies;
        _enemies = _enemies->next;
    }
    if (_player)
        delete _player;
}

GameSpace & GameSpace::operator=(GameSpace const & obj)
{
    _player_shots = obj._player_shots;
    _enemy_shots = obj._enemy_shots;
    _enemies = obj._enemies;
    _player = obj._player; 
    return *this;
}

void GameSpace::put_player_shot(int x, int y)
{
    if (!_player_shots)
    {
        _player_shots = new t_shot;
        _player_shots_start = _player_shots;
        _player_shots->current_x = x;
        _player_shots->current_y = y;
        _player_shots->symbol = '-';
        _player_shots->next = NULL;
        _player_shots->next = NULL;
        _count_player_shots++;
    }
    else
    {
        _player_shots = _player_shots_start;
        while (_player_shots->next)
            _player_shots = _player_shots->next;
        _player_shots->next = new t_shot;
        _player_shots->next->current_x = x;
        _player_shots->next->current_y = y;
        _player_shots->next->symbol = '-';
        _player_shots->next->next = NULL;
        //_player_shots->next->prev = _player_shots;
        _player_shots = _player_shots->next;
        _count_player_shots++;
    }
    //std::cout << "Put player shot " << x << ' ' << y << ' ' << _count_player_shots << std::endl;
}

void GameSpace::put_enemy_shot(int x, int y)
{
    if (!_enemy_shots)
    {
        _enemy_shots = new t_shot;
        _enemy_shots_start = _enemy_shots;
        _enemy_shots->current_x = x;
        _enemy_shots->current_y = y;
        _enemy_shots->symbol = 'o';
        //_enemy_shots->prev = NULL;
        _enemy_shots->next = NULL;
        _count_enemy_shots++;
    }
    else
    {
        _enemy_shots = _enemy_shots_start;
        while (_enemy_shots->next)
            _enemy_shots = _enemy_shots->next;
        _enemy_shots->next = new t_shot;
        _enemy_shots->next->current_x = x;
        _enemy_shots->next->current_y = y;
        _enemy_shots->next->symbol = 'o';
        _enemy_shots->next->next = NULL;
        //_enemy_shots->next->prev = _enemy_shots;
        _enemy_shots = _enemy_shots->next;
        _count_enemy_shots++;
    }
    //std::cout << "Put enemy shot " << x << ' ' << y << ' ' << _count_enemy_shots << std::endl;
}

void GameSpace::put_enemy(Enemy *enemy)
{
    if (enemy)
    {
        if(!_enemies)
        {
            _enemies = new t_enemy;
            _enemies_start = _enemies;
            _enemies->enemy = enemy;
            _enemies->next = NULL;
            //_enemies->prev = NULL;
            _count_enemies++;
        }
        else
        {
            _enemies = _enemies_start;
            while (_enemies->next)
                _enemies = _enemies->next;
            _enemies->next = new t_enemy;
            //_enemies->next->prev = _enemies;
            _enemies->next->enemy = enemy;
            _enemies->next->next = NULL;
            _enemies = _enemies->next;
            _count_enemies++;
        }

        //std::cout << "Enemy added " << _enemies->enemy->getStartX()<< ' ' << _enemies->enemy->getStartY() << ' ' << _count_enemies << std::endl;
    }
}

void GameSpace::put_player(Player *player)
{
    if (!_player)
        _player = player;
    else
    {
        delete _player;
        _player = player;
    }
    //std::cout << "Player added " << _player->getStartX() << ' ' << _player->getStartY() <<  std::endl;
}

bool GameSpace::checkCollision(void)
{
    if (_enemies)
        _enemies = _enemies_start;
    while (_enemies)
    {
        for(int i = 0; i < PLAYER_SIZE; i++)
        {
            for(int j = 0; j < PLAYER_SIZE; j++)
            {
                if (_player->getStartX() + i == _enemies->enemy->getStartX() && _player->getStartY() + j == _enemies->enemy->getStartY())
                {
                    _player->setHp(_player->getHp() - 1);
                    _enemies = _enemies_start;
                    return true;
                }
            }
        }
        _enemies = _enemies->next;
    }
    _enemies = _enemies_start;
    return false;
}


//void GameSpace::removeFromList(t_shot *elem)
//{
//    if (_player_shots && _player_shots_start)
//    {
//        t_shot *temp = NULL;
//        t_shot *list = _player_shots;
//        t_shot *start = _player_shots_start;
//        while (list)
//        {
//            if (list == elem)
//            {
//                if (temp && list->next)
//                {
//                    temp->next = list->next;
//                    delete list;
//                }
//                else if (temp && !list->next) {
//                    temp->next = NULL;
//                    delete list;
//                }
//                else if (!temp && list->next)
//                {
//                    start = list->next;
//                    delete list;
//                }
//                else
//                {
//                    delete list;
//                    list = NULL;
//                    start = NULL;
//                }
//            }
//            temp = list;
//            list = list->next;
//        }
//    }
//}
//
//void GameSpace::removeFromList(t_enemy *elem)
//{
//    if (_enemies && _enemies_start)
//    {
//        t_enemy *temp = NULL;
//        t_enemy *list = _enemies;
//        t_enemy *start = _enemies_start;
//        while (list)
//        {
//            if (list == elem)
//            {
//                if (temp && list->next)
//                {
//                    temp->next = list->next;
//                    delete list;
//                }
//                else if (temp && !list->next) {
//                    temp->next = NULL;
//                    delete list;
//                }
//                else if (!temp && list->next)
//                {
//                    start = list->next;
//                    delete list;
//                }
//                else
//                {
//                    delete list;
//                    list = NULL;
//                    start = NULL;
//                }
//            }
//            temp = list;
//            list = list->next;
//        }
//    }
//}
//
//
//
//

void GameSpace::delete_enemy(int n)
{
    if (n < 0 || n > _count_enemies || n == 0)
        return ;
    if (_count_enemies == 1)
    {
        delete _enemies->enemy;
        delete _enemies;
        _count_enemies--;
        _enemies = NULL;
        _enemies_start = NULL;
        return ;
    }
    t_enemy *tmp = _enemies_start;
    t_enemy *next;
    for (int i = 0; i < n - 1; i++)
        tmp = tmp->next;
    next = tmp->next->next;
    delete tmp->next->enemy;
    delete tmp->next;
    tmp->next = next;
    _count_enemies--;
}

void GameSpace::delete_players_shot(int n)
{
    //std::cout << n << ' ' << _count_player_shots << std::endl;
    if (n < 0 || n > _count_player_shots || n == 0)
        return ;
    if (_count_player_shots == 1)
    {
        _player_shots = _player_shots_start;
        _enemy_shots->next = NULL;
        delete _player_shots;
        _count_player_shots--;
        _player_shots = NULL;
        _player_shots_start = NULL;
        return ;
    }
    t_shot *tmp = _player_shots_start;
    t_shot *next;
    for (int i = 0; i < n - 1; i++)
        tmp = tmp->next;
    next = tmp->next->next;
    delete tmp->next;
    tmp->next = next;
    _count_player_shots--;
}

void GameSpace::delete_enemy_shot(int n)
{
    //std::cout << n << ' ' << _count_enemy_shots << std::endl;
    if (n < 0 || n > _count_enemy_shots || n == 0)
        return ;
    if (_count_enemy_shots == 1)
    {
        delete _enemy_shots;
        _count_enemy_shots--;
        _enemy_shots = NULL;
        _enemy_shots_start = NULL;
        return ;
    }
    t_shot *tmp = _enemy_shots_start;
    t_shot *next;
    for (int i = 0; i < n - 1; i++)
        tmp = tmp->next;
    next = tmp->next->next;
    delete tmp->next;
    tmp->next = next;
    _count_enemy_shots--;
}

void GameSpace::checkShotsCollision(void)
{
    t_shot *shot = NULL;
    t_enemy *enemy = NULL;
    int i = 0;
    if (_player_shots_start)
        shot = _player_shots_start;
    while (shot)
    {
        if (_enemies_start)
            enemy = _enemies_start;
        i = 0;
        while (enemy) {
            
            if (enemy->enemy->getStartX() <= shot->current_x &&
                shot->current_x < (enemy->enemy->getStartX() + ENEMY_SIZE)
                && enemy->enemy->getStartY() <= shot->current_y &&
                shot->current_y < (enemy->enemy->getStartY() + ENEMY_SIZE)) 
            {
//                removeFromList(shot);
//                removeFromList(enemy);
                    _player->setScore(_player->getScore() + 1);
                    delete_enemy(i);
                    delete_players_shot(i);
                    break;
                //exit(0);
                //std::cout << i << ' ' << "remove!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            }
            enemy = enemy->next;
            i++;
        }
        if (_player_shots_start)
            shot = shot->next;
        else
            return;
    }
}

void GameSpace::PlayerShotsCollision(void)
{
    t_shot *shot = NULL;
    int i = 0;
    if (_enemy_shots)
        shot = _enemy_shots;
    while (shot)
    {
        
        if (_player->getStartX() <= shot->current_x && shot->current_x < (_player->getStartX() + PLAYER_SIZE)
            &&  _player->getStartY() <= shot->current_y && shot->current_y < (_player->getStartY() + PLAYER_SIZE))
        {
            delete_enemy_shot(i);
            _player->takeDamage(1);
        }
        if (_enemy_shots_start)
            shot = shot->next;
        else
            return;
            

    }
}

// void GameSpace::test()
// {
//     if (_player_shots)
//         _player_shots = _player_shots_start;
//     if (_enemy_shots)
//         _enemy_shots = _enemy_shots_start;
//     if (_enemies)
//         _enemies = _enemies_start;

//     while (_player_shots)
//     {
//         std::cout << "I am player shot at X: " << _player_shots->current_x << " Y: " << _player_shots->current_y << std::endl;
//         _player_shots = _player_shots->next;
//     }

//     while (_enemy_shots)
//     {
//         std::cout << "I am enemy shot at X: " << _enemy_shots->current_x << " Y: " << _enemy_shots->current_y << std::endl;
//         _enemy_shots = _enemy_shots->next;
//     }

//     while (_enemies)
//     {
//         std::cout << "I am Enemy at X: " << _enemies->enemy->getStartX() << " Y: " << _enemies->enemy->getStartY() << std::endl;
//         _enemies = _enemies->next;
//     }

//     _player_shots = _player_shots_start;
//     _enemy_shots = _enemy_shots_start;
//     _enemies = _enemies_start;
// }

void GameSpace::init(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);


    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
}

void GameSpace::Draw(void)
{
    t_shot *plr_p = NULL;
    t_enemy *enemy = NULL;
    //t_shot *enem_p;

    if (_player_shots)
        plr_p = _player_shots_start;
    if (_enemies)
        enemy = _enemies_start;
    // if (_enemy_shots)
    //      enem_p = _enemy_shots_start;


    while (plr_p)
    {
        mvwprintw(_win, plr_p->current_y, plr_p->current_x, "*");
        plr_p->current_x++;
        plr_p = plr_p->next;
    }



    while  (enemy)
    {
    //    char **r1 = new     {"\\-/", "***", "|-|"};
    //    char **r2 = new     {"| |", "* *",    " <|"};
    //    char **r3 = new     {"/_\\","***",    "|-|"};

    //    int r = rand()%3;

        mvwprintw(_win, enemy->enemy->getStartY(), enemy->enemy->getStartX(), "|-|");
        mvwprintw(_win, enemy->enemy->getStartY() + 1, enemy->enemy->getStartX(), "<|");
        mvwprintw(_win, enemy->enemy->getStartY() + 2, enemy->enemy->getStartX(), "|-|");
        enemy->enemy->setStartX(enemy->enemy->getStartX() - 1);
        enemy = enemy->next;
        //exit(0);
    }

//    while (enem_p)
//    {
//        mvwprintw(_win, enem_p->current_x, enem_p->current_y, "-");
//        enem_p->current_x--;
//        enem_p = enem_p->next;
//    }
}

void GameSpace::r_obj(void)
{

//    int r_y = rand()%10;

//    if (r_y == 2000)
//        put_enemy(new Enemy(80, 15));

}

void GameSpace::Render(void)
{
    int c = 0;
    init();
	refresh();
    nodelay(stdscr, TRUE);
    
    _win = newwin(HEIGHT, WIDTH, 0, 0);
    put_player(new Player(2, HEIGHT / 2));

	box(_win, 0, 0);
    //put_enemy(new Enemy(80, HEIGHT / 2));
    put_enemy(new Enemy(80, 5));
    
    //put_enemy(new Enemy(80, 20));
    int d = 0;
    int t = 20;
    std::string total = "";
    std::string hp = "";
    while(c != 27)
    {
        
        delwin(_win);
        
        _win = newwin(HEIGHT, WIDTH, 0, 0);

      
        mvwprintw(_win, _player->getStartY(), _player->getStartX(), "-\\|");
        mvwprintw(_win, _player->getStartY() + 1, _player->getStartX(), ">->");
        mvwprintw(_win, _player->getStartY() + 2, _player->getStartX(), "-//");
        //r_obj();

       total = std::to_string(_player->getScore());
       hp  = std::to_string(_player->getHp());
       mvwprintw(_win, 2, 3, "Score: ");
        mvwprintw(_win, 2, 10, total.c_str());
        mvwprintw(_win,2, 12, ", HP: ");
        mvwprintw(_win,2, 18,  hp.c_str());

        
        Draw();
        checkCollision();
        if (!_player->getHp())
            break;
        checkShotsCollision();
        //PlayerShotsCollision();
        
        box(_win, 0, 0);
        
        refresh();
        wrefresh(_win);
        c = getch();
        
        d++;
        if (d % 200 == 0 && (t - 3) > 0)
            t -= 3;
        if (d % t == 0)
        {
            put_enemy(new Enemy(80, rand()%19 + 3));
            _enemies->enemy->attack(*this);
        }
        switch (c) 
        {
		    case KEY_UP:
		    	if (_player->getStartY() - 1 > 0) 
		    		_player->setStartY(_player->getStartY() - 1);
		    	break;
		    case KEY_DOWN:
		    	if (_player->getStartY() + 1 < HEIGHT - PLAYER_SIZE) 
		    		_player->setStartY(_player->getStartY() + 1);
		    	break;
		    case KEY_LEFT:
		    	if (_player->getStartX() - 1 > 0)
		    		_player->setStartX(_player->getStartX() - 1);
		    	break;
		    case KEY_RIGHT:
		    	if (_player->getStartX() + 1 < WIDTH - PLAYER_SIZE)
		    		_player->setStartX(_player->getStartX() + 1);
                break;
            case 32:
                    _player->attack(*this);
		    	break;
        }
        usleep(40000);
    }
    getch();
    endwin();
}