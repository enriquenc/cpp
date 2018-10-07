// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISquad.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 20:35:59 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 20:36:00 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISQUAD_HPP
#define ISQUAD_HPP

#include "ISpaceMarine.hpp"
#include <string>
#include <iostream>

class ISquad
{
public:
    virtual ~ISquad(){}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int unit) const = 0;
    virtual int push(ISpaceMarine* obj) = 0;
};

#endif