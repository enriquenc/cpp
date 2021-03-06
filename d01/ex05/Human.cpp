// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 22:47:29 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 22:47:30 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

std::string Human::identify() const
{
    return this->br.identify();
}

const Brain &Human::getBrain() const
{
	return this->br;
}