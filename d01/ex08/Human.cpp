// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 18:55:46 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 18:55:47 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"
#include <iostream>


void Human::meleeAttack(std::string const & target)
{
	std::cout << "Melle Atack! Target: " << target << '.' << std::endl; 
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged Attack! Target: " << target << '.' << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating Shout! Target " << target << '.' << std::endl;
}

void    Human::action(std::string const & action_name, std::string const & target)
{
    std::string actionsStr[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

    typedef void (Human::*Actions)(std::string const & target);
    Actions actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

    for (int i = 2; i >= 0; i--)
    	if (actionsStr[i] == action_name)
    	{
        	(this->*(actions[i]))(target);
        	break;
    	}
}