// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 15:47:48 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 15:47:49 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << "ScavTrap. Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) :	ClapTrap::ClapTrap(name)
{
	_hit_points = 100;
	_max_hit_points = 100;
	_energy_points = 50;
	_max_energy_points = 50;
	_level = 1;
	_name = name;
	_melee_attack_damage = 20;
	_ranged_attack_damage = 15;
	_armor_damage_reduction = 3;
	std::cout << "ScavTrap. Constructor called. Name - " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap. Destructor called. Name - " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap & obj)
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


int ScavTrap::challengeNewcomer(std::string const & target)
{
	if (_energy_points >= 20)
	{
		random_damage = rand()%100 + 1;

		std::string attacks_arr[] = {"DIVISON BY ZERO", "BAD ECOLOGY", "IDIOTS", "CRIME", "CORRUPTION"};
		std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at " << attacks_arr[rand()%5] << " on " << random_damage << " damage" << std::endl;
		_level = _level + (float)(random_damage / 100);
		takeEnergy(20);
		take_info();
		return (random_damage);
	}
	std::cout << "No energy to use vaulthunter. " << _name << " going to be repaired." << std::endl;
	return 0;
}