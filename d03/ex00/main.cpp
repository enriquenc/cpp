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
#include <ctime>

int main()
{
	unsigned int damage;
	FragTrap John("John");
	FragTrap Bill("Bill");
	srand(time(NULL));
	
	typedef int (FragTrap::*Atck)(const std::string &targer);
	Atck atacks[3] = {&FragTrap::rangedAttack, &FragTrap::meleeAttack, &FragTrap::vaulthunter_dot_exe};
	damage = rand()%2;
	if (damage == 0)
		John.setSleep(true);
	else
		Bill.setSleep(true);
	while(!John.death() && !Bill.death())
	{
		if(!John.getSleep())
		{
			if(!(damage = (John.*(atacks[rand()%3]))(Bill.getName())))
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
			if(!(damage = (Bill.*(atacks[rand()%3]))(John.getName())))
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


