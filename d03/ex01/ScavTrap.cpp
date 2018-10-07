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


ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap. Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) :	_hit_points(100),
										_max_hit_points(100),
										_energy_points(50),
										_max_energy_points(50),
										_level(1),
										_name(name),
										_melee_attack_damage(20),
										_ranged_attack_damage(15),
										_armor_damage_reduction(3)
{
	std::cout << "ScavTrap. Constructor called. Name - " << name << std::endl;
	_name = name;
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

const bool &ScavTrap::getSleep(void) const
{
	return _sleep;
}

void ScavTrap::setSleep(const bool &sleep)
{
	_sleep = sleep;
}

const std::string &ScavTrap::getName(void) const
{
	return _name;
}

void ScavTrap::take_info(void)
{
	std::cout << "\x1b[34;5;207m||[ScavTrap] " << _name << "| HP: " << _hit_points << ", EP: " << _energy_points << ", LVL: " << _level << ".|\033[0m" << std::endl;
}

void ScavTrap::takeEnergy(unsigned int amount)
{
	_energy_points -= amount;
	if (_energy_points < 0)
		_energy_points = 0;
}

int ScavTrap::rangedAttack(const std::string &target)
{
	if (_energy_points >= 15)
	{
		std::cout << "[ScavTrap] " << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack_damage << " points of damage !" << std::endl;
		_level = _level + (float)(_ranged_attack_damage / 100);
		takeEnergy(10);
		take_info();
		return _ranged_attack_damage;
	}
	std::cout << "No energy to use ranged attack. " << _name << " going to be repaired." << std::endl;
	return 0;
}

int ScavTrap::meleeAttack(const std::string &target)
{
	if (_energy_points >= 20)
	{
		std::cout << "[ScavTrap] " << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack_damage << " points of damage !" << std::endl;
		_level = _level + (float)(_melee_attack_damage / 100);
		takeEnergy(15);
		take_info();
		return _melee_attack_damage;
	}
	std::cout << "No energy to use melee attack. " << _name << " going to be repaired." << std::endl;
	return 0;
}


void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > _armor_damage_reduction)
	{
		_hit_points = _hit_points - (amount - _armor_damage_reduction);
		if (_hit_points < 0)
			_hit_points = 0;
		std::cout << "[ScavTrap] " << _name << " take damage on " << amount << ", armor damage reduction: " << _armor_damage_reduction << '.' << std::endl;
	}
	else
		std::cout << "[ScavTrap] " << _name << " ";
	take_info();
}

void ScavTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > _max_hit_points)
		_hit_points = _max_energy_points;
	_energy_points += amount;
	if (_energy_points > _max_energy_points)
		_energy_points = _max_energy_points;
	std::cout << "[ScavTrap] " << _name << " was repaired on " << amount << '.' << std::endl;
	_sleep = true;
	take_info();
}

bool ScavTrap::death(void)
{
	if (_hit_points == 0)
	{
		std::cout << "[ScavTrap] " << _name << " died." << std::endl;
		return true; 
	}
	return false;
}

int ScavTrap::challengeNewcomer(std::string const & target)
{
	if (_energy_points >= 35)
	{
		random_damage = rand()%100 + 1;

		std::string attacks_arr[] = {"DIVISON BY ZERO", "BAD ECOLOGY", "IDIOTS", "CRIME", "CORRUPTION"};
		std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at " << attacks_arr[rand()%5] << " on " << random_damage << " damage" << std::endl;
		_level = _level + (float)(random_damage / 100);
		takeEnergy(35);
		take_info();
		return (random_damage);
	}
	std::cout << "No energy to use vaulthunter. " << _name << " going to be repaired." << std::endl;
	return 0;
}