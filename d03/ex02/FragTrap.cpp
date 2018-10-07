// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 10:24:41 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 10:24:42 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << "FragTrap. Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) :	ClapTrap::ClapTrap(name)
{
	_hit_points = 100;
	_max_hit_points = 100;
	_energy_points = 100;
	_max_energy_points = 100;
	_level = 1;
	_name = name;
	_melee_attack_damage = 30;
	_ranged_attack_damage = 20;
	_armor_damage_reduction = 5;
	_sleep = false;

	std::cout << "FragTrap. Constructor called. Name - " << this->_name << '.' << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
	std::cout << "FragTrap. Copy constructor called." << std::endl;
	*this = obj;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap. Destructor called. Name - " << _name << '.' << std::endl;
}


int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_energy_points >= 25)
	{
		random_damage = rand()%50 + 1;

		std::string attacks_arr[] = {"kick", "hack", "fuck", "kiss", "hook"};
		std::cout << this->_name << " attacks " << target << " at " << attacks_arr[rand()%5] << " on " << random_damage << " damage" << std::endl;
		_level = _level + (float)(random_damage / 100);
		takeEnergy(25);
		take_info();
		return (random_damage);
	}
	std::cout << "No energy to use vaulthunter. " << _name << " going to be repaired." << std::endl;
	return 0;
}


FragTrap & FragTrap::operator=(const FragTrap & obj)
{
	_hit_points = obj._hit_points;
	_max_hit_points = obj._max_hit_points;
	_energy_points = obj._energy_points;
	_max_energy_points = obj._energy_points;
	_level = obj._level;
	_name = obj._name;
	_melee_attack_damage = obj._melee_attack_damage;
	_ranged_attack_damage = obj._ranged_attack_damage;
	_armor_damage_reduction = obj._armor_damage_reduction;
	
	_sleep = obj._sleep;
	return *this;
}