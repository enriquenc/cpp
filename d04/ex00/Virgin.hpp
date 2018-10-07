// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Virgin.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 17:13:09 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 17:13:10 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef Virgin_HPP
#define Virgin_HPP

#include "Victim.hpp"


class Virgin : public Victim
{
public:

    Virgin(void);
    Virgin(std::string const & name);
    ~Virgin(void);

    void getPolymorphed(void) const;
};

#endif