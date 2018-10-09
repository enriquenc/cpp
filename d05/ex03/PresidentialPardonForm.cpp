// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 13:36:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 13:36:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5)
{
    _target = "NO_TARGET";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & obj)
{
    *this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & obj)
{
    _target = obj._target;
    return *this;
}

void PresidentialPardonForm::action(void) const
{
   std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string const &PresidentialPardonForm::getTarget(void) const
{
    return _target;
}