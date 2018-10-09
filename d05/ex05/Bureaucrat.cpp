// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/08 13:39:01 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/08 13:39:02 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

Bureaucrat::Bureaucrat(void):   _name("NO_NAME"),
                                _grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name),
                                                            _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
    *this = obj;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & obj)
{
    _grade = obj._grade;
    return *this;
}

std::string const &Bureaucrat::getName(void) const
{
    return _name;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const & obj)
{
    o << ' ' << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}


int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::increment(void)
{
    _grade--;
}

void Bureaucrat::decrement(void)
{
    _grade++;
}

void Bureaucrat::signForm(Form &obj)
{
    try
    {
        obj.beSigned(_grade);
        std::cout << "\033[0;34m" << _name << "(Grade " << _grade << ") signs " << obj.getName()
        << "(s.grade " << obj.getSignGrade() << ", ex.grade " << obj.getExecuteGrade()
        << " ) targeted on " << obj.getTarget() << " (" << (obj.getSigned() ? "Signed" : "Unsigned") << ")."  << "\033[0m" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "\033[0;31m" << _name << "(Grade " << _grade << ") cannot sign " << obj.getName() << " targeted on "
                  << obj.getTarget() << " (" << (obj.getSigned() ? "Signed" : "Unsigned") << ") because " << e.what() << "\033[0m" << std::endl;
    }
}

void Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(_grade);
        std::cout << "\033[0;35m" << _name << "(Grade " << _grade << ") signs " << " executes " << form.getName()
                  << "(s.grade " << form.getSignGrade() << ", ex.grade " << form.getExecuteGrade()
                  << " ) targeted on " << form.getTarget() << " (" << (form.getSigned() ? "Signed" : "Unsigned") << ")."  << "\033[0m" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "\033[0;31m" << _name << "(Grade " << _grade << ") cannot execute " << form.getName() << " targeted on "
        << form.getTarget() << " (" << (form.getSigned() ? "Signed" : "Unsigned") << ") because " << e.what() << "\033[0m" << std::endl;
    }
}