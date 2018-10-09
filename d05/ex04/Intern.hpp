// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 16:18:45 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 16:18:45 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
private:
    
    Intern(Intern const & obj);
    
    Intern &operator=(Intern const & obj);
public:
    Intern(void);
    ~Intern(void);

    Form *makeForm(std::string const & name, std::string const & target);
};

#endif