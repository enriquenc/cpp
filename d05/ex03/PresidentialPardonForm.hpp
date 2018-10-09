// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//  PresidentialPardonForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 13:37:02 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 13:37:03 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
    std::string _target;
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const & obj);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const & obj);

    void action(void) const;
    std::string const &getTarget(void) const;
};

#endif