// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 20:48:09 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 20:48:11 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

typedef struct s_squad
{
    ISpaceMarine *warrior;
    int index;
    struct s_squad *next;
}               t_squad;

class Squad : public ISquad
{
private:
    t_squad *_squad;
    t_squad *_start;
    t_squad *_end;
    int _count;
public:
    Squad(void);
    Squad(Squad const & obj);
    Squad(t_squad *squad, t_squad *start, t_squad *end, int count);
    ~Squad(void);

    Squad & operator=(Squad const & obj);

    int getCount(void) const;
    ISpaceMarine* getUnit(int unit) const;
    int push(ISpaceMarine* obj);
    
    bool already_in_the_squad(ISpaceMarine * obj);
    
};

#endif