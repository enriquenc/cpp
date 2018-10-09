// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/08 13:39:01 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/08 13:39:02 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Form.hpp"
#include <string>
#include <stdexcept>

Form::Form(void):   _name("NO_NAME"),
                    _sign_it_grade(0),
                    _execute_it_grade(0),
                    _signed(false) 
                    {}

Form::Form(const std::string name, int sign_it_grade, int execute_it_grade):  _name(name),
                                                                                _sign_it_grade(sign_it_grade),
                                                                                _execute_it_grade(execute_it_grade),
                                                                                _signed(false)
{
    if(sign_it_grade < 1 || execute_it_grade < 1)
        throw GradeTooHighException();
    else if(execute_it_grade > 150 || sign_it_grade > 150)
        throw GradeTooLowException();
}

Form::Form(Form const & obj):   _name("NO_NAME"),
                                _sign_it_grade(0),
                                _execute_it_grade(0)
{
    *this = obj;
}

Form::~Form(void){}

Form &Form::operator=(Form const & obj)
{
    _signed = obj._signed;                      
    return *this;
}

std::string const &Form::getName(void) const
{
    return _name;
}

std::ostream &operator<<(std::ostream &o, Form const & obj)
{
    o << obj.getName() << ", sign grade: " << obj.getSignGrade() << ", execute grade: " << obj.getExecuteGrade() << ", " << "signed: " <<  ((obj.getSigned()) ? "true" : "false")  << ".";
    return o;
}

int Form::getSignGrade(void) const
{
    return _sign_it_grade;
}

int Form::getExecuteGrade(void) const
{
    return _execute_it_grade;
}

int Form::getSigned(void) const
{
    return _signed;
}

void Form::beSigned(int grade)
{
    if (grade <= _sign_it_grade)
        _signed = true;
    else
        throw GradeTooLowException();
}

void Form::execute(int grade) const
{
    if (_signed)
    {
        if (grade <= _execute_it_grade)
            action();
        else
            throw GradeTooLowException();
    }
    else
        throw FormNotSignedException();
}