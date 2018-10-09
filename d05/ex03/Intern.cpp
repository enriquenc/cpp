// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 16:18:48 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 16:18:49 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void){}

Intern::Intern(Intern const &obj){(void)obj;}

Intern &Intern::operator=(Intern const & obj){(void)obj; return *this;}

Intern::~Intern(void){}

Form *Intern::makeForm(std::string const & name, std::string const & target)
{
    if (name == "robotomy request")
    {
        std::cout << "Intern creates " << name << " with target " << target << '.' << std::endl;
        return (new RobotomyRequestForm(target));
    }
    else if (name == "shrubbery creation")
    {
        std::cout << "Intern creates " << name << " with target " << target << '.' << std::endl;
        return (new ShrubberyCreationForm(target));
    }

    else if (name == "presidential pardon")
    {
        std::cout << "Intern creates " << name << " with target " << target << '.' << std::endl;
        return  (new PresidentialPardonForm(target));
    }
    else
        std::cout << "Request form " << name << " unknown" << std::endl;
    return NULL;
}