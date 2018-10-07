// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceMarine.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 20:43:05 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 20:43:06 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISPACEMARINE_HPP
#define ISPACEMARINE_HPP

#include <iostream>
#include <string>

class ISpaceMarine
{
public:
    virtual ~ISpaceMarine(){}
    virtual ISpaceMarine* clone() const = 0;
    virtual void battleCry() const = 0;
    virtual void rangedAttack() const = 0;
    virtual void meleeAttack() const = 0;
};

#endif