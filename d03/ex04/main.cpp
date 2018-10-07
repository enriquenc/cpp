// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 10:24:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/05 10:24:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <ctime>

int main()
{
	unsigned int damage;
	int random;
	ClapTrap John("John");
	SuperTrap Bill("Bill");
	srand(time(NULL));
	
	typedef int (ClapTrap::*Atck)(const std::string &targer);
	typedef int (ClapTrap::*SAtck)(const std::string &targer);
	Atck atacks[3] = {&ClapTrap::rangedAttack, &ClapTrap::meleeAttack};
	SAtck ninja_atacks[] = {&ClapTrap::rangedAttack, &ClapTrap::meleeAttack};
	damage = rand()%2;
	if (damage == 0)
		John.setSleep(true);
	else
		Bill.setSleep(true);
	Bill.take_info();
	while(!John.death() && !Bill.death())
	{
		if(!John.getSleep())
		{
			if(!(damage = (John.*(atacks[rand()%2]))(Bill.getName())))
				John.beRepaired(rand()%20 + 1);
			else
				Bill.takeDamage(damage);
		}
		else
			John.setSleep(false);
		if(Bill.death())
		{
			std::cout << John.getName() << " WIN!!!" << std::endl;
			system("say John win");
			break;
		}
		if(!Bill.getSleep())
		{
			random = rand()%4;
			if (random == 2)
				John.takeDamage(Bill.ninjaShoebox(John));
			else if (random == 3)
				John.takeDamage(Bill.vaulthunter_dot_exe(John.getName()));
			else if(!(damage = (Bill.*(ninja_atacks[random]))(John.getName())))
				Bill.beRepaired(rand()%20 + 1);
			else
				John.takeDamage(damage);
		}
		else
			Bill.setSleep(false);
		if(John.death())
		{
			std::cout << Bill.getName() << " WIN!!!" << std::endl;
			system("say Bill win");
			break;
		}
	}
	Bill.take_info();
	John.take_info();
	return 0;	
}


