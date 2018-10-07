// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 17:09:30 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 17:09:31 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap. Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_hit_points(100),
								_max_hit_points(100),
								_energy_points(100),
								_max_energy_points(100),
								_level(1),
								_name(name),
								_melee_attack_damage(30),
								_ranged_attack_damage(20),
								_armor_damage_reduction(5),
								_sleep(false)
{
	std::cout << "ClapTrap. Constructor called. Name - " << this->_name << '.' << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap. Copy constructor called." << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap. Destructor called. Name - " << _name << '.' << std::endl;
}

void ClapTrap::take_info(void)
{
	std::cout << "\x1b[36;5;207m|| " << _name << "| HP: " << _hit_points << ", EP: " << _energy_points << ", LVL: " << _level << ".|\033[0m" << std::endl;
}

void ClapTrap::takeEnergy(unsigned int amount)
{
	_energy_points -= amount;
	if (_energy_points < 0)
		_energy_points = 0;
}

int ClapTrap::rangedAttack(const std::string &target)
{
	if (_energy_points >= 15)
	{
		std::cout << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack_damage << " points of damage !" << std::endl;
		_level = _level + (float)(_ranged_attack_damage / 100);
		takeEnergy(15);
		take_info();
		return _ranged_attack_damage;
	}
	std::cout << "No energy to use ranged attack. " << _name << " going to be repaired." << std::endl;
	return 0;
}

int ClapTrap::meleeAttack(const std::string &target)
{
	if (_energy_points >= 20)
	{
		std::cout << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack_damage << " points of damage !" << std::endl;
		_level = _level + (float)(_melee_attack_damage / 100);
		takeEnergy(20);
		take_info();
		return _melee_attack_damage;
	}
	std::cout << "No energy to use melee attack. " << _name << " going to be repaired." << std::endl;
	return 0;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _armor_damage_reduction)
	{
		_hit_points = _hit_points - (amount - _armor_damage_reduction);
		if (_hit_points < 0)
			_hit_points = 0;
		std::cout << _name << " take damage on " << amount << ", armor damage reduction: " << _armor_damage_reduction << '.' << std::endl;
	}
	else
	std::cout << _name << " absorb all damage." << std::endl;
	take_info();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > _max_hit_points)
		_hit_points = _max_energy_points;
	_energy_points += amount;
	if (_energy_points > _max_energy_points)
		_energy_points = _max_energy_points;
	std::cout << _name << " was repaired on " << amount << '.' << std::endl;
	_sleep = true;
	take_info();
}

bool ClapTrap::death(void)
{
	if (_hit_points == 0)
	{
		std::cout << _name << " died." << std::endl;
		return true; 
	}
	return false;
}


const bool &ClapTrap::getSleep(void) const
{
	return _sleep;
}

void ClapTrap::setSleep(const bool &sleep)
{
	_sleep = sleep;
}

const std::string &ClapTrap::getName(void) const
{
	return _name;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & obj)
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