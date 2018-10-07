// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 18:10:10 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 18:10:11 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << "NinjaTrap. Default constructor called." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) :	ClapTrap::ClapTrap(name)
{
	_hit_points = 60;
	_max_hit_points = 60;
	_energy_points = 120;
	_max_energy_points = 120;
	_level = 1;
	_name = name;
	_melee_attack_damage = 60;
	_ranged_attack_damage = 5;
	_armor_damage_reduction = 0;
	_sleep = false;

	std::cout << "NinjaTrap. Constructor called. Name - " << this->_name << '.' << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &obj)
{
	std::cout << "NinjaTrap. Copy constructor called." << std::endl;
	*this = obj;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap. Destructor called. Name - " << _name << '.' << std::endl;
}


int NinjaTrap::ninjaShoebox(ClapTrap & obj)
{
	if (_energy_points >= 30)
	{
		random_damage = rand()%100 + 30;
		obj.takeDamage(random_damage);
		obj.setSleep(true);
		std::cout << _name << " put to sleep " << obj.getName() << '.' << std::endl;
		return random_damage;
	}
	std::cout << "No energy to use ninja shoebox. " << _name << " going to be repaired." << std::endl;	
	return 0;
}

int NinjaTrap::ninjaShoebox(NinjaTrap & obj)
{
	if (_energy_points >= 30)
	{
		random_damage = rand()%100 + 30;
		obj.takeDamage(random_damage);
		obj.setSleep(true);
		std::cout << _name << " put to sleep " << obj.getName() << '.' << std::endl;
		return random_damage;
	}
	std::cout << "No energy to use ninja shoebox. " << _name << " going to be repaired." << std::endl;
	return 0;
}

int NinjaTrap::ninjaShoebox(FragTrap & obj)
{
	if (_energy_points >= 30)
	{
		random_damage = rand()%100 + 30;
		obj.takeDamage(random_damage);
		obj.setSleep(true);
		std::cout << _name << " put to sleep " << obj.getName() << '.' << std::endl;
		return random_damage;
	}
	std::cout << "No energy to use ninja shoebox. " << _name << " going to be repaired." << std::endl;
	return 0;
}

int NinjaTrap::ninjaShoebox(ScavTrap & obj)
{
	if (_energy_points >= 30)
	{
		random_damage = rand()%100 + 30;
		obj.takeDamage(random_damage);
		obj.setSleep(true);
		std::cout << _name << " put to sleep " << obj.getName() << '.' << std::endl;
		return random_damage;
	}
	std::cout << "No energy to use ninja shoebox. " << _name << " going to be repaired." << std::endl;
	return 0;
}



NinjaTrap & NinjaTrap::operator=(const NinjaTrap & obj)
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