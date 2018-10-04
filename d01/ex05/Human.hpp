// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:47:35 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 22:47:36 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"
#include <string>

class Human
{
public:
    const Brain br;
    std::string identify() const;
    const Brain &getBrain(void) const;
};

#endif