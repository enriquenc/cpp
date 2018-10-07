// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 14:55:02 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 14:55:03 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include "Victim.hpp"

class Sorcerer
{
private:

    std::string _name;
    std::string _title;

    Sorcerer(void);
public:

    Sorcerer(std::string const & name, std::string const & title);
    Sorcerer(Sorcerer const & obj);
    ~Sorcerer(void);

    void polymorph(Victim const & obj) const;

    const std::string & getName(void) const;
    const std::string & getTitle(void) const;

    Sorcerer & operator=(Sorcerer const & obj);

};

std::ostream & operator<<(std::ostream & o, Sorcerer & obj);

#endif