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
    Form(const std::string name, int _sign_it_grade, int _execute_it_grade);
    Form(Form const & obj);
    ~Form(void);

    Form &operator=(Form const &obj);

    std::string const &getName(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;
    int getSigned(void) const;

    void beSigned(int grade);

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

std::ostream &operator<<(std::ostream &o, Form const & obj);

#endif