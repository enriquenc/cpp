
// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 16:59:27 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 16:59:28 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

int main()
{
    Pony ivan("Ivan", 120, 15, 5);
    Pony* petro = new Pony("Petro", 80, 24, 10);

    ivan.live();
    petro->live();
    ivan.eat(12);
    petro->eat(16);
    ivan.have_some_fun();
    petro->have_some_fun();

    delete petro;
    
    return 0;
}