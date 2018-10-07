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

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap. Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) :	_hit_points(100),
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

void FragTrap::take_info(void)
{
	std::cout << "\x1b[36;5;207m||FR4G-TP " << _name << "| HP: " << _hit_points << ", EP: " << _energy_points << ", LVL: " << _level << ".|\033[0m" << std::endl;
}

void FragTrap::takeEnergy(unsigned int amount)
{
	_energy_points -= amount;
	if (_energy_points < 0)
		_energy_points = 0;
}

int FragTrap::rangedAttack(const std::string &target)
{
	if (_energy_points >= 15)
	{
		std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_ranged_attack_damage << " points of damage !" << std::endl;
		_level = _level + (float)(_ranged_attack_damage / 100);
		takeEnergy(15);
		take_info();
		return _ranged_attack_damage;
	}
	std::cout << "No energy to use ranged attack. " << _name << " going to be repaired." << std::endl;
	return 0;
}

int FragTrap::meleeAttack(const std::string &target)
{
	if (_energy_points >= 20)
	{
		std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_melee_attack_damage << " points of damage !" << std::endl;
		_level = _level + (float)(_melee_attack_damage / 100);
		takeEnergy(20);
		take_info();
		return _melee_attack_damage;
	}
	std::cout << "No energy to use melee attack. " << _name << " going to be repaired." << std::endl;
	return 0;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount > _armor_damage_reduction)
	{
		_hit_points = _hit_points - (amount - _armor_damage_reduction);
		if (_hit_points < 0)
			_hit_points = 0;
		std::cout << "FR4G-TP " << _name << " take damage on " << amount << ", armor damage reduction: " << _armor_damage_reduction << '.' << std::endl;
	}
	else
		std::cout << "FR4G-TP " << _name << " ";
	take_info();
}

void FragTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > _max_hit_points)
		_hit_points = _max_energy_points;
	_energy_points += amount;
	if (_energy_points > _max_energy_points)
		_energy_points = _max_energy_points;
	std::cout << "FR4G-TP " << _name << " was repaired on " << amount << '.' << std::endl;
	_sleep = true;
	take_info();
}

bool FragTrap::death(void)
{
	if (_hit_points == 0)
	{
		std::cout << "FR4G-TP " << _name << " died." << std::endl;
		return true; 
	}
	return false;
}

int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_energy_points >= 25)
	{
		random_damage = rand()%50 + 1;

		std::string attacks_arr[] = {"kick", "hack", "fuck", "kiss", "hook"};
		std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at " << attacks_arr[rand()%5] << " on " << random_damage << " damage" << std::endl;
		_level = _level + (float)(random_damage / 100);
		takeEnergy(25);
		take_info();
		return (random_damage);
	}
	std::cout << "No energy to use vaulthunter. " << _name << " going to be repaired." << std::endl;
	return 0;
}


const bool &FragTrap::getSleep(void) const
{
	return _sleep;
}

void FragTrap::setSleep(const bool &sleep)
{
	_sleep = sleep;
}

const std::string &FragTrap::getName(void) const
{
	return _name;
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