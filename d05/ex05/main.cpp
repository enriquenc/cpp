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
#include "CentralBureaucracy.hpp"

int main()
{
    CentralBureaucracy centralBureaucracy;

    centralBureaucracy.queueUp("home");
    centralBureaucracy.queueUp("hospital");
    centralBureaucracy.queueUp("hostel");
    centralBureaucracy.queueUp("school");
    centralBureaucracy.queueUp("university");

//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("John", 24)));
//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("Jake", 70)));
//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("Bill", 120)));
//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("Taras", 60)));
//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("Lol", 110)));
//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("kek", 50)));
//    centralBureaucracy.addBureaucrat(*(new Bureaucrat("fuck", 100)));
    centralBureaucracy.addBureaucrat(*(new Bureaucrat("shit", 40)));
    centralBureaucracy.addBureaucrat(*(new Bureaucrat("shit", 40)));

    centralBureaucracy.doBureaucracy();
    return (0);
}