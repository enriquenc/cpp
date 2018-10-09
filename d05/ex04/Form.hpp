// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/08 13:38:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/08 13:38:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

    const std::string _name;
    const int _sign_it_grade;
    const int _execute_it_grade;

    bool _signed;

public:

    Form(void);
    Form(const std::string name, int sign_it_grade, int execute_it_grade);
    Form(Form const & obj);
    virtual ~Form(void);

    Form &operator=(Form const &obj);

    std::string const &getName(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;
    int getSigned(void) const;

    void beSigned(int grade);

    virtual void action(void) const = 0;
    virtual std::string const &getTarget(void) const = 0;

    void execute(Bureaucrat const & executor) const;

    class GradeTooHighException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("grade is too high.");
        }
    };
    
    class GradeTooLowException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("grade is too low.");
        }
    };

    class FormNotSignedException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("form isn't signed.");
        }
    };
};

std::ostream &operator<<(std::ostream &o, Form const & obj);

#endif