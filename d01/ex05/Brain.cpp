// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:47:10 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 22:47:11 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"
#include <sstream>

std::string Brain::identify(void) const
{
    std::stringstream ss;
    ss << std::hex << this;
    return (ss.str());
}