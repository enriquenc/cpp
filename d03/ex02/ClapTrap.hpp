// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 10:24:50 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 10:24:51 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <string>
#include <iostream>

class ClapTrap 
{
protected:
	int	_hit_points;
	int	_max_hit_points;
	int	_energy_points;
	int	_max_energy_points;
	float	_level;
	std::string	_name;
	float	_melee_attack_damage;
	float	_ranged_attack_damage;
	unsigned int	_armor_damage_reduction;

	float random_damage;
	bool _sleep;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &obj);
	~ClapTrap(void);

	ClapTrap & operator=(const ClapTrap & obj);

	int rangedAttack(const std::string &target);
	int meleeAttack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void takeEnergy(unsigned int amount);
	
	bool death(void);
	void take_info(void);


	const bool &getSleep(void) const;
	void setSleep(const bool &sleep);
	const std::string &getName(void) const;
};

#endif