// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 20:58:42 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 20:58:42 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
    TacticalMarine(void);
    TacticalMarine(TacticalMarine const & obj);
    ~TacticalMarine(void);

    ISpaceMarine* clone(void) const;
    void battleCry(void) const;
    void rangedAttack(void) const;
    void meleeAttack(void) const;
};

#endif
