// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 20:48:13 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 20:48:14 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Squad.hpp"

Squad::Squad(void)
{
    _squad = new t_squad;
    _squad->next = NULL;
    _squad->warrior = NULL;
    _squad->index = 0;
    _start = _squad;
    _end = _squad;
    _count = 0;
}

Squad::Squad(Squad const & obj)
{
    *this = obj;
}

Squad::Squad(t_squad *squad, t_squad *start, t_squad *end, int count)
{
    if (squad && start && end)
    {
        _start = start;
        _end = end;
        _squad = squad;
        _count = count;
    }
}

Squad::~Squad(void)
{
    _squad = _start;
    while (_squad->next)
    {
        delete _squad->warrior;
        delete _squad;
        _squad = _squad->next;
    }
    delete _squad;
    _squad = NULL;
    _start = NULL;
    _end = NULL;
}

Squad & Squad::operator=(Squad const & obj)
{
    _start = obj._start;
    _end = obj._end;
    _squad = obj._squad;
    _count = obj._count;
    return *this;
}

int Squad::getCount(void) const
{
    return _count;
}

ISpaceMarine* Squad::getUnit(int unit) const
{
    t_squad *l_squad;
    l_squad = _start;
    if (unit < 0 || unit >= _count)
        return NULL;
    while(l_squad)
    {
        std::cout << l_squad->index << std::endl << unit << std::endl;
        if(unit == l_squad->index)
            return l_squad->warrior;
        l_squad = l_squad->next;
    }
    return NULL;
}

bool Squad::already_in_the_squad(ISpaceMarine *obj)
{
    if (!obj)
        return false;
    _squad = _start;
    while (_squad)
    {
        if (_squad->warrior == obj)
            return true;
        _squad = _squad->next;
    }
    return false;
}

int Squad::push(ISpaceMarine* obj)
{
    if (obj)
    {
        if(!_squad->warrior)
        {
            _end->warrior = obj;
            _count++;
        }
        else
        {
            _end->next = new t_squad;
            _end->next->index = _end->index + 1;
            _end->next->warrior = obj;
            _end->next->next = NULL;
            _end->next->warrior = NULL;
            _end = _end->next;
            _count++;
        }
    }
    return _count;
}
