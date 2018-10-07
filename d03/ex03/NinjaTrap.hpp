// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 18:10:14 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 18:10:15 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &obj);
	~NinjaTrap(void);

	NinjaTrap & operator = (const NinjaTrap & obj);

	int ninjaShoebox(NinjaTrap & obj);
	int ninjaShoebox(FragTrap & obj);
	int ninjaShoebox(ScavTrap & obj);
	int ninjaShoebox(ClapTrap & obj);
	
};

#endif