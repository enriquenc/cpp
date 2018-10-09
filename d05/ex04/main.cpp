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
#include "OfficeBlock.hpp"

int main()
{
    srand(time(0));
    Intern idiotOne;
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 30);
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 71);
    OfficeBlock ob;
    ob.setIntern(&idiotOne);
    ob.setSigningBureaucrat(&bob);
    ob.setExecutingBureaucrat(&hermes);
    ob.doBureaucracy("robotomy request", "target");


    return (0);
}