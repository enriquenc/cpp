// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 17:04:10 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 17:04:11 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void):_intern(NULL),
                                _signing_bureaucrat(NULL),
                                _executing_bureaucrat(NULL) {}

OfficeBlock::~OfficeBlock() {}

void OfficeBlock::setIntern(Intern *intern)
{
    _intern = intern;
}

void OfficeBlock::setSigningBureaucrat(Bureaucrat *signing_bureaucrat)
{
    _signing_bureaucrat = signing_bureaucrat;
}

void OfficeBlock::setExecutingBureaucrat(Bureaucrat *executing_bureaucrat)
{
    _executing_bureaucrat = executing_bureaucrat;
}

void OfficeBlock::doBureaucracy(std::string const &form_name, std::string const &target_name)
{
    Form *form = _intern->makeForm(form_name, target_name);
    _signing_bureaucrat->signForm(*form);
    _executing_bureaucrat->executeForm(*form);
}