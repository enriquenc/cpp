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
        std::cout <<  "\033[0;32mIntern creates " << name << "(s.grade 72, ex.grade 45) targeted on " << target << " (Unsigned) \033[0m" << std::endl;
        return (new RobotomyRequestForm(target));
    }
    else if (name == "shrubbery creation")
    {
        std::cout <<  "\033[0;32mIntern creates " << name << "(s.grade 145, ex.grade  137) targeted on " << target << " (Unsigned) \033[0m" << std::endl;
        return (new ShrubberyCreationForm(target));
    }

    else if (name == "presidential pardon")
    {
        std::cout <<  "\033[0;32mIntern creates " << name << "(s.grade 25, ex.grade 5) targeted on " << target << " (Unsigned) \033[0m" << std::endl;
        return  (new PresidentialPardonForm(target));
    }
    else
        std::cout << "\033[1;31m Request form " << name << " unknown\\033[0m" << std::endl;
    return NULL;
}