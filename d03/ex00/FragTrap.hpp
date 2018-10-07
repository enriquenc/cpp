// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 10:24:50 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 10:24:51 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>

class FragTrap 
{
private:
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
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &obj);
	~FragTrap(void);

	FragTrap & operator=(const FragTrap & obj);

	int rangedAttack(const std::string &target);
	int meleeAttack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void takeEnergy(unsigned int amount);
	
	bool death(void);
	void take_info(void);

	int vaulthunter_dot_exe(std::string const & target);


	const bool &getSleep(void) const;
	void setSleep(const bool &sleep);
	const std::string &getName(void) const;
};

#endif
