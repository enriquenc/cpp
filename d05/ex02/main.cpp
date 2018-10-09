// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/08 13:39:09 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/08 13:39:10 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{   
    srand(time(0));
    ShrubberyCreationForm scf("ShrubberyCreationForm target");
    RobotomyRequestForm rrf("RobotomyRequestForm target");
    PresidentialPardonForm ppf("PresidentialPardonFormtarget");
    Bureaucrat taras("Taras", 1);

    std::cout << taras << std::endl;
    std::cout << scf << std::endl;
    taras.executeForm(scf);
    taras.signForm(scf);
    taras.executeForm(scf);

    std::cout << rrf << std::endl;
    taras.executeForm(rrf);
    taras.signForm(rrf);
    taras.executeForm(rrf);

    std::cout << ppf << std::endl;
    taras.executeForm(ppf);
    taras.signForm(ppf);
    taras.executeForm(ppf);

    Bureaucrat vasilii("Vasilii", 140);
    ShrubberyCreationForm scf1("scf1 target");
    std::cout << vasilii << std::endl;
    std::cout << scf1 << std::endl;
    vasilii.signForm(scf1);
    std::cout << scf1 << std::endl;
    vasilii.executeForm(scf1);
    vasilii.signForm(rrf);

    ShrubberyCreationForm scf3("scf3 target");
    vasilii.executeForm(scf3);
 return (0);
}