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
#include "Intern.hpp"

int main()
{   
    srand(time(0));
    Intern intern;
    Form *scf = intern.makeForm("shrubbery creation", "sc target");
    Form *rrf = intern.makeForm("robotomy request", "rb target");
    Form *ppf = intern.makeForm("presidential pardon", "pb target");
    Form *invalid = intern.makeForm("lol", "target");
    
    invalid = NULL;
    Bureaucrat taras("Taras", 1);

    std::cout << taras << std::endl;
    std::cout << *scf << std::endl;
    taras.executeForm(*scf);
    taras.signForm(*scf);
    taras.executeForm(*scf);

    std::cout << *rrf << std::endl;
    taras.executeForm(*rrf);
    taras.signForm(*rrf);
    taras.executeForm(*rrf);

    std::cout << *ppf << std::endl;
    taras.executeForm(*ppf);
    taras.signForm(*ppf);
    taras.executeForm(*ppf);

    delete ppf;
    delete rrf;
    delete scf;
    return (0);
}