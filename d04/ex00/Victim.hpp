// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:25 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:26 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
protected:

    std::string _name;

    
public:

    Victim(void);
    Victim(std::string const & name);
    Victim(Victim const & obj);
    ~Victim(void);

    virtual void getPolymorphed(void) const;

    const std::string &getName(void) const;

    Victim & operator=(Victim const & obj);
};

std::ostream & operator<<(std::ostream & o, Victim & obj);

#endif