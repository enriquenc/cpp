// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:33 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:34 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:

    Peon(void);
    Peon(std::string const & name);
    ~Peon(void);
    
    void getPolymorphed(void) const;
};

#endif