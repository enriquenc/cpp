// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 17:04:14 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 17:04:15 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
private:

    Intern *_intern;
    Bureaucrat *_signing_bureaucrat;
    Bureaucrat *_executing_bureaucrat;

public:
    OfficeBlock(void);
    ~OfficeBlock(void);

    void setIntern(Intern *intern);
    void setSigningBureaucrat(Bureaucrat *signing_bureaucrat);
    void setExecutingBureaucrat(Bureaucrat *executing_bureaucrat);

    void doBureaucracy(std::string const & form_name, std::string const & target_name);

};

#endif