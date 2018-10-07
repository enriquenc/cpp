// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:36:28 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:36:29 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PowerFist_HPP
#define PowerFist_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist(void);
    PowerFist(std::string const &name, int apcost, int damage);
    ~PowerFist(void);

    void attack(void) const;
};

#endif