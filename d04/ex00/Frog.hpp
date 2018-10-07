// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Frog.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:13:09 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 17:13:10 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef Frog_HPP
#define Frog_HPP

#include "Victim.hpp"


class Frog : public Victim
{
public:

    Frog(void);
    Frog(std::string const & name);
    ~Frog(void);

    void getPolymorphed(void) const;
};

#endif