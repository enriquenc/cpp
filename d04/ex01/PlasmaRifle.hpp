// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 18:36:28 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/06 18:36:29 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PlASMARIFLE_HPP
#define PlASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle(void);
    PlasmaRifle(std::string const & name, int apcost, int damage);
    ~PlasmaRifle(void);

    void attack(void) const;
};

#endif