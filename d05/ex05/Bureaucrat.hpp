// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/08 13:38:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/08 13:38:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BEREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:

    const std::string _name;
    int _grade;

public:

    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(Bureaucrat const & obj);
    ~Bureaucrat(void);

    Bureaucrat &operator=(Bureaucrat const &obj);

    std::string const &getName(void) const;
    int getGrade(void) const;
    void increment(void);
    void decrement(void);
    void signForm(Form &obj);
    
    void executeForm(Form const & form);

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade is too high.");
            }
    };

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade is too low.");
            }
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const & obj);

#endif