// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 20:55:11 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 20:55:11 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
public:
	SuperTrap(void);
	SuperTrap(std::string name);
	SuperTrap(const  SuperTrap & obj);
	~SuperTrap(void);

	int rangedAttack(const std::string &target);
	int meleeAttack(const std::string &target);
	SuperTrap & operator = (const SuperTrap & obj);
};

#endif