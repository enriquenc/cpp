// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 20:58:42 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 20:58:42 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator(void);
    AssaultTerminator(AssaultTerminator const & obj);
    ~AssaultTerminator(void);

    ISpaceMarine* clone(void) const;
    void battleCry(void) const;
    void rangedAttack(void) const;
    void meleeAttack(void) const;
};

#endif