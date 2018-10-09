// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 13:36:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 13:36:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("robotomy request", 72, 45)
{
    _target = "NO_TARGET";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("robotomy request", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & obj)
{
    *this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
    _target = obj._target;
    return *this;
}

void RobotomyRequestForm::action(void) const
{
    if (rand()%2 == 0)
        std::cout << "Target has been robotomized successfully." << std::endl;
    else
        std::cout << "Failure. Target hasn't been robotomized." << std::endl; 
}

std::string const &RobotomyRequestForm::getTarget(void) const
{
    return _target;
}